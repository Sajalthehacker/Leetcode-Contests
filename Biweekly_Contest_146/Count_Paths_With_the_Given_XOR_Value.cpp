// https://leetcode.com/problems/count-paths-with-the-given-xor-value/

/*
You are given a 2D integer array grid with size m x n. You are also given an integer k.

Your task is to calculate the number of paths you can take from the top-left cell (0, 0) to the bottom-right cell (m - 1, n - 1) satisfying the following constraints:

You can either move to the right or down. Formally, from the cell (i, j) you may move to the cell (i, j + 1) or to the cell (i + 1, j) if the target cell exists.
The XOR of all the numbers on the path must be equal to k.
Return the total number of such paths.

Since the answer can be very large, return the result modulo 109 + 7.

 

Example 1:

Input: grid = [[2, 1, 5], [7, 10, 0], [12, 6, 4]], k = 11

Output: 3

Explanation: 

The 3 paths are:

(0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2)
(0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2)
(0, 0) → (0, 1) → (1, 1) → (2, 1) → (2, 2)
Example 2:

Input: grid = [[1, 3, 3, 3], [0, 3, 3, 2], [3, 0, 1, 1]], k = 2

Output: 5

Explanation:

The 5 paths are:

(0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2) → (2, 3)
(0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2) → (2, 3)
(0, 0) → (1, 0) → (1, 1) → (1, 2) → (1, 3) → (2, 3)
(0, 0) → (0, 1) → (1, 1) → (1, 2) → (2, 2) → (2, 3)
(0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 3)
Example 3:

Input: grid = [[1, 1, 1, 2], [3, 0, 3, 2], [3, 0, 2, 2]], k = 10

Output: 0

 

Constraints:

1 <= m == grid.length <= 300
1 <= n == grid[r].length <= 300
0 <= grid[r][c] < 16
0 <= k < 16
*/

const int MOD = 1e9 + 7;

class Solution {
public:
    int solve(int i, int j, int currXor, vector<vector<int>>& grid, int k, vector<vector<vector<int>>> &dp){
        // Base case: If out of bounds, no path is possible
        if (i < 0 || j < 0) return 0;

        // Calculate new XOR including the current cell
        int newXor = currXor ^ grid[i][j];

        // Base case: If we reach the top-left cell, check XOR condition
        if (i == 0 && j == 0) {
            return newXor == k ? 1 : 0;
        }

        // Memoization check
        if (dp[i][j][newXor] != -1) return dp[i][j][newXor];

        // Recursive case: Move left and up
        int leftPaths = solve(i, j - 1, newXor, grid, k, dp);
        int upPaths = solve(i - 1, j, newXor, grid, k, dp);

        // Store and return result
        return dp[i][j][newXor] = (leftPaths + upPaths) % MOD;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1 << 4, -1)));

        return solve(m - 1, n - 1, 0, grid, k, dp);
    }
};
