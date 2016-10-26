/* 
 * File:   LinkedList.cpp
 * Author: angelique
 * 
 * Created on October 17, 2016, 6:50 PM
 */

#include "LinkedList.h"

LinkedList::LinkedList() 
{
    head = new Point;
    head -> next = NULL;
    length = 0;
}

LinkedList::LinkedList(const LinkedList& orig) {
}

int i=0; 

LinkedList::~LinkedList() 
{
    //cout << "linked list destruct 1     " << i << endl;
    Point * p = head;
    //cout << "linked list destruct 2" << endl;
    Point * q = head;
    //cout << "linked list destruct 3" << endl;
    while (q != NULL)
    {
       // cout << "linked list destruct 4" << endl;
        p = q;
        //cout << "linked list destruct 5" << endl;
        q = p -> next;
        //cout << "linked list destruct 6" << endl;
        if (q != NULL) delete p;
       // cout << "linked list destruct 7" << endl;
    }
    i++;
    //cout << "linked list destruct 8" << endl;
}

// Inserts an item at the end of the list.
void LinkedList::insertPoint( Hamming * HammingPoint,CosineSim *CosinePoint,Euclidean *EuclideanPoint, int * Row)
{
    //cout << "linked list insert id = " << CosinePoint->getId()<< endl;
    Point *temp = new Point(HammingPoint, CosinePoint, EuclideanPoint, Row);
    //cout << "linked list 1" << endl;
    if (!head -> next)
    {
        //cout << "linked list 2" << endl;
        head -> next = temp;
        //cout << "linked list 3" << endl;
        length++;
        return;
    }
    temp->next = head->next;
    head->next = temp;
    length++;
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
/*bool LinkedList::removePoint( string itemKey )
{
    if (!head -> next) return false;
    Point * p = head;
    Point * q = head;
    while (q)
    {
        if (q -> key == itemKey)
        {
            p -> next = q -> next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}*/

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
/*Point * LinkedList::getPoint( string itemKey )
{
    Point * p = head;
    Point * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p -> key == itemKey))
            return p;
        q = p -> next;
    }
    return NULL;
}*/

// Displays list contents to the console window.
void LinkedList::printList(string method, int counter)
{
    //cout << "print 1" << endl;
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    //cout << "print 2" << endl;
    Point * p = head->next;
    //cout << "print 3" << endl;
    cout << "\n{ ";
    while (p)
    {
        //cout << "print 4" << endl;
        if (method == "@metric_space hamming")
            cout << p->hamming_key->getId();
        else if (method == "@metric_space cosine")
            cout << p->cosine_key->getId();
        else if (method == "@metric_space euclidean")
            cout << p -> euclidean_key->getId();
        else
            for (int i = 0; i < counter; i++)
                cout << p->row[i]<< "\t";
        //cout << "print 5" << endl;
        if (p -> next) cout << ", ";
        else break;
        //cout << "print 6" << endl;
        p = p->next;
        //cout << "print 7" << endl;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}
