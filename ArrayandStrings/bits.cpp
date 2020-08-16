#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calc(int i, vector<int> &nums1, int size, int s, int &mask)
{
    if (i == size) //base case
    {
        if (s == 0)
            mask++;
        return;
    }
    calc(i + 1, nums1, size, s + nums1[i], mask);
    calc(i + 1, nums1, size, s, mask);
}

int main()
{
    int n, input;
    cin >> n;
    vector<int> nums(n);
    vector<int> nums1(n, 0);
    for (int &input : nums)
        cin >> input;

    int maxele = 0;
    sort(nums.begin(), nums.end()); //O(nlogn)
    maxele = nums.back();           //Largest element

    int count = 0; //count max number of set bit position

    while (maxele != 0)
    {
        count++;
        maxele = maxele >> 1;
    }

    int point = 0; //now storing the number of set bits in each element as other vector
    for (int ele : nums)
    {
        while (ele)
        {
            if (ele & 1)
                nums1[point]++;
            ele = ele >> 1;
        }
        point++;
    }

        return 0;
}

/* bits operations

*/