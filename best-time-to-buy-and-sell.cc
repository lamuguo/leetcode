#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct T {
  int first;
  int second;

  string str() {
    stringstream ss;
    ss << "(" << first << ", " << second << ")";
    return ss.str();
  }  
};

class Solution {
public:
  int maxProfit(vector<int> & prices) {
        int res = 0, minp = INT_MAX;
        for (int p : prices) {
            res = max(res, (p - minp));
            minp = min(minp, p);
        }
        return res;
    }

  int maxProfit2(vector<int> &prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<T> A;
    for (int i = 0; i < n; ++i) {
      A.push_back(T{i, prices[i]});
    }

    sort(A.begin(), A.end(), [](const T &x, const T &y) {
	return x.second <= y.second;
      });

    // for (int i = 0; i < n; ++i) {
    //   cout << "xfguo: " << A[i].str() << endl;
    // }

    int last_left = -1;
    int last_left_rank = n - 1;
    int last_right = n;
    int left, right;
    int profit = 0;
    while (true) {
      left = last_left + 1;
      while (A[left].first >= last_left_rank && left < n) left++;
      if (left >= n) break;
      right = last_right - 1;
      while (A[right].first < A[left].first && right > left) right--;
      if (right <= left) break;

      profit = max(profit, A[right].second - A[left].second);
      last_left = left;
      last_right = right;
      last_left_rank = A[left].first;
      //      cout << "xfguo: l = " << A[left].str() << ", r = " << A[right].str() << endl;
    }
    return profit;
  }
};

int main() {
  Solution sol;
  vector<int> A {7, 8, 4, 5, 17};
  int profit = sol.maxProfit(A);
  cout << "output = " << profit << endl;
  return 0;
}
