#include<iostream>
#include<vector>
using namespace std;

// rank = 1 + number of elements greater than X
int findRank(vector<int>& nums,int elementIndex)
{
    int rank = 1;
    for(int num : nums)
        if(nums[elementIndex] < num)
            rank++;
    return rank;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    int elementIndex;
    cout << "Enter index of element to find rank: ";
    cin >> elementIndex;
    if(elementIndex < 0 || elementIndex >= n)
    {
        cout << "Invalid Index";
        return 1;
    }
    int rank = findRank(nums,elementIndex);
    cout << "Rank of element " << nums[elementIndex] << " at index " << elementIndex << " is " << rank << endl;
    return 0;
    
}
