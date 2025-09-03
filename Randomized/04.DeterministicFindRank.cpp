#include <iostream>
#include <vector>
using namespace std;

int findElementWithRank(vector<int>& nums, int left, int right, int rank) ;

void swap(vector<int>& nums, int i, int j) 
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void bubbleSort(vector<int>& nums, int left, int right) 
{
    for (int i = 0; i < right - left; ++i) 
        for (int j = left; j < right - i; ++j) 
            if (nums[j] > nums[j + 1]) 
                swap(nums, j, j + 1);
}

int partition(vector<int>& nums, int left, int right) 
{
    int pivotValue = nums[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= j && nums[i] <= pivotValue) i++;
        while (i <= j && nums[j] > pivotValue) j--;
        if (i < j) swap(nums, i, j); 
    }
    swap(nums, left, j);
    return j;
}

// evaluates medians of medians
// Step1: Divide into groups of 5
// Step2: Sort each group
// Step3: Find median of medians using findElementWithRank()
int goodPivot(vector<int>& nums, int left, int right) 
{
    // for arrays smaller than 5 elements
    if (right - left < 5) 
    {
        bubbleSort(nums, left, right);
        return left + (right - left) / 2; // Return median index of small group
    }

    // Ceiling division to account for partial groups
    int groups = (right - left + 1 + 4) / 5;
    int j = left;
    // Process all elements, including partial groups.
    for (int i = left; i <= right; i += 5) 
    {
        int groupRight = min(i + 4, right); // Handle partial groups
        bubbleSort(nums, i, groupRight);
        swap(nums, j, i + (groupRight - i) / 2); // Move median to front
        j++;
    }
    // CHANGE: Used (groups + 1) / 2 for correct median rank (e.g., for 3 groups, rank 2 instead of 1).
    return findElementWithRank(nums, left, left + groups - 1, (groups + 1) / 2);
}

int findElementWithRank(vector<int>& nums, int left, int right, int rank) 
{
    // base case to handle left == right, avoiding unnecessary recursion.
    if (left == right) 
        return left;

    int pivotIndex = goodPivot(nums, left, right);
    swap(nums, left, pivotIndex);
    int partitionIndex = partition(nums, left, right);
    int pivotRank = right - partitionIndex + 1; // Number of elements >= pivot

    if (rank == pivotRank) 
        return partitionIndex;
    else if (rank < pivotRank) 
        return findElementWithRank(nums, partitionIndex + 1, right, rank);
    else 
        return findElementWithRank(nums, left, partitionIndex - 1, rank - pivotRank);
}

int main() 
{
    int n, rank;
    cout << "Enter number of elements: ";
    cin >> n;
    // Validation for n to prevent invalid vector initialization.
    if (n <= 0) 
    {
        cout << "Invalid number of elements!" << endl;
        return 1;
    }
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << "Enter rank of element (1 to " << n << "): ";
    cin >> rank;
    // Validation for rank to ensure it’s within bounds.
    if (rank <= 0 || rank > n) 
    {
        cout << "Invalid rank! Rank must be between 1 and " << n << "." << endl;
        return 1;
    }
    int index = findElementWithRank(nums, 0, n - 1, rank);
    cout << "Element with rank " << rank << " is: " << nums[index] << endl;
    return 0;
}
