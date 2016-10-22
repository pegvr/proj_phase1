/* 
 * File:   LinkedList.h
 * Author: angelique
 *
 * Created on October 17, 2016, 6:50 PM
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <iostream>
#include <string>
#include "Hamming.h"

using namespace std;


struct Point
{
    Hamming *key;
    Point * next;
    Point(){};
    Point(Hamming * newPoint)
    {
        //cout << "!!!!" << endl;
        //cout << "point " << newPoint->getId() << endl;
        key = newPoint; 
        next = NULL; 
        //cout << "!!!!!!!!!!" << key->getId() << endl;
    };
};

class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList& orig);
    virtual ~LinkedList();
    // Inserts an item at the end of the list.
    void insertPoint( Hamming * newPoint );
    
    // Removes an item from the list by item key.
    // Returns true if the operation is successful.
    //bool removePoint( string itemKey );
    
    // Searches for an item by its key.
    // Returns a reference to first match.
    // Returns a NULL pointer if no match is found.
    //Point * getPoint( string itemKey );
    
    // Displays list contents to the console window.
    void printList();
    
    // Returns the length of the list.
    int getLength();
private:
    Point * head;
    
    // Length is the number of data nodes.
    int length;
};

#endif	/* LINKEDLIST_H */



