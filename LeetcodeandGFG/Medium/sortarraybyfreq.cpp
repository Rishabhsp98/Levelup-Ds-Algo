#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first; //This-other
}
void ques(vector<int> &nums)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int &ele : nums)
        mp[ele]++;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    vector<pair<int, int>> v;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        v.push_back(make_pair(itr->first, itr->second));
    }
    sort(v.begin(), v.end(), comp);
    for (auto itr = v.begin(); itr != v.end(); ++itr)
    {
        int q = itr->second;
        while (q--)
        {
            cout << itr->first << " ";
        }
    }
}

int main()
{
    //code
    int t, n, input;
    cin >> t;
    vector<int> ans;
    while (t--)
    {
        cin >> n;
        vector<int> nums(n);
        nums.clear();
        ans.clear();
        while (n--)
        {
            cin >> input;
            nums.push_back(input);
        }
        ques(nums);
        cout << endl;
    }
    return 0;
}