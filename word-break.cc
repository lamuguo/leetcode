#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    int n = s.length();
    if (n == 0) return true;
    visited.resize(n);
    for (int i = 0; i < n; ++i) {
      visited[i].resize(n);
    }
    return canBreak(s, dict, 0, n - 1);
  }
    
  vector<vector<int>> visited;
  bool canBreak(const string &s,
		const unordered_set<string> &dict, int l, int r) {
    if (visited[l][r] > 0) {
      return visited[l][r] == 1;
    }
    bool result = false;
    if (dict.count(s.substr(l, r - l + 1)) > 0) {
      result = true;
    } else {
      for (int i = l; i < r; ++i) {
	if (canBreak(s, dict, l, i) && canBreak(s, dict, i + 1, r)) {
	  result = true;
	}
      }
    }
    visited[l][r] = result ? 1 : 2;
    return result;
  }
};

int main() {
  Solution sol;
  unordered_set<string> dict {"leet", "code", "lee"};
  cout << "output = " << sol.wordBreak(string("leetcode"), dict) << endl;
  return 0;
}
