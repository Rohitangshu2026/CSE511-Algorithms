#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

void swap(vector<int>& nums,int i,int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
int partition(vector<int>& nums,int left,int right)
{
    int i = left + 1;
    int j = right;

    while(i <= j)
    {
        while(i <= j && nums[i] <= nums[left])
            i++;
        while(i <= j && nums[j] > nums[left])
            j--;
        if(i < j)
        {
            swap(nums,i,j);
            i++;
            j--;
        }   
    }
    swap(nums,left,i-1);
    return i-1;
}

int findElementWithRank(vector<int>& nums, int left,int right,int rank)
{
    int pivot = left + rand() % (right - left + 1);
    swap(nums,left,pivot);
    int partitionIndex = partition(nums,left,right);
    if(rank == right - partitionIndex + 1)
        return partitionIndex;
    else if(rank < right - partitionIndex + 1)
        return findElementWithRank(nums,partitionIndex+1,right,rank);
    else    
        return findElementWithRank(nums,left,partitionIndex-1,rank-right+partitionIndex-1);
}
int main() 
{
    srand(static_cast<unsigned int>(time(0)));
    int n, rank;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << "Enter rank of element: ";
    cin >> rank;
    cout << "Element with rank " << rank << " is : " << nums[findElementWithRank(nums, 0, n - 1, rank)] << endl;

    return 0;
}