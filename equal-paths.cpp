#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
#include <iostream>
using namespace std;


// You may add any prototypes of helper functions here
bool traverse(Node * root, int depth, int leaf_depth);
void find_leaf_depth(Node * root, int depth, int &height);


bool equalPaths(Node * root)
{
    // Add your code below'
    int leaf_height = 0; 
    find_leaf_depth(root, 0, leaf_height); 
    return traverse(root, 0, leaf_height); 
}

void find_leaf_depth(Node * root, int depth, int &height){
  int new_depth = depth + 1;  
  if (root == nullptr){
    return; 
  }
  find_leaf_depth(root->left, new_depth, height); 
  find_leaf_depth(root->right, new_depth, height); 
  if (root->left == nullptr && root->right == nullptr && height == 0){
    height = depth; 
  }
}

bool traverse(Node * root, int depth, int leaf_depth){
  if (root == nullptr) return true;
  int x = depth + 1;
  bool left_sub_tree = traverse(root->left, x, leaf_depth);
  if (root->left == nullptr && root->right == nullptr){
    if (depth == leaf_depth) return true; 
    return false; 
  }
  bool right_sub_tree = traverse(root->right, x, leaf_depth);
  return left_sub_tree && right_sub_tree; 
}