#include<iostream>
#include<vector>
#include<cstdlib>   // for rand()
#include<ctime>     // for time()

using namespace std;

// swap function
void swap(vector<int>& nums,int i,int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// Partition function
int partition(vector<int>& nums,int left,int right)
{
    int i = left + 1;
    int j = right;

    // continue untill 2 pointers cross
    while(i <= j)
    {
        while(i <= j && nums[i] <= nums[left])
            i++;
        while(i <= j && nums[j] > nums[left])
            j--;
        // if valid indices found swap them
        if(i < j)
        {
            swap(nums,i,j);
            i++;
            j--;
        }
    }
    i--;    // place pivot in correct sorted position
    swap(nums,left,i);
    return i;  // pivot index
}

// Randomized Quick Sort
void RandomizedQuickSort(vector<int>& nums,int left,int right)
{
    if(left < right)
    {
        // select a random index bectween [left,right] as pivot element
        int pivot = left + rand() % (right - left + 1); 
        swap(nums,pivot,left);

        // get pivot index
        int k = partition(nums,left,right);
    
        RandomizedQuickSort(nums,left,k-1);
        RandomizedQuickSort(nums,k+1,right);
    }
}

void print(vector<int>& nums)
{
    for(int num : nums)
        cout << num << " ";
    cout << endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));  // seed random generator with current time
  
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
  
    RandomizedQuickSort(nums,0,n-1);
    print(nums);
    return 0;
}
