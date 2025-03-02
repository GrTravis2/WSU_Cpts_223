#ifndef AVL_MAP_H
#define AVL_MAP_H

#include <iostream>
#include <assert.h>
#include <queue>
#include <array>

#include "avl_node.hpp"

typedef enum rotate {
    LL,
    RR,
    LR,
    RL
}ROTATE;
template <class K, class V>
class avl_map {

    class Iterator {

        private:
            avl_node<K, V>*& pNode;
            bool mFound;

        public:

            // constructor
            Iterator(avl_node<K, V>*& nodePtr); // basic init

            // destructor
            ~Iterator(); // do nothing

            // getters
            K& getKey() const;
            V& getValue() const;

            // public methods
            bool hasNext(const K& key); // returns true if iterator should continue
            void next(const K& key); // go to next level in tree based on key value


            /*
            // get next iterator, return nullptr if key not found
            void next(const K& key) {

                // check for leaf node -> if dead end stop recursive calls
                if (this->pNode != nullptr) {
                    // continue recursive call if key is not a match
                    if (this->pNode->mKey != key) { 
                        if (this->pNode->mKey < key) { // -> if key is less than node key go left
                            this->pNode = this->pNode->getLeftPtr();
                        } else {
                            this->pNode = this->pNode->getRightPtr(); // -> else go right
                        }
                    }
                }
            } */

    };

    private:
    avl_node<K, V>* mpRoot;
    
    // private methods
    void deleteTreeHelper(avl_node<K, V>* pTree);
    int getMaxHeight(avl_node<K, V>* pTree);
    int getMaxHeightHelper(avl_node<K, V>* pTree, int level);
    bool insertHelper(const K& key, const V& value, avl_node<K, V>* pTree);
    void balanceHelper(avl_node<K, V>* pParent, avl_node<K, V>* pChild);
    void rotate(avl_node<K, V>* pParent, avl_node<K, V>* pChild, ROTATE r);
    void rotateRoot(avl_node<K, V>* pChild, ROTATE r);
    bool eraseHelper(avl_node<K, V>* pTree, const K& key);
    avl_map<K, V>::Iterator findHelper(avl_node<K, V>* pTree, const K& key);

    public:

    // constructor
    avl_map();

    // destructor
    ~avl_map();

    // public methods
    bool empty(); // -> returns true if tree is empty
    void insert(const K& key, const V& value); // -> insert element and balance if needed
    void erase(const K& key); // -> remove element by key and balance if needed
    bool equals(const K* keys, const int& size); // -> compare keys and breadth first order against array of keys -> helpful for tests!
    void clear(); // -> clear contents of tree

    avl_map<K, V>::Iterator begin(); // -> get iterator starting at root of the tree
    avl_map<K, V>::Iterator find(const K& key); // -> find element in the tree by key, return iterator


};

// Iterator methods

// constructor
template <class K, class V>
avl_map<K, V>::Iterator::Iterator(avl_node<K, V>*& nodePtr) : pNode(nodePtr), mFound(false)  {};

// destructor
template <class K, class V>
avl_map<K, V>::Iterator::~Iterator() {} // do nothing

// getters
template <class K, class V>
K& avl_map<K, V>::Iterator::getKey() const {
    return pNode->getKey();
}

template <class K, class V>
V& avl_map<K, V>::Iterator::getValue() const {
    return pNode->getValue();
}

// public methods

// returns true if iterator can continue searching for next value
// returns false if iterator hits a leaf node or finds the key, if key is found iter mFound data member set to true
template <class K, class V>
bool avl_map<K, V>::Iterator::hasNext(const K& key) {
    bool ok = false;
    if (key < this->pNode->mKey) { // -> go left if less
        ok = (this->pNode->getLeftPtr() != nullptr);
    } else if (key > this->pNode->mKey) { // -> go right if greater
        ok = (this->pNode->getRightPtr() != nullptr);
    } else {
        this->mFound = true; // if the key is not less than or greater than, then it must be a match
    }

    return ok;
}

// go down next level based on key values, need to check if next can continue with hasNext()
template <class K, class V>
void avl_map<K, V>::Iterator::next(const K& key) {
    if (this->pNode->mKey < key) { // -> if key is less than node key go left
        this->pNode = this->pNode->getLeftPtr();
    } else {
        this->pNode = this->pNode->getRightPtr(); // -> else go right
    }
}

// constructor
template <class K, class V>
avl_map<K, V>::avl_map() {
    this->mpRoot = nullptr;
}

// destructor
template <class K, class V>
avl_map<K, V>::~avl_map() {
    this->deleteTreeHelper(this->mpRoot);
}

// private methods

// returns true if tree is empty
template <class K, class V>
bool avl_map<K, V>::empty() {
    return this->mpRoot == nullptr;
}

// helper method for destructor, delete tree is post order
template <class K, class V>
void avl_map<K, V>::deleteTreeHelper(avl_node<K, V>* pTree) {
    if (pTree != nullptr) {
        this->deleteTreeHelper(pTree->getLeftPtr());
        this->deleteTreeHelper(pTree->getRightPtr());
        delete pTree;
    }
}

// helper method to hide int paramater
template <class K, class V>
int avl_map<K, V>::getMaxHeightHelper(avl_node<K, V>* pTree, int level) {
    int left = -1; // set default values, overwrite if node/subtree is valid
    int right = -1;
    int current = -1;
    if (pTree != nullptr) { // in order traversal -> returns node level if not nullptr!
        left = getMaxHeightHelper(pTree->getLeftPtr(), level + 1);
        right = getMaxHeightHelper(pTree->getRightPtr(), level + 1);
        current = level;
    }

    return std::max({left, right, current}); // max guarantees that levels 0 or greater are returned
}

// get height of sub-tree pTree, returns -1 if sub-tree is empty
template <class K, class V>
int avl_map<K, V>::getMaxHeight(avl_node<K, V>* pTree) {
    return getMaxHeightHelper(pTree, 0);
}

// public methods
template <class K, class V>
void avl_map<K, V>::insert(const K& key, const V& value) {
    if (this->mpRoot == nullptr) { // insert on empty tree
        this->mpRoot = new avl_node<K, V>(key, value);
        assert(this->mpRoot != nullptr); // crash if heap alloc fails
    } else { // tree is not empty, traverse and insert
        
        this->insertHelper(key, value, this->mpRoot);
    }
    // after insert check if mpRoot needs balancing since insert only checks subtree balance
    if (mpRoot != nullptr && std::abs(mpRoot->getBalanceFactor()) > 1) {
        this->balanceHelper(mpRoot, mpRoot);
    }

}

template <class K, class V>
bool avl_map<K, V>::insertHelper(const K& key, const V& value, avl_node<K, V>* pTree) {
    bool success = false;
    if (pTree != nullptr) { // check for dead end

        if (pTree->getKey() != key) { // check for duplicates

            if (key < pTree->getKey()) { // check if traverse should go left

                if (pTree->getLeftPtr() == nullptr) { // insert here if pTree is a leaf node
                    avl_node<K, V>* pNew = new avl_node<K, V>(key, value);
                    if (pNew != nullptr) { // verify that pNew successfully allocated before insert
                        pTree->setLeftPtr(pNew);
                        success = true;
                    }
                } else { // this is not the leaf node, try on next level
                    success = insertHelper(key, value, pTree->getLeftPtr());
                }
            } else {
                if (pTree->getRightPtr() == nullptr) { // insert here if pTree is a leaf node
                    avl_node<K, V>* pNew = new avl_node<K, V>(key, value);
                    if (pNew != nullptr) { // verify that pNew successfully allocated before insert
                        pTree->setRightPtr(pNew);
                        success = true;
                    }
                } else { // this is not the leaf node, try on next level
                    success = insertHelper(key, value, pTree->getRightPtr());
                }
            }

            if (success) { // node was inserted, check if rebalance needed then rebalance

                // check left/right child for balance -> call balanceHelper if needed which handles rotation cases
                // note that I used if else if under the assumption that the insert will only need to happen on one
                // subtree since insert happens on one subtree, which saves some conditional checks :)
                if (pTree->getLeftPtr() != nullptr && std::abs(pTree->getLeftPtr()->getBalanceFactor()) > 1) {
                    this->balanceHelper(pTree, pTree->getLeftPtr());
                } else if (pTree->getRightPtr() != nullptr && std::abs(pTree->getRightPtr()->getBalanceFactor()) > 1){
                    this->balanceHelper(pTree, pTree->getRightPtr());
                }

                // compute and update this nodes balance factor
                int bf = this->getMaxHeight(pTree->getRightPtr()) - this->getMaxHeight(pTree->getLeftPtr());
                pTree->setBalanceFactor(bf);
            }
        }
    }

    return success;
}

// Check rotation case for pChild, balance subtree, and update pChild balance factor
template <class K, class V>
void avl_map<K, V>::balanceHelper(avl_node<K, V>* pParent, avl_node<K, V>* pChild) {
    ROTATE r;

    // if balance helper is called then pChild is unbalanced -> check for rotation cases
    if (pChild->getBalanceFactor() < -1) { // subtree is left heavy

        // if left subtree is left heavy LL case else LR case
        r = (pChild->getLeftPtr()->getBalanceFactor() < 0) ? LL : LR;

    } else { // subtree must be right heavy

        // if right subtree is left heavy RL case else RR case
        r = (pChild->getRightPtr()->getBalanceFactor() < 0) ? RL : RR;
    }
    if (pChild == this-> mpRoot) { 
        this->rotateRoot(mpRoot, r); 
    } else {
        this->rotate(pParent, pChild, r);
    }
    
}

template <class K, class V>
void avl_map<K, V>::rotate(avl_node<K, V>* pParent, avl_node<K, V>* pChild, ROTATE r) {

    avl_node<K, V>* buffer = nullptr;

    switch (r) {
        case LL: // -> do right rotation
            pParent->setLeftPtr(pChild->getLeftPtr());
            pChild->setLeftPtr(pParent->getLeftPtr()->getRightPtr());
            pParent->getLeftPtr()->setRightPtr(pChild);
            break;
        case LR:
            // rotate to get LL case then rotate again to balance
            buffer = pChild->getLeftPtr()->getRightPtr();
            pChild->getLeftPtr()->setRightPtr(buffer->getLeftPtr());
            buffer->setLeftPtr(pChild->getLeftPtr());
            pChild->setLeftPtr(buffer);

            // do a right rotation
            pParent->setLeftPtr(pChild->getLeftPtr());
            pChild->setLeftPtr(pParent->getLeftPtr()->getRightPtr());
            pParent->getLeftPtr()->setRightPtr(pChild);

            break;
        case RL:
            // rotate to get LL case then rotate again to balance
            buffer = pChild->getRightPtr()->getLeftPtr();
            pChild->getRightPtr()->setLeftPtr(buffer->getRightPtr());
            buffer->setRightPtr(pChild->getRightPtr());
            pChild->setRightPtr(buffer);

            // do a right rotation
            pParent->setRightPtr(pChild->getRightPtr());
            pChild->setRightPtr(pParent->getRightPtr()->getLeftPtr());
            pParent->getRightPtr()->setLeftPtr(pChild);

            break;
        case RR: // -> left rotation!
            pParent->setRightPtr(pChild->getRightPtr());
            pChild->setRightPtr(pParent->getRightPtr()->getLeftPtr());
            pParent->getRightPtr()->setLeftPtr(pChild);
            break;
        default:
            assert(false); // if you get here I want to know how
    }
}

template <class K, class V>
void avl_map<K, V>::rotateRoot(avl_node<K, V>* pChild, ROTATE r) {
    
    avl_node<K, V>* buffer = nullptr;

    switch (r) {
        case LL: // -> do right rotation
            mpRoot = pChild->getLeftPtr();
            pChild->setLeftPtr(mpRoot->getRightPtr());
            mpRoot->setRightPtr(pChild);
            break;
        case LR:
            // rotate to get LL case then rotate again to balance
            buffer = pChild->getLeftPtr()->getRightPtr();
            pChild->getLeftPtr()->setRightPtr(buffer->getLeftPtr());
            buffer->setLeftPtr(pChild->getLeftPtr());
            pChild->setLeftPtr(buffer);

            // do a right rotation
            mpRoot = pChild->getLeftPtr();
            pChild->setLeftPtr(mpRoot->getRightPtr());
            mpRoot->setRightPtr(pChild);

            break;
        case RL:
            // rotate to get LL case then rotate again to balance
            buffer = pChild->getRightPtr()->getLeftPtr();
            pChild->getRightPtr()->setLeftPtr(buffer->getRightPtr());
            buffer->setRightPtr(pChild->getRightPtr());
            pChild->setRightPtr(buffer);

            // do a left rotation
            mpRoot = pChild->getRightPtr();
            pChild->setRightPtr(mpRoot->getLeftPtr());
            mpRoot->setLeftPtr(pChild);

            break;
        case RR: // -> left rotation!
            mpRoot = pChild->getRightPtr();
            pChild->setRightPtr(mpRoot->getLeftPtr());
            mpRoot->setLeftPtr(pChild);
            break;
        default:
            assert(false); // if you get here I want to know how
    }
}

template <class K, class V>
void avl_map<K, V>::erase(const K& key) {

    if (mpRoot->getKey() == key) {
        // key match at the root node! -> special case!
        // set the rightmost node of the left subtree as new root
        // to guarantee ordering is still valid
        avl_node<K, V>* pNode = mpRoot->getLeftPtr();
        avl_node<K, V>* buffer = mpRoot;

        // step until pNode is the rightmost node of the left subtree
        // and buffer points at the node above pNode
        while (pNode->getRightPtr() != nullptr) {
            buffer = pNode;
            pNode = pNode->getRightPtr();
        }
        buffer->setRightPtr(nullptr); // cut pNode from tree and point buffer back at root
        buffer = mpRoot;

        // insert pNode in place of old root, update root, and then delete old root
        pNode->setLeftPtr(mpRoot->getLeftPtr());
        pNode->setRightPtr(mpRoot->getRightPtr());
        mpRoot = pNode;
        delete buffer;

    } else {
        this->eraseHelper(mpRoot, key);
    }
    
}

template <class K, class V>
bool avl_map<K, V>::eraseHelper(avl_node<K, V>* pTree, const K& key) {

    bool success = false;
    
    if (pTree != nullptr) { // check for dead end

        bool left = (pTree->getKey() < key)? true : false;
        avl_node<K, V>* pNext = (left) ? pTree->getLeftPtr() : pTree->getRightPtr();

        if (pNext->getKey() != key) { // key not found, search another level
            
            success = this->eraseHelper(pNext, key);

        } else { // key found!
            avl_node<K, V>* pNode = nullptr;
            avl_node<K, V>* buffer = pNext;
            if (left) {
                pNode = pNext->getRightPtr(); // start in left subtree of node to be deleted

                // advance until pNode is at rightmost leaf node and buffer is above it
                while (pNode->getRightPtr() != nullptr) {
                    buffer = pNode;
                    pNode = pNode->getRightPtr();
                }

                if (buffer == pNext) {
                    buffer->setLeftPtr(pNode->getLeftPtr());
                } else {
                    buffer->setRightPtr(nullptr);
                }
                buffer = pNext.
                pNode.se
            }
        }

    }

    return success;
}

template <class K, class V>
typename avl_map<K, V>::Iterator avl_map<K, V>::begin() {
    return avl_map<K, V>::Iterator(this->mpRoot);
}

// compare keys in breadth first order against array of keys
template <class K, class V>
bool avl_map<K, V>::equals(const K* keys, const int& size) { 
    std::queue<avl_node<K, V>*> q;
    avl_node<K, V>* pCurrent = nullptr;
    int i = 0;
    bool ok = false;

    q.push(this->mpRoot);

    while (!q.empty() && i < size) {
        pCurrent = q.front(); // pull out front node and compare key against expected key
        if (pCurrent->getKey() != keys[i++]) { break; }

        if (pCurrent->getLeftPtr() != nullptr) { q.push(pCurrent->getLeftPtr()); }   // enqueue left, then right
        if (pCurrent->getRightPtr() != nullptr) { q.push(pCurrent->getRightPtr()); } // for BFS search

        q.pop(); // delete node pCurrent is pointing to
    }
    if (q.empty() && i == size) { ok = true; } // if we compared the whole tree and array then true

    return ok;
}

template <class K, class V>
void avl_map<K, V>::clear() {
    this->deleteTreeHelper(mpRoot);
    this->mpRoot = nullptr;
}

// returns iter pointing to found node or nullptr if not found!
template <class K, class V>
typename avl_map<K, V>::Iterator avl_map<K, V>::find(const K& key) {
    avl_map<K, V>::Iterator iter = this->begin();

    // advance iter, will stop at nullptr or if key is found
    while (iter.hasNext(key)) { iter.next(key); }

    return iter;
}




#endif