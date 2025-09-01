#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& heights)
{
    int n = heights.size();
    int left = 0;
    int right = n - 1;
    int max_left = 0, max_right = 0;
    int water_trapped = 0;
    while(left <= right)
    {
        if(heights[left] <= heights[right])
        {
            max_left = max(heights[left],max_left);
            water_trapped += ((heights[left] == max_left) ? 0 : max_left - heights[left]);
            left++;
        }
        else
        {
            max_right = max(heights[right],max_right);
            water_trapped += ((heights[right] == max_right) ? 0 : max_right - heights[right]);            
            right--;
        }

    } 
    return water_trapped;
}

int main()
{
    vector<int> heights;
    int x;
    while(cin>>x)
        heights.push_back(x);
    int water_trapped = trap(heights);
    cout<<"Water trapped: "<<water_trapped;
    return 0;
}
