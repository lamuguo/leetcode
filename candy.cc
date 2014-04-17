#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int calculate(int min0, int max1, int min1) {
    int result = 0;
    if (max1 - min0 < min1 - max1) {
      result = candies(min0, max1 - 1) + candies(max1, min1);
    } else {
      result = candies(min0, max1) + candies(max1 + 1, min1);
    }
    //            cout << "xfguo: " << min0 << ", " << max1 << ", " << min1 << ", result = " << result << endl;
    return result;
  }
    
  int candies(int left, int right) {
    if (left > right) {
      return 0;
    }
    int l = right - left + 1;
    return l * (l + 1) / 2;
  }

  int candy(vector<int> &A) {
    int total = 0;
    int n = A.size();
    int last_min = 0;
    int maxp = -1;
    int minp = -1;
    for (int i = 0; i < n; ++i) {
      if ((i == 0 || A[i] >= A[i-1]) && (i == n - 1 || A[i] >= A[i+1])) {
	maxp = i;
      }
      if (maxp >= 0 && (i == n - 1 || A[i] <= A[i+1])) {
	minp = i;
	total += calculate(last_min, maxp, i);
	if (i == n - 1 || A[i] == A[i+1]) {
	  last_min = i + 1;
	} else {
	  last_min = i;
	  total--;
	  //cout << "xfguo: total--" << endl;
	}
	maxp = -1;
      }
    }
    if (minp < maxp) {
      total += calculate(last_min, maxp, n - 1);
    }
    return total;
  }
};


int main() {
  Solution sol;
  //vector<int> A {2,4, 4, 6};
  // vector<int> A {2,2};
   vector<int> A {1,0,2};
  cout << "output = " << sol.candy(A) << endl;
  return 0;
}

