#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        string word;
        vector<string> vs;
        while (is >> word) {
            vs.push_back(word);
        }
        s.clear();
        reverse(vs.begin(), vs.end());
        ostringstream os;
        for (int i = 0; i < vs.size(); ++i) {
            if (i > 0) {
                os << " ";
            }
            os << vs[i];
        }
        s = os.str();
    }
};

int main() {
  Solution sol;
  string s = "a";
  sol.reverseWords(s);
  cout << "output = '" << s << "'" << endl;
  return 0;
}
