#include <iostream>

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      int mask = 1 << i;
      int sum = 0;
      for (int j = 0; j < n; ++j) {
	if ((A[j] & mask) != 0) {
	  sum++;
	}
      }
      //      cout << "xfguo: bit " << mask << ", sum = " << sum << endl;
      if (sum % 2 != 0) {
	res |= mask;
      }
    }
    return res;
  }
};


int main() {
  Solution sol;
  int A[] = {-1, 3, 5, 5, 3};
  cout << "size = " << sizeof(A) / sizeof(int) << endl;
  cout << "output = " << sol.singleNumber(A, sizeof(A) / sizeof(int)) << endl;
  return 0;
}
