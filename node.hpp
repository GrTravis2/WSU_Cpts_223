#ifndef NODE_HPP
#define NODE_HPP


template <class T>
class node {
    private:
        T mData;
        node* pNext;

    public:
        // constructor
        node(const T& newData);

        // destructor
        ~node();

        //getters
        T getData();
        node* getNextPtr();

        //setters
        void setData(T& newData);
        void setNextPtr(node* newNextPtr);

};

template <class T>
node<T>::node(const T& newData) {
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
    return this->mData;
}

template <class T>
node<T>* node<T>::getNextPtr() {
    return this->pNext;
}

// setters
template <class T>
void node<T>::setData(T& newData) {
    this->mData = newData;
}

template <class T>
void node<T>::setNextPtr(node* newNextPtr) {
    this->pNext = newNextPtr;
}

#endif