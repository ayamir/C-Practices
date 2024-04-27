#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> pathsWithMaxScore(vector<string> &board) {
        int n = board.size();
        const int mod = 1e9 + 7;
        // 表示走到i,j位置的方案总数和相应得分
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, 0)));
        dp[n - 1][n - 1][0] = 0;
        dp[n - 1][n - 1][1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            char ch = board[n - 1][j];
            if (ch != 'X') {
                dp[n - 1][j][1] = dp[n - 1][j + 1][1];
                if (dp[n - 1][j][1] != 0)
                    dp[n - 1][j][0] = dp[n - 1][j + 1][0] + ch - '0';
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            char ch = board[i][n - 1];
            if (ch != 'X') {
                dp[i][n - 1][1] = dp[i + 1][n - 1][1];
                if (dp[i][n - 1][1] != 0)
                    dp[i][n - 1][0] = dp[i + 1][n - 1][0] + ch - '0';
            }
        }
        auto maxPair = [&](vector<int> &a, vector<int> &b) -> pair<int, int> {
            if (a[0] > b[0]) {
                return make_pair(a[0], a[1]);
            } else {
                return make_pair(b[0], b[1]);
            }
        };
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                char ch = board[i][j];
                if (ch != 'X') {
                    int score, num;
                    tie(score, num) = maxPair(dp[i + 1][j], dp[i][j + 1]);
                    dp[i][j][1] = num;
                    if (dp[i][j][1] != 0)
                        dp[i][j][0] = score + ch - '0';
                }
            }
        }
        dp[0][0][1] %= mod;
        return dp[0][0];
    }
};

int main(int argc, char *argv[]) {
    Solution solu;
    vector<string> board = {"E12", "1X1", "21S"};
    auto res = solu.pathsWithMaxScore(board);
    for (const auto &value : res) {
        cout << value << " ";
    }
    return 0;
}
