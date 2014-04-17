#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Tuple {
  int val;
  int ref_count;

  string str() {
    stringstream ss;
    ss << "(" << val << ", " << ref_count << ")";
    return ss.str();
  }
};

class LRUCache{
public:
  unordered_map<int, Tuple> tuples_;
  queue<int> visits_;
  int capacity_;

  LRUCache(int capacity) : capacity_(capacity) {
  }
    
  int get(int key) {
    int result = -1;
    if (tuples_.count(key) > 0) {
      //      cout << "xfguo: push " << key << endl;
      visits_.push(key);
      tuples_[key].ref_count++;
      result = tuples_[key].val;
    }
    //cout << "out: " << result << endl;
    return result;
  }
    
  void set(int key, int value) {
    if (tuples_.count(key) > 0) {
      //      cout << "xfguo: push " << key << endl;
      tuples_[key].ref_count++;
      tuples_[key].val = value;
      visits_.push(key);
      return;
    }
    if (tuples_.size() < capacity_) {
      //      cout << "xfguo: push " << key << endl;
      tuples_[key] = Tuple{value, 1};
      visits_.push(key);
    } else {
      bool found = false;
      int k = -1;
      while (!found) {
	k = visits_.front(); visits_.pop();
	//	cout << "xfguo: pop " << k << ", tuple = " << tuples_[k].str() << endl;
	if (--tuples_[k].ref_count == 0) {
	  found = true;
	};
      }
      tuples_.erase(k);
      tuples_[key] = Tuple{value, 1};
      //      cout << "xfguo: push " << key << endl;
      visits_.push(key);
    }
  }

  string str() {
    stringstream ss;
    ss << "tuples_: {";
    for (auto t : tuples_) {
      ss << "(" << t.first << ", " << t.second.str() << ")";
    }
    ss << "}";
    return ss.str();
  }

  void run() {
    get(2);set(2,6);get(1);set(1,5);set(1,2);get(1);get(2);
  }
};

int main() {
  LRUCache lru(2);
  lru.run();
}
