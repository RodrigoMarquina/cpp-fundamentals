#include <iostream>
#include <string>

#include "node.hpp"

using namespace std;

template <typename N>
class LinkedList {
    public:
        LinkedList() = default;                 //Generates the default constructor 

        template <typename... Values>
        LinkedList(Values... values){           //Constructor               
            (appendEnd(values), ...);           //Fold expression
        }

        LinkedList(const LinkedList& other){    //Creates new nodes if the list is coppied 
            Node<N>* current = other.head;      //LinkedList<int> a(1,2,3);
            while(current){                     //LinkedList<int> b = a;
                appendEnd(current->getValue());
                current = current->getNext();
            }
        }

        LinkedList& operator = (const LinkedList& other){
            if(this == &other) return *this;    //Prevents a = a;
            
            clear();

            Node<N>* current = other.head;
            while(current){
                appendEnd(current->getValue());
                current = current->getNext();
            }
            return *this;
        }

        ~LinkedList() {                         //Destroyer to avoid memory leak
            clear();
        }

        void appendStart(const N& newValue);
        void appendEnd(const N& newValue);
        void insertAtIndex(int index, const N& newValue);
        void setValueAtIndex(int index, const N& newValue);
        void popStart();
        void popEnd(); 
        void removeIndex(int index);
        void removeValue(const N& value);
        void searchValue(const N& value) const;
        N& getValueAtIndex(int index);            
        int sizeLinkedList() const;
        void printLinkedList() const;
        
    private:
        Node<N>* head = nullptr;
        Node<N>* tail = nullptr;
        int size = 0;

        void clear() {
            Node<N>* current = head;
            while(current) {
                Node<N>* next = current->getNext();
                delete current;
                current = next;
            }
            head = tail = nullptr;
            size = 0;
        } 
};

template <typename N>
void LinkedList<N>::appendStart(const N& newValue){
    Node <N>* node = new Node<N>(newValue);
    if(!head){
        head = tail = node;
    } else{
        head->setPrev(node);
        node->setNext(head);
        head = node;
    }
    size++;
}

template <typename N>
void LinkedList<N>::appendEnd(const N& newValue){
    Node <N>* node = new Node<N>(newValue);
    if(!head){
        head = tail = node;
    } else{
        tail->setNext(node);
        node->setPrev(tail);
        tail = node;
    }
    size++;
}

template <typename N>
void LinkedList<N>::insertAtIndex(int index, const N& newValue){
    if(index < 0 || index > size){
        throw out_of_range("Index out of range!");
    }

    if(index == 0){
        appendStart(newValue);
        return;
    } 

    if(index == size){
        appendEnd(newValue);
        return;
    }

    Node <N>* current = head;
    for(int i = 0; i < index; i++){
        current = current->getNext();
    }

    Node <N>* node = new Node<N>(newValue);
    Node <N>* prev = current->getPrev();

    node->setPrev(prev);
    node->setNext(current);
    prev->setNext(node);
    current->setPrev(node);

    size++;
} 

template <typename N>
void LinkedList<N>::setValueAtIndex(int index, const N& newValue){
    if(index < 0 || index >= size){
        throw out_of_range("Index out of range!");
    }

    Node <N>* current = head;
    for(int i = 0; i < index; i++){
        current = current->getNext();
    }

    current->setValue(newValue);
}

template <typename N>
void LinkedList<N>::popStart(){
    if(head){
        Node <N>* current = head;
        head = head->getNext();

        if(head){
            head->setPrev(nullptr);
        } else{
            tail = nullptr;
        }

        delete current;
        size--;
    }
}

template <typename N>
void LinkedList<N>::popEnd(){
    if(head){
        Node<N>* current = tail;
        tail = tail->getPrev();

        if(tail){
            tail->setNext(nullptr);
        } else{
            head = nullptr;
        }

        delete current;
        size--;
    }
}

template <typename N>
void LinkedList<N>::removeIndex(int index){
    if(index < 0 || index >= size){
        throw out_of_range("Index out of range!");
    }
    if(index == 0){
        popStart();
        return;
    }
    if(index == size-1){
        popEnd();
        return;
    }

    Node<N>* current = head;
    for(int i = 0; i < index; i++){
        current = current->getNext();
    }

    Node<N>* next = current->getNext();
    Node<N>* prev = current->getPrev();

    next->setPrev(prev);
    prev->setNext(next);

    delete current;
    size--;
}

template <typename N>
void LinkedList<N>::removeValue(const N& value){
    Node<N>* current = head;

    while(current){
        Node<N>* next = current->getNext();
        
        if(current->getValue() == value){
            if(current == head){
                popStart();
            } else if(current == tail){
                popEnd();
            } else{
                Node<N>* prev = current->getPrev();

                next->setPrev(prev);
                prev->setNext(next);

                delete current;
                size--;
            }
        }
        current = next;
    }
}

template <typename N>
void LinkedList<N>::searchValue(const N& value) const {
    Node<N>* current = head;
    int i = 0; 
    while(current){
        if(current->getValue() == value){
            cout << "Found value " << current->getValue() <<" in index: " << i << endl;
        }
        current = current->getNext();
        i++;
    }
}

template <typename N>
N& LinkedList<N>::getValueAtIndex(int index){
    if(index < 0 || index >= size){
        throw out_of_range("Index out of range!");
    }

    Node<N>* current = head;

    for(int i = 0; i < index; i++){
        current = current->getNext();
    }

    return current->getValue();
}

template <typename N>
int LinkedList<N>::sizeLinkedList() const {
    return size;
}

template <typename N>
void LinkedList<N>::printLinkedList() const {
    if(head){
        for(Node <N>* current = head; current; current = current->getNext()){
            cout << current->getValue();
            if(current->getNext()) cout << " <-> ";
        }
        cout << endl;
    }
}

void runLinkedList() {
    
    LinkedList<int> list1(1,2,3);

    //list1.appendStart(0);
    //list1.printLinkedList();
    //list1.insertAtIndex(0, 4);
    //list1.setValueAtIndex(3, 9);
    //list1.removeIndex(5);
    //list1.popStart();

    LinkedList<int> list2(1,4,6,4,6,5,4);

    //list2.popEnd();

    //list2.removeIndex(0);

    //list2.removeValue(4);

    //cout << list2.getValueAtIndex(4) << endl;

    list2.searchValue(4);

    list2.printLinkedList();

    //cout << list1.sizeLinkedList() << endl;

}


/*
- new Node<N>(newValue)

Allocates raw memory on the heap

Constructs a Node<N> object in that memory

Initializes value with newValue

Returns the address of that object

- Node<N>* node = ...

node is a pointer

It stores the address of the newly created Node<N>
*/