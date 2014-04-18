/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// The solution works for both I and II of the problem.

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  vector<TreeLinkNode *> v;
  void connect(TreeLinkNode *root) {
    if (root == NULL) {
      return;
    }
    connect(0, root);
  }
    
  void connect(int level, TreeLinkNode *node) {
    if (v.size() == level) {
      v.emplace_back(node);
      node->next = NULL;
    } else {
      v[level]->next = node;
      v[level] = node;
    }
    if (node->left != NULL) connect(level + 1, node->left);
    if (node->right != NULL) connect(level + 1, node->right);
  }
};

int main() {
  Solution sol;
  return 0;
}
