#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for reverse
#include <time.h>    //for time measuring
#include <iomanip>   // for setprecision
using namespace std;

void display(vector<int> &arr)
{
    for (int &ele : arr)
        cout << ele << " ";
    cout << endl;
}
void display2D(vector<vector<int>> &arr)
{
    for (vector<int> &ar : arr)
        display(ar);
    cout << endl;
}

// leetcode 1143  LCS

//Memoiozation
int lcs_memo(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == s1.length() || j == s2.length())
        return 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    int ans;
    if (s1[i] == s2[j])
        ans = lcs_memo(s1, s2, i + 1, j + 1, dp) + 1;
    else
        ans = max(lcs_memo(s1, s2, i, j + 1, dp), lcs_memo(s1, s2, i + 1, j, dp));

    return dp[i][j] = ans;
}

//DP of LCS ans also subsequence string also
int lcs_DP(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    string str = "";
    for (i = s1.length(); i >= 0; i--)
    {
        for (j = s2.length(); j >= 0; j--)
        {
            if (i == s1.length() || j == s2.length())
                continue; //base case
            int ans = 0;
            if (s1[i] == s2[j])
            {
                ans = dp[i + 1][j + 1] + 1; //lcs_memo(s1,s2,i+1,j+1,dp)+1;
                str += s1[i];               //If we want subsequence string
            }
            else
                ans = max(dp[i][j + 1], dp[i + 1][j]); //max(lcs_memo(s1,s2,i,j+1,dp),lcs_memo(s1,s2,i+1,j,dp));

            dp[i][j] = ans;
        }
    }

    reverse(str.begin(), str.end());
    cout << str << " " << endl;
    return dp[0][0];
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //return lcs_memo(text1,text2,0,0,dp);
    cout << lcs_DP(text1, text2, 0, 0, dp) << endl;
    display2D(dp);
}

//Leetcode 1035
int maxUncrossedLines(vector<int> &A, vector<int> &B)
{

    //QUESTION same as LCS
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (A[i] == B[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    return dp[0][0];
}
//leetcode 1458 :Hard 4 calls(one call is just multiplication)=====================

int maxdotprod_memo(vector<int> nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp)
{
    if (i == nums1.size() || j == nums2.size())
        return dp[i][j] = -1e8;

    if (dp[i][j] != 0)
        return dp[i][j];

    int val = nums1[i] * nums2[j];
    int a = maxdotprod_memo(nums1, nums2, i + 1, j + 1, dp) + val;
    int b = maxdotprod_memo(nums1, nums2, i, j + 1, dp);
    int c = maxdotprod_memo(nums1, nums2, i + 1, j, dp);

    int prod = max({a, b, c, val});

    return dp[i][j] = prod;
}
int maxdotprod_DP(vector<int> nums1, vector<int> &nums2, vector<vector<int>> &dp)
{

    for (int i = nums1.size(); i >= 0; i--)
    {
        for (int j = nums2.size(); j >= 0; j--)
        {
            if (i == nums1.size() || j == nums2.size())
            {
                dp[i][j] = -1e8;
                continue;
            }

            int val = nums1[i] * nums2[j];
            int a = dp[i + 1][j + 1] + val; //maxdotprod_memo(nums1,nums2,i+1,j+1,dp);
            int b = dp[i][j + 1];           //maxdotprod_memo(nums1,nums2,i,j+1,dp);
            int c = dp[i + 1][j];           //maxdotprod_memo(nums1,nums2,i+1,j,dp);

            int prod = max({a, b, c, val});

            dp[i][j] = prod;
        }
    }
    return dp[0][0];
}
int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //return maxdotprod_memo(nums1,nums2,0,0,dp);
    return maxdotprod_DP(nums1, nums2, dp);
}

//leetcode 1035(just like LONGEST COMMON SUBSEQUENCE ONLY 2 CALLS : WHEN ELE SAME AND OTHER WHEN NOT SAME)

int maxUncrossedLines(vector<int> &A, vector<int> &B)
{

    //QUESTION same as LCS
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (A[i] == B[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    return dp[0][0];
}
void solve()
{
    longestCommonSubsequence("ABCDGH", "AE");
    vector<int> A{1, 4, 2};
    vector<int> B{1, 2, 4};
    cout << maxUncrossedLines(A, B) << endl;
    cout << maxDotProduct(A, B) << endl;
}
int main()
{

    //32 bit system.  */
    clock_t start, end;

    /* Recording the starting clock tick.*/
    start = clock();

    solve();

    // Recording the end clock tick.
    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}