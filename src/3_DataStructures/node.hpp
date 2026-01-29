#ifndef NODE_HPP
#define NODE_HPP

//Template
template <typename N>
class Node {
    public:
        explicit Node(const N& newValue)                //Prevents implicit conversions
            : value(newValue) {}

        N& getValue();                                      //Returns a reference to the value to avoid copying and to protect it
        void setValue(const N& newValue);

        Node<N>* getNext() const;                       //Returns the address of the next node
        Node<N>* getPrev() const;

        void setNext(Node<N>* newNode);                 //Connects the pointers together
        void setPrev(Node<N>* newNode);

    private:
        N value;
        Node<N>* nextNode = nullptr; 
        Node<N>* prevNode = nullptr; 
};

template <typename N>
N& Node<N>::getValue(){
    return value;
}

template <typename N>
void Node<N>::setValue(const N &newValue) {
    value = newValue;
}

template <typename N>
Node<N>* Node<N>::getNext() const {
    return nextNode;
}

template <typename N>
Node<N>* Node<N>::getPrev() const {
    return prevNode;
}

template <typename N>
void Node<N>::setNext(Node<N>* newNode) {
    nextNode = newNode;
}

template <typename N>
void Node<N>::setPrev(Node<N>* newNode) {
    prevNode = newNode;
}

#endif