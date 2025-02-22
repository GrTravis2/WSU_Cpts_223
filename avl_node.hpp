#ifndef AVL_NODE_H
#define AVL_NODE_H

template <class K, class V>
class avl_node {

    private:
    K mKey;
    V mData;
    avl_node<K, V>* mpLeft;
    avl_node<K, V>* mpRight;
    int mBalanceFactor;

    // private methods

    public:

    // constructor
    avl_node(const K& key, const V& data, avl_node<K, V>* left, avl_node<K, V>* right);

    // destructor
    ~avl_node();

    // getters
    avl_node<K, V>* getLeftPtr();
    avl_node<K, V>* getRightPtr();
    int getBalanceFactor();

    // setters
    void setLeftPtr(avl_node<K, V>* newLeftPtr);
    void setRightPtr(avl_node<K, V>* newRightPtr);
    void setBalanceFactor(const int& newBF);
    

    // public methods

    // friends

    // class K must have <, >, != operators overloaded to use in avl_node!
    friend bool operator<(const avl_node<K, V>& lhs, const avl_node<K, V>& rhs);
    friend bool operator>(const avl_node<K, V>& lhs, const avl_node<K, V>& rhs);
    friend bool operator!=(const avl_node<K, V>& lhs, const avl_node<K, V>& rhs);

};

// constructor
template <class K, class V>
avl_node<K, V>::avl_node(
    const K& key, 
    const V& data, 
    avl_node<K, V>* left, 
    avl_node<K, V>* right) : 
    mpLeft(left),
    mpRight(right),
    mBalanceFactor(-1) {};

// destructor
template <class K, class V>
avl_node<K, V>::~avl_node() {} // -> do nothing!

// getters
template <class K, class V>
avl_node<K, V>* avl_node<K, V>::getLeftPtr() {
    return this->mpLeft;
}

template <class K, class V>
avl_node<K, V>* avl_node<K, V>::getRightPtr() {
    return this->mpRight
}

template <class K, class V>
int avl_node<K, V>::getBalanceFactor() {
    return this->mBalanceFactor;
}

// setters
template <class K, class V>
void avl_node<K, V>::setLeftPtr(avl_node<K, V>* newLeftPtr) {
    this->mpLeft = newLeftPtr;
}

template <class K, class V>
void avl_node<K, V>::setRightPtr(avl_node<K, V>* newRightPtr) {
    this->mpRight = newRightPtr;
}

template <class K, class V>
void avl_node<K, V>::setBalanceFactor(const int& newBF) {
    this->mBalanceFactor = newBF;
}


// public methods

// friends
template <class K, class V>
bool operator<(const avl_node<K, V>& lhs, const avl_node<K, V>& rhs) {
    return lhs.mKey < rhs.mKey;
}

template <class K, class V>
bool operator>(const avl_node<K, V>& lhs, const avl_node<K, V>& rhs) {
    return lhs.mKey > rhs.mKey;
}

template <class K, class V>
bool operator!=(const avl_node<K, V>& lhs, const avl_node<K, V>& rhs) {
    return lhs.mKey != rhs.mKey;
}

#endif