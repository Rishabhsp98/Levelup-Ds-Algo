#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//All are easy category

//Medium
//leetcode 1091 just learn the technique how to use 1-d array from 2-d array(vector) and just simply run BFS which is very familiar

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (n == 0 || m == 0)
        return -1;
    if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        return -1;

    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    queue<int> que;
    que.push(0); //starting from (0,0)

    grid[0][0] = 1;
    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size--)
        {
            int rvtx = que.front();
            que.pop();

            int r = rvtx / m; //using row number
            int c = rvtx % m; //using coloumn number

            if (r == n - 1 && c == m - 1)
                return level + 1;
            for (int d = 0; d < 8; d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];

                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0)
                {
                    que.push(x * m + y); //this is the way to put data at that index
                    grid[x][y] = 1;
                }
            }
        }
        level++;
    }
    return -1;
}

//Medium
//leetcode Wall and gates (Just put all 0's in queue and then fill every infinity with the level they are occuring)

//Wall and Gates on lintcode (premium)

void WallandGates(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (n == 0 || m == 0)
        return;
    int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    queue<int> que;
    // que.push(0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 0)
                que.push((i * m + j));

    int level = 1;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size--)
        {
            int rvtx = que.front();
            que.pop();

            int r = rvtx / m;
            int c = rvtx % m;

            for (int d = 0; d < 4; d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];

                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == INT32_MAX)
                {
                    que.push(x * m + y);
                    grid[x][y] = level;
                }
            }
        }
        level++;
    }
}

//Medium
//leetcode 994 (Rotting oranges)
/* Amazon's favourite just similar to wall and gates put all 2's 
    in queue and then run BFS for that queue,after that then at the end
    If any grid[x][y]==1(means still fresh Left) 
    return -1(Not Possible to Rott everyone) otherwise return 
    level at which all are rotten */

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (n == 0 || m == 0)
        return -1;

    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    queue<int> que;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 2)
                que.push(i * m + j);

    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size--)
        {
            int rvtx = que.front();
            que.pop();

            int r = rvtx / m;
            int c = rvtx % m;

            for (int d = 0; d < 4; d++)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];

                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                {
                    que.push(x * m + y);
                    grid[x][y] = 2;
                }
            }
        }
        level++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return level == 0 ? 0 : level - 1;
}

int main()
{

    return 0;
}