#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Binary Search Tree tests
    BinarySearchTree<char,int> bt;
    bt.insert(std::make_pair('a',1));
    bt.insert(std::make_pair('b',2));
    // Node<char, int>* my = successor(bt.internalFind('a'));
    // bt.print();
    bt.myprint(); 
    // cout << it->first; 
    // cout << it->second; 
    // ++it; 
    // cout << it->first;
    // cout << it->second; 
    // predecessor(bt.internalFind('b'));
    // bt.internalFind('a');
    
    cout << "Binary Search Tree contents:" << endl; 
    for(BinarySearchTree<char,int>::iterator it = bt.begin(); it != bt.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    // cout << "hello" << i << endl; 
    // i++;
    
    if(bt.find('b') != bt.end()) {
        cout << "Found b" << endl;
    }
    else {
        cout << "Did not find b" << endl;
    }
    bt.print();
    cout << "Erasing b" << endl;
    // bt.remove('b');
    cout << "PASSED" << endl; 
    // cout << "SEGFAULT?" << endl;
    // cout << "hello" << i << endl; 
    // i++;
    // AVL Tree Tests
    // AVLTree<char,int> at;
    // at.insert(std::make_pair('a',1));
    // at.insert(std::make_pair('b',2));

    // cout << "\nAVLTree contents:" << endl;
    // for(AVLTree<char,int>::iterator it = at.begin(); it != at.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // if(at.find('b') != at.end()) {
    //     cout << "Found b" << endl;
    // }
    // else {
    //     cout << "Did not find b" << endl;
    // }
    // cout << "Erasing b" << endl;
    // at.remove('b');

    return 0;
}
