#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> f;

  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n == 0) {
      return 0;
    }

    f.resize(n);
    for (int i = 0; i < n; ++i) {
      f[i].resize(n);
      for (int j = 0; j < n; ++j) {
        f[i][j] = -1;
      }
    }

    return maxProfit(0, n-1, prices);
  }

  int maxProfit(int l, int r, const vector<int> &A) {
    if (f[l][r] >= 0) {
      return f[l][r];
    }
    int maxp = max(0, A[r] - A[l]);
    for (int i = l; i < r; ++i) {
      maxp = max(maxp, maxProfit(l, i, A) + maxProfit(i+1, r, A));
    }
    f[l][r] = maxp;
    //cout << "xfguo: f[" << l << "][" << r << "] = " << maxp << endl;
    return maxp;
  }
};

int main() {
  Solution sol;
  vector<int> A {6,1,3,2,4,7};
  int profit = sol.maxProfit(A);
  cout << "output = " << profit << endl;
  return 0;
}
