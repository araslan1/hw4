#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include<vector>

/**
 * A templated class for a Node in a search tree.
 * The getters for parent/left/right are virtual so
 * that they can be overridden for future kinds of
 * search trees, such as Red Black trees, Splay trees,
 * and AVL trees.
 */


template <typename Key, typename Value>
class Node
{
public:
    Node(const Key& key, const Value& value, Node<Key, Value>* parent);
    virtual ~Node();

    const std::pair<const Key, Value>& getItem() const;
    std::pair<const Key, Value>& getItem();
    const Key& getKey() const;
    const Value& getValue() const;
    Value& getValue();

    virtual Node<Key, Value>* getParent() const;
    virtual Node<Key, Value>* getLeft() const;
    virtual Node<Key, Value>* getRight() const;

    void setParent(Node<Key, Value>* parent);
    void setLeft(Node<Key, Value>* left);
    void setRight(Node<Key, Value>* right);
    void setValue(const Value &value);

protected:
    std::pair<const Key, Value> item_;
    Node<Key, Value>* parent_;
    Node<Key, Value>* left_;
    Node<Key, Value>* right_;
};

/*
  -----------------------------------------
  Begin implementations for the Node class.
  -----------------------------------------
*/

/**
* Explicit constructor for a node.
*/
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) :
    item_(key, value),
    parent_(parent),
    left_(NULL),
    right_(NULL)
{

}

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed by the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node()
{

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<const Key, Value>& Node<Key, Value>::getItem() const
{
    return item_;
}

/**
* A non-const getter for the item.
*/
template<typename Key, typename Value>
std::pair<const Key, Value>& Node<Key, Value>::getItem()
{
    return item_;
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const
{
    return item_.first;
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const
{
    return item_.second;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
    return item_.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const
{
    return parent_;
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const
{
    return left_;
}

/**
* An implementation of the virtual function for retreiving the right child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const
{
    return right_;
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent)
{
    parent_ = parent;
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left)
{
    left_ = left;
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right)
{
    right_ = right;
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value)
{
    item_.second = value;
}

/*
  ---------------------------------------
  End implementations for the Node class.
  ---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree
{
public:
    BinarySearchTree(); //TODO
    virtual ~BinarySearchTree(); //TODO
    virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO
    virtual void remove(const Key& key); //TODO
    void clear(); //TODO
    bool isBalanced(); //TODO
    void print() const;
    bool empty() const;

    template<typename PPKey, typename PPValue>
    friend void prettyPrintBST(BinarySearchTree<PPKey, PPValue> & tree);
public:
    /**
    * An internal iterator class for traversing the contents of the BST.
    */
    class iterator  // TODO
    {
    public:
        iterator();

        std::pair<const Key,Value>& operator*() const;
        std::pair<const Key,Value>* operator->() const;

        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const;
        iterator& operator++();
        Node<Key, Value>* successor(Node<Key, Value>* current);
    protected:
        friend class BinarySearchTree<Key, Value>;
        iterator(Node<Key,Value>* ptr);
        Node<Key, Value> *current_;
    };

public:
    iterator begin() const;
    iterator end() const;
    iterator find(const Key& key) const;
    Value& operator[](const Key& key);
    Value const & operator[](const Key& key) const;
    void myprint();

protected:
    bool balance(Node<Key,Value> *next);
    int balance_traverse(Node<Key,Value> *next); 
    void traverse(Node<Key,Value> *next); 
    Node<Key, Value>* internalFind(const Key& k) const; // TODO 
    // Mandatory helper functions
    Node<Key, Value> *getSmallestNode() const;  // TODO
    Node<Key, Value>* successor(Node<Key, Value>* current);
    // Note:  static means these functions don't have a "this" pointer
    //        and instead just use the input argument.
    static Node<Key, Value>* predecessor(Node<Key, Value>* current); // TODO
    // Provided helper functions
    virtual void printRoot (Node<Key, Value> *r) const;
    virtual void nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2) ;
     
    // Add helper functions here


protected:
    Node<Key, Value>* root_;
    // You should not need other data members
};

/*
--------------------------------------------------------------
Begin implementations for the BinarySearchTree::iterator class.
---------------------------------------------------------------
*/

/**
* Explicit constructor that initializes an iterator with a given node pointer.
*/



template<class Key, class Value>
Node<Key, Value>* 
BinarySearchTree<Key, Value>::iterator::successor(Node<Key, Value>* current)
{

    if (current == nullptr){
      return nullptr;
    }

    // std::cout << "SUCCESSOR" << current->getKey(); 
    // if (current->getRight() == nullptr){
    //     std::cout << "DAM CALL";
    // }
    if (current->getRight() != nullptr){
        // Key mykey = current->getRight()->getKey();
        Node<Key,Value> * successor = current->getRight();
        while (successor->getLeft() != nullptr){
            successor = successor->getLeft(); 
        }
        // std::cout << "SUCCESSOR: " << successor->getKey();
        return successor; 
    }else{
        Node<Key,Value> * successor = current->getParent();
        if (successor->getParent() == nullptr){
          return nullptr; 
        }
        while (successor->getParent()->getLeft() != successor){
          if (successor == nullptr){
            return nullptr; 
          }
          successor = successor->getParent();
          
        }
        // std::cout << "SUCCESSOR: " << successor->getParent()->getKey();
        return successor->getParent(); 
    }
}


template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value> *ptr)
{
    current_ = ptr; 
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::myprint()
{
    Node<Key, Value> *temp = root_; 
    Node<Key, Value> *child = temp->getRight(); 
    nodeSwap(temp, child); 
    // std:: cout << "THIS IS KEY: " << temp->getKey(); 

}

/**
* A default constructor that initializes the iterator to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator() 
{
    current_ = NULL;
}

/**
* Provides access to the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> &
BinarySearchTree<Key, Value>::iterator::operator*() const
{
    return current_->getItem();
}

/**
* Provides access to the address of the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> *
BinarySearchTree<Key, Value>::iterator::operator->() const
{
    return &(current_->getItem());
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator==(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    if (this->current_ == rhs.current_){
      return true;
    }
    return false; 
    // if ((*this)->first == rhs->first && (*this)->second == rhs->second){
    //     return true;
    // }
    // return false;
}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator!=(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{ 
    if (this->current_ != rhs.current_){
      return true;
    }
    return false; 
    // if (rhs.current_ == nullptr){
    //   if (current_ == nullptr){
    //     return false; 
    //   }else{
    //     return true; 
    //   }
    // }
    // if (((*this)->first != rhs->first) | ((*this)->second != rhs->second)){
    //     return true;
    // }
    // return false;
}


/**
* Advances the iterator's location using an in-order sequencing
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator&
BinarySearchTree<Key, Value>::iterator::operator++()
{
    // TODO
    // if (current_->getRight() != nullptr){
    //     Node<Key,Value> *successor =  current_->getRight(); 
    //     while (successor->getLeft() != nullptr){
    //         successor = successor->getLeft(); 
    //     }
    //     // std::cout << "This is successor key returned: " << successor->getKey() << "WHEN"; 
    //     BinarySearchTree<Key,Value>::iterator it(successor); 
    //     std::cout << "This is key supposed to b: " << it->first << " " << it->second << " "; 
    //     return it; 
    // }else{
    //     bool left_node_found = false; 
    //     Node<Key,Value>* successor = current_; 
    //     while (left_node_found == false){
    //         successor = successor->getParent(); 
    //         if (successor == nullptr){
    //             BinarySearchTree<Key,Value>::iterator it(nullptr); 
    //             return it; 
    //         }
    //         if (successor->getParent()->getLeft() == successor){
    //             left_node_found = true; 
    //         }
    //     }
    //     // std::cout << "WHEN" << successor->getParent()->getKey(); 
    //     BinarySearchTree<Key,Value>::iterator it(successor->getParent()); 
    //     return it; 
    // }
    current_ = successor(current_); 
    return *this; 


}


/*
-------------------------------------------------------------
End implementations for the BinarySearchTree::iterator class.
-------------------------------------------------------------
*/

/*
-----------------------------------------------------
Begin implementations for the BinarySearchTree class.
-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::BinarySearchTree() 
{
    // TODO
    root_ = NULL; 
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree()
{
    // TODO
    clear(); 
}

/*
 * Returns true if tree is empty
*/

template<class Key, class Value>
bool BinarySearchTree<Key, Value>::empty() const
{
    return root_ == NULL;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{
    printRoot(root_);
    std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/




template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::begin() const
{
    // std::cout << "BEGIN KEY" << getSmallestNode()->getRight()->getKey(); 
    BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());
    return begin;
}

/**
* Returns an iterator whose value means INVALID
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::end() const
{
    BinarySearchTree<Key, Value>::iterator end(NULL);
    return end;
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::find(const Key & k) const
{
    Node<Key, Value> *curr = internalFind(k);
    BinarySearchTree<Key, Value>::iterator it(curr);
    return it;
}

/**
 * @precondition The key exists in the map
 * Returns the value associated with the key
 */
template<class Key, class Value>
Value& BinarySearchTree<Key, Value>::operator[](const Key& key)
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}
template<class Key, class Value>
Value const & BinarySearchTree<Key, Value>::operator[](const Key& key) const
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}

/**
* An insert method to insert into a Binary Search Tree.
* The tree will not remain balanced when inserting.
* Recall: If key is already in the tree, you should 
* overwrite the current value with the updated value.
*/
template<class Key, class Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<const Key, Value> &keyValuePair)
{
    // TODO
    // if you insert 1 and then 2, you have to move stuff around to get 1
    //if keyValuePair is less than current node go left, if it's greater go right; 
    // std::cout << "THIS IS KEY VALUE PAIR: " << keyValuePair.first << keyValuePair.second;
    if (root_ == nullptr){
      root_ = new Node<Key,Value>(keyValuePair.first, keyValuePair.second, nullptr);
      return; 
    }
    Node<Key, Value>* root = root_; 
    while (root != nullptr){
      if (keyValuePair.first < root->getItem().first){
        //go left
        if (root->getLeft() == nullptr){
          Node<Key,Value>* temp = new Node<Key,Value>(keyValuePair.first, keyValuePair.second, root);
          root->setLeft(temp);
          break;
        }
        root = root->getLeft();
      }else if(keyValuePair.first == root->getItem().first){
        root->getItem().second = keyValuePair.second; 
        break; 
      }
      else{
        //go right
        if (root->getRight() == nullptr){
          Node<Key,Value>* temp = new Node<Key,Value>(keyValuePair.first, keyValuePair.second, root);
          root->setRight(temp);
          break;
        }
        root = root->getRight();
      }
    }
}


/**
* A remove method to remove a specific key from a Binary Search Tree.
* Recall: The writeup specifies that if a node has 2 children you
* should swap with the predecessor and then remove.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::remove(const Key& key)
{
    // TODO
    if (root_ == nullptr){
      return; 
    }
    Node<Key,Value>* temp = internalFind(key); 
    Node<Key,Value>* keeper; 
    Node<Key,Value>* parent; 
  

    if (temp != nullptr){
      if (temp->getRight() != nullptr && temp->getLeft() != nullptr){
        keeper = predecessor(temp);
        nodeSwap(temp, keeper); 
        parent = temp->getParent(); 
        if (parent != nullptr && parent->getRight() == temp){
          parent->setRight(nullptr); 
          delete temp; 
          temp = nullptr; 
        }else if (parent != nullptr && parent->getLeft() == temp){
          parent->setLeft(nullptr); 
          delete temp; 
          temp = nullptr; 
        }else{
          keeper->setParent(nullptr); 
          root_ = keeper;
          delete temp; 
          temp = nullptr; 
        }
        // std::cout << "THIS IS SUCC KEY: " << my_pred->getKey(); 
        
        // std::cout << "THIS IS ROOT KEY: " << root_->getKey(); 
        delete temp; 
        

      }else if (temp->getRight() != nullptr){
        parent = temp->getParent(); 
        keeper = temp->getRight(); 
        if (parent != nullptr && parent->getRight() == temp){
          parent->setRight(keeper); 
          keeper->setParent(parent); 
          delete temp; 
          temp = nullptr; 
        }else if (parent != nullptr && parent->getLeft() == temp){
          parent->setLeft(keeper); 
          keeper->setParent(parent); 
          delete temp; 
          temp = nullptr; 
        }else{
          keeper->setParent(nullptr); 
          root_ = keeper;
          delete temp; 
          temp = nullptr; 
        }
      }else if (temp->getLeft() != nullptr){
        parent = temp->getParent(); 
        keeper = temp->getLeft(); 
        if (parent != nullptr && parent->getRight() == temp){
          parent->setRight(keeper); 
          keeper->setParent(parent); 
          delete temp; 
          temp = nullptr; 
        }else if (parent != nullptr && parent->getLeft() == temp){
          parent->setLeft(keeper); 
          keeper->setParent(parent); 
          delete temp; 
          temp = nullptr; 
        }else{
          keeper->setParent(nullptr); 
          root_ = keeper;
          delete temp; 
          temp = nullptr; 
        }
      }else{
        parent = temp->getParent(); 
        if (parent != nullptr && parent->getRight() == temp){
          parent->setRight(nullptr);
          delete temp; 
          temp = nullptr; 
        }else if (parent != nullptr && parent->getLeft() == temp){
          parent->setLeft(nullptr); 
          delete temp; 
          temp = nullptr; 
        }else{
          delete root_;
          root_ = nullptr; 
        }
        
      }
    }

}


template<class Key, class Value>
Node<Key, Value>* 
BinarySearchTree<Key, Value>::predecessor(Node<Key, Value>* current)
{ 
    if (current == nullptr){
      return nullptr;
    }
    Node<Key, Value>* temp; 
    if (current->getLeft() != nullptr){
      temp = current->getLeft(); 
      while (temp->getRight() != nullptr){
        temp = temp->getRight(); 
      }
      //now temp is predecessor
      return temp;
    }else{
      temp = current; 
      bool right_most_found = false; 
      while (right_most_found == false){
        if (temp->getParent()->getRight() == temp){
          right_most_found = true; 
        }else{
          temp = temp->getParent(); 
        }
      }
      return temp->getParent(); 
    }
    return nullptr; 
}


/**
* A method to remove all contents of the tree and
* reset the values in the tree for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
  traverse(root_); 
  root_ = nullptr; 
    // std::vector<Node<Key,Value> *> myvec; 
    // if (root_ == nullptr){
    //   return;
    // }
    // if (root_->getRight() == nullptr && root_->getLeft() == nullptr){
    //   delete root_;
    //   return; 
    // }
    // Node<Key,Value> *smallest_node = getSmallestNode();
    // Node<Key,Value> *next_node = successor(smallest_node);
    // myvec.push_back(smallest_node);
    // while (next_node != nullptr){
    //   smallest_node = next_node; 
    //   // Key k = smallest_node->getKey();
    //   next_node = successor(smallest_node); 
    //   myvec.push_back(smallest_node); 
    // }
    // for (size_t i = 0; i < myvec.size(); i++){
    //   if (myvec[i] != nullptr){
    //     delete myvec[i]; 
    //   }
    //   myvec[i] = nullptr; 
    // }
    // BinarySearchTree<Key,Value>::iterator it = begin();
    // if (it.current_ == nullptr){
    //   return;
    // }

    // for(; it != end(); ++it) {
    //     myvec.push_back(it.current_); 
    // }
    // for (size_t i = 0; i < myvec.size(); i++){
    //   delete myvec[i]; 
    // }
    // std::cout << "CLEAR FUNCTION\n";
    // std::cout << root_->getKey(); 
    // std::cout << root_->getRight()->getKey(); 
    // std::cout <<"CLEAR FUNCTION\n";
    // Node<Key,Value> *smallest_node = getSmallestNode();
    // std::cout << "Smallest Node Key: " << smallest_node->getKey() << "\n"; 
    // if (smallest_node == nullptr) return;
    // Node<Key,Value> *next_node = this->successor(smallest_node); 
    // std::cout << "PASSED?";
    // smallest_node->get
    // delete smallest_node; 
    // while(next_node != nullptr){
    //   smallest_node = next_node; 
    //   next_node = this->successor(smallest_node);
    //   delete smallest_node; 
    // }
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::traverse(Node<Key,Value> *next){
  if (next == nullptr){
    return; 
  }
  traverse(next->getLeft()); 
  traverse(next->getRight()); 
  delete next; 
}


/**
* A helper function to find the smallest node in the tree.
*/
template<typename Key, typename Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::getSmallestNode() const
{
    
    // BinarySearchTree<Key, Value>::iterator it(root_);
    Node<Key, Value>* smallest_node = root_; 
    if (root_ == nullptr){
      return nullptr; 
    }
    while (smallest_node->getLeft() != nullptr){
      smallest_node = smallest_node->getLeft(); 
    }
    return smallest_node; 
    // for (;it != nullptr; ++it){
    //   if (it.current_->getValue() < smallest){
    //     smallest = it.current_->getValue(); 
    //     smallest_node = it.current_; 
    //   }
    // }
    // return smallest_node; 
}

/**
* Helper function to find a node with given key, k and
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const
{
    // std::cout << "DAM";
    if (root_->getKey() == key){
      return root_; 
    }
    for (BinarySearchTree<Key, Value>::iterator it = this->begin();it != this->end(); ++it){
      if (it.current_->getItem().first == key){
        return it.current_;
      }
    }    
    return nullptr; 
}

/**
 * Return true iff the BST is balanced.
 */
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalanced()
{
    Node<Key,Value> *next = root_; 
    return balance(next); 
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::balance(Node<Key,Value> *next){
    if (next == nullptr) {
        return true;
    } else {
        int leftHeight = balance_traverse(next->getLeft());
        int rightHeight = balance_traverse(next->getRight());
        if (abs(leftHeight - rightHeight) <= 1) {
            return balance(next->getLeft()) && balance(next->getRight());
        } else {
            return false;
        }
    }
}



template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::balance_traverse(Node<Key,Value> *next){
  if (next == nullptr) return 0; 
  int leftHeight = balance_traverse(next->getLeft());
  int rightHeight = balance_traverse(next->getRight());
  return 1 + std::max(leftHeight, rightHeight);
}


// template<typename Key, typename Value>
// Node<Key, Value>* 
// BinarySearchTree<Key, Value>::successor(Node<Key, Value>* current)
// {

//     if (current == nullptr){
//       return nullptr;
//     }
//     // std::cout << "SUCCESSOR";
//     // std::cout << current->getKey(); 
//     // if (current->getRight() == nullptr){
//     //     std::cout << "DAM CALL";
//     // }
//     if (current->getRight() != nullptr){
//         // Key mykey = current->getRight()->getKey();
//         Node<Key,Value> * temp = current->getRight();
//         while (temp->getLeft() != nullptr){
//             temp = temp->getLeft(); 
//         }
//         // std::cout << "SUCCESSOR: " << successor->getKey();
//         return temp; 
//     }else{
//         Node<Key,Value> * successor = current->getParent();
//         if (successor->getParent() == nullptr){
//           return nullptr; 
//         }
//         while (successor->getParent()->getLeft() != successor){
//           if (successor == nullptr){
//             return nullptr; 
//           }
//           successor = successor->getParent();
          
//         }
//         // std::cout << "SUCCESSOR: " << successor->getParent()->getKey();
//         return successor->getParent(); 
//     }
// }



template<typename Key, typename Value>
Node<Key, Value>* 
BinarySearchTree<Key, Value>::successor(Node<Key, Value>* current)
{

    if (current == nullptr){
      return nullptr;
    }
    // std::cout << "SUCCESSOR";
    // std::cout << current->getKey(); 
    // if (current->getRight() == nullptr){
    //     std::cout << "DAM CALL";
    // }
    if (current->getRight() != nullptr){
        // Key mykey = current->getRight()->getKey();
        Node<Key,Value> * temp = current->getRight();
        while (temp->getLeft() != nullptr){
            temp = temp->getLeft(); 
        }
        // std::cout << "SUCCESSOR: " << successor->getKey();
        return temp; 
    }else{
        Node<Key,Value> * successor = current;
        if (successor->getParent() == nullptr){
          return nullptr; 
        }
        while (successor->getParent()->getLeft() != successor){
          if (successor == nullptr){
            return nullptr; 
          }
          successor = successor->getParent();
          if (successor == nullptr){
            return nullptr;
          }
          
          if (successor->getParent() == nullptr){
            return nullptr; 
          }
          
        }
        // std::cout << "SUCCESSOR: " << successor->getParent()->getKey();
        return successor->getParent(); 
    }
}




template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2)
{
    if((n1 == n2) || (n1 == NULL) || (n2 == NULL) ) {
        return;
    }
    Node<Key, Value>* n1p = n1->getParent();
    Node<Key, Value>* n1r = n1->getRight();
    Node<Key, Value>* n1lt = n1->getLeft();
    bool n1isLeft = false;
    if(n1p != NULL && (n1 == n1p->getLeft())) n1isLeft = true;
    Node<Key, Value>* n2p = n2->getParent();
    Node<Key, Value>* n2r = n2->getRight();
    Node<Key, Value>* n2lt = n2->getLeft();
    bool n2isLeft = false;
    if(n2p != NULL && (n2 == n2p->getLeft())) n2isLeft = true;


    Node<Key, Value>* temp;
    temp = n1->getParent();
    n1->setParent(n2->getParent());
    n2->setParent(temp);

    temp = n1->getLeft();
    n1->setLeft(n2->getLeft());
    n2->setLeft(temp);

    temp = n1->getRight();
    n1->setRight(n2->getRight());
    n2->setRight(temp);

    if( (n1r != NULL && n1r == n2) ) {
        n2->setRight(n1);
        n1->setParent(n2);
    }
    else if( n2r != NULL && n2r == n1) {
        n1->setRight(n2);
        n2->setParent(n1);

    }
    else if( n1lt != NULL && n1lt == n2) {
        n2->setLeft(n1);
        n1->setParent(n2);

    }
    else if( n2lt != NULL && n2lt == n1) {
        n1->setLeft(n2);
        n2->setParent(n1);

    }


    if(n1p != NULL && n1p != n2) {
        if(n1isLeft) n1p->setLeft(n2);
        else n1p->setRight(n2);
    }
    if(n1r != NULL && n1r != n2) {
        n1r->setParent(n2);
    }
    if(n1lt != NULL && n1lt != n2) {
        n1lt->setParent(n2);
    }

    if(n2p != NULL && n2p != n1) {
        if(n2isLeft) n2p->setLeft(n1);
        else n2p->setRight(n1);
    }
    if(n2r != NULL && n2r != n1) {
        n2r->setParent(n1);
    }
    if(n2lt != NULL && n2lt != n1) {
        n2lt->setParent(n1);
    }


    if(this->root_ == n1) {
        this->root_ = n2;
    }
    else if(this->root_ == n2) {
        this->root_ = n1;
    }

}

/**
 * Lastly, we are providing you with a print function,
   BinarySearchTree::printRoot().
   Just call it with a node to start printing at, e.g:
   this->printRoot(this->root_) // or any other node pointer

   It will print up to 5 levels of the tree rooted at the passed node,
   in ASCII graphics format.
   We hope it will make debugging easier!
  */

// include print function (in its own file because it's fairly long)
#include "print_bst.h"

/*
---------------------------------------------------
End implementations for the BinarySearchTree class.
---------------------------------------------------
*/

#endif
