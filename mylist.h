#pragma once
#include <iostream>

#pragma once
#include <iostream>

template <class T>
class myList
{
private:

    typedef struct node
    {
        T data;
        node* next;
        node* prev;
    } *nodePtr;

    //typedef struct node* nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    //These are for reversing the list
    nodePtr next;
    nodePtr prev;
public:

    myList();
    void append(const T& addData);
    void erase(const T& delData);
    void printList();
    void reverse();
};

template <class T>
myList<T>::myList()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

template <class T>
void myList<T>::append(const T& addData)
{
    nodePtr n = new node;			//nodePtr points to new node
    n->next = NULL;
    n->data = addData;

    if (head != NULL)				//if list already has elements
    {
        curr = head;
        while (curr->next != NULL)	//traverse list to the end
        {
            curr = curr->next;
        }
        curr->next = n;				//the end elements nex pointer is now to n
    }

    else
    {
        head = n;					//if list is empty then node added is the head
    }
}

template <class T>
void myList<T>::erase(const T& delData)
{
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while (curr != NULL && curr->data != delData)
    {
        temp = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        std::cout << delData << " not in the list\n";
        delete delPtr;
    }

    else
    {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if (delPtr == head)
        {
            head = head->next;
            temp = NULL;
        }
        delete delPtr;
        std::cout << "The value " << delData << " was erased\n";
    }
}

template <class T>
void myList<T>::printList()
{
    curr = head;
    while (curr != NULL)
    {
        std::cout << curr->data << " \n";
        curr = curr->next;
    }
}

template <class T>
void myList<T>::reverse()
{
    curr = head;
    prev = NULL;
    temp = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}