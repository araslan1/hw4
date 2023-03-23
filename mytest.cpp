/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


struct Node {
    int key;
    Node *left, *right;
    Node(int k, Node* lt = nullptr, Node* rt = nullptr) :
        key(k), left(lt), right(rt)
    {}
};


bool traverse(Node * root, int depth, int leaf_depth, bool leaf_found){
  if (root == nullptr) return true;
  int x = depth + 1;
  int leaf_depth_ = 0;  
  bool leaf_found_ = false; 
  bool left_sub_tree = traverse(root->left, x, leaf_depth_, leaf_found_);
  if (root->left == nullptr && root->right == nullptr && !leaf_found){
    leaf_depth_ = depth; 
    leaf_found_ = true; 
    return true; 
  }
  if (leaf_found && root->left == nullptr && root->right == nullptr){
    if (depth == leaf_depth) return true; 
    return false; 
  }
  bool right_sub_tree = traverse(root->right, x, leaf_depth_, leaf_found_);
  return left_sub_tree && right_sub_tree; 
}

int main()
{
    Node* e = new Node(0, nullptr, nullptr); 
    Node* b = new Node(0, e, nullptr); 
    Node* d = new Node(0, nullptr, nullptr);
    Node *a = new Node(0, d, nullptr); 
    Node *root = new Node(0, a, b); 
    bool n = traverse(root, 0, 0, false); 
    cout << n << endl; 
    return 0;
}
