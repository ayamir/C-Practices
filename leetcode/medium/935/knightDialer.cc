#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    const int mod = 1e9 + 7;
    vector<vector<int>> g{
        {4, 6}, {6, 8},    {7, 9}, {4, 8}, {0, 3, 9},
        {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4},
    };

  public:
    int knightDialer(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        for (int j = 0; j < 10; j++)
            dp[1][j] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int next : g[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][next]) % mod;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 10; j++) {
            res = (res + dp[n][j]) % mod;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.knightDialer(3131) << endl;
    return 0;
}
