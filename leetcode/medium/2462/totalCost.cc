#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    long long totoalCost(vector<int> &costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<>> pq0, pq1;
        int i = 0;
        int j = costs.size() - 1;
        long long res = 0;
        while (k--) {
            while (pq0.size() < candidates && i <= j) {
                pq0.push(costs[i++]);
            }
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[j--]);
            }
            int a = (pq0.size() > 0) ? pq0.top() : INT_MAX;
            int b = (pq1.size() > 0) ? pq1.top() : INT_MAX;
            if (a <= b) {
                res += a;
                pq0.pop();
            } else {
                res += b;
                pq1.pop();
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
