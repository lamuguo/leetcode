#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {

public:
  vector<vector<set<string>>> v;

  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    // quick check
    set<char> ch_in_words;
    for (auto &word : dict) {
      for (int i = 0; i < word.length(); ++i) {
	ch_in_words.insert(word[i]);
      }
    }
    for (int i = 0; i < s.length(); ++i) {
      if (ch_in_words.count(s[i]) == 0) {
	return vector<string>();
      }
    }
    

    int n = s.length();
    v.resize(n);
    for (int i = 0; i < n; ++i) {
      v[i].resize(n);
    }
    set<string> *out = wordBreak2(0, n - 1, s, dict);
    if (out->count("FALSE") > 0) {
      return vector<string>();
    }
    return vector<string>(out->begin(), out->end());
  }
    
  set<string> *wordBreak2(int l, int r, string s,
			 unordered_set<string> &dict) {
    if (!v[l][r].empty()) {
      //cout << "xfguo: l = " << l << ", r = " << r << ", out = "	   << str(v[l][r]) << endl;
      return &v[l][r];
    }
    set<string> result;
    if (dict.count(s.substr(l, r - l + 1)) > 0) {
      result.insert(s.substr(l, r - l + 1));
    }
    for (int i = l; i < r; ++i) {
      if (wordBreak2(l, i, s, dict)->count("FALSE") == 0 &&
	  wordBreak2(i + 1, r, s, dict)->count("FALSE") == 0) {
	for (string ls : v[l][i]) {
	  for (string rs : v[i+1][r]) {
	    result.insert(ls + " " + rs);
	  }
	}
      }
    }
    if (result.empty()) {
      result.insert("FALSE");
    }
    static int count = 0;
    if (count++ % 100 == 0) {
      // cout << "xfguo: count = " << count << endl; cout.flush();
    }
    v[l][r] = result;
    //    cout << "xfguo: l = " << l << ", r = " << r << ", out = " << str(result) << endl;
    return &v[l][r];
  }

  string str(const set<string> &in) {
    stringstream ss;
    ss << "{";
    for (auto s : in) {
      ss << s << ", ";
    }
    ss << "}";
    return ss.str();
  }
};

int main() {
  Solution sol;
  unordered_set<string> dict {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  for (auto s: sol.wordBreak(string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"), dict)) {
    cout << "output: " << s << endl;
  }
  return 0;
}
