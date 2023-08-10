#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

template <typename T>
class CircularLinkedList 
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node(const T&);

    };
    Node* head;
    Node* tail;
    int size;

public:

    CircularLinkedList();
    CircularLinkedList(const CircularLinkedList&);
    ~CircularLinkedList();
    int GetSize();
    bool InList(const T&);
    void AddFront(const T&);
    void AddBack(const T&);
    void AddBeforeX(const T&, const T&);
    void AddAfterX(const T&, const T&);
    T GoThrough();
    void Remove(const T&);
    void Kiir();
};


#endif