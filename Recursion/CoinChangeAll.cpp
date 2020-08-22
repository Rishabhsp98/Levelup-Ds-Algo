#include <iostream>
#include <vector>
using namespace std;

//Always make 4 call(4 elements here) for every call after reducing every target(every target call will start from 0 to nums.size() using all elements)
int CoinchangPermu_Inf(vector<int> &nums, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int ele : nums)
    {
        if (target - ele >= 0)
            count += CoinchangPermu_Inf(nums, target - ele, ans + to_string(ele) + " ");
    }
    return count;
}

//just move forward always so use nums[idx] and start next call from idx to nums.size()
int CoinchangeCombina_Inf(vector<int> &nums, int target, int idx, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = idx; i < nums.size(); i++)
        if (target - nums[i] >= 0)
            count += CoinchangeCombina_Inf(nums, target - nums[i], i, ans + to_string(nums[idx]) + " ");
    return count;
}

//Move forward as in case of combination but also after using nums[idx] don't use it again so idx+1
int CoinchangeCombina_Single(vector<int> &nums, int target, int idx, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = idx; i < nums.size(); i++)
    {
        if (target - nums[i] >= 0)
            count += CoinchangeCombina_Single(nums, target - nums[i], i + 1, ans + to_string(nums[i]) + " ");
    }

    return count;
}
void CoinchangeMain()
{
    vector<int> arr{1, 2, 5};
    // cout << "Total  " << CoinchangPermu_Inf(arr, 10, "");
    cout << "Total  " << CoinchangeCombina_Inf(arr, 5, 0, "");
    // cout << "Total  " << CoinchangeCombina_Single(arr, 10, 0, "");
}
void solve()
{
    CoinchangeMain();
}
int main()
{
    solve();
    return 0;
}