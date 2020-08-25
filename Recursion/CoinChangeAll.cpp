#include <iostream>
#include <vector>
using namespace std;

//Faith
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

/*Just same way like we have to make all 4 numsbers(here) call for every target
 but now as we can not use same element twice we just block it after making call 
 for particular target ,and after target==0 (backtrack) we restore it to positive
for other calls.*/

int CoinchangePermu_Single(vector<int> &nums, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = nums[i];
        if (nums[i] > 0 && target - nums[i] >= 0)
        {
            nums[i] *= -1;
            count += CoinchangePermu_Single(nums, target - temp, ans + to_string(temp) + " ");
            nums[i] *= -1;
        }
    }
    return count;
}
void CoinchangeMain()
{
    vector<int> arr{2, 3, 5, 7};
    // cout << "Total  " << CoinchangPermu_Inf(arr, 10, "");
    // cout << "Total  " << CoinchangeCombina_Inf(arr, 5, 0, "");
    // cout << "Total  " << CoinchangeCombina_Single(arr, 10, 0, "");
    cout << "Total  " << CoinchangePermu_Single(arr, 10, "");
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