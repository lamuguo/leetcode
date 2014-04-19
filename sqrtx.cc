#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long int int64;
  int sqrt(int x) {
    int64 xx = static_cast<int64>(x);
    int64 left = 0;
    int64 right = 1 << 16;
    while (left < right) {
      int64 m = (left + right) / 2;
      if (m * m == xx) return static_cast<int>(m);
      if (m * m > xx)
        right = m;
      else
        left = m;
      if (left + 1 == right) {
        return static_cast<int>(left);
      }
      cout << "xfguo: l = " << left << ", right = " << right << ", m = " << m << ", m * m = " << m*m << endl;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  int s = sol.sqrt(2147395599);
  cout << "output = " << s << endl;
  return 0;
}
