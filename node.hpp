#ifndef NODE_HPP
#define NODE_HPP


template <class T>
class node {
    private:
        T mData;
        node* pNext;

    public:
        // constructor
        node(T& newData);

        // destructor
        ~node();

        //getters
        T getData();
        node* getNextPtr();

        //setters
        bool setData(T& newData);
        bool setNextPtr(node* newNextPtr);

};

template <class T>
node<T>::node(T& newData) {
    this->mData = newData;
    this->pNext = nullptr;
}

template <class T>
node<T>::~node() {
    // do nothing, no obj on the heap :)
}


// getters
template <class T>
T node<T>::getData() {
    return this->mData
}

template <class T>
node<T>* node<T>::getNextPtr() {
    return this->pNext
}

// setters
template <class T>
bool node<T>::setData(T& newData) {
    this->mData = newData;
}

template <class T>
bool node<T>::setNextPtr(node* newNextPtr) {
    this->pNext = newNextPtr;
}

#endif