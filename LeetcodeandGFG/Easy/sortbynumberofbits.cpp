#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Leetcode 1356

/*
if we want to create function of number of bits
    int count=0;
    for(int i=0;i<n;i++)
    {
        int mask=(1<<i);
        if((mask & n)!= 0)
            count++;

    } 
    return count
*/
class Solution
{

public:
    static bool SortBySec(int &a, int &b)
    {
        int x = __builtin_popcount(a);
        int y = __builtin_popcount(b);
        if (x != y) //Means both number of bits are equal
            return x < y;
        else // normal (simply whose smaller number (both number of bits aren't equal))
            return a < b;
    }

    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), SortBySec);
        return arr;
    }
};
