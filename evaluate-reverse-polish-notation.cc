// err 1: forgot break
// err 2: don't know stack<>.

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (string token : tokens) {
            int v = -1;
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int r = st.top();st.pop();
                int l = st.top(); st.pop();
                switch (token[0]) {
		case '+': v = l + r; break;
		case '-': v = l - r; break;
		case '*': v = l * r; break;
		case '/': v = l / r; break;
		default: v = -1;
                }
            } else {
	      v = stoi(token);
            }
            st.push(v);
        }
        return st.top();
    }
};

int main() {
  vector<string> tokens {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};

  Solution sol;
  cout << "result = " << sol.evalRPN(tokens) << endl;
  return 0;
}

