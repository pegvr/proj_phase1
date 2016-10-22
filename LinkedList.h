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
#include "CosineSim.h"
#include "Euclidean.h"

struct Point
{
    Hamming *hamming_key;
    Euclidean *euclidean_key;
    CosineSim *cosine_key;
    Point * next;
    Point(){};
    Point(Hamming *HammingPoint, CosineSim *CosinePoint,Euclidean *EuclideanPoint)
    {
        //cout << "!!!!" << endl;
        //cout << "point " << newPoint->getId() << endl;
        //key = newPoint; 

        hamming_key = HammingPoint;
        euclidean_key = EuclideanPoint;
        cosine_key = CosinePoint;
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
    void insertPoint( Hamming * newPoint,CosineSim *CosinePoint,Euclidean *EuclideanPoint);
    
    // Removes an item from the list by item key.
    // Returns true if the operation is successful.
    //bool removePoint( string itemKey );
    
    // Searches for an item by its key.
    // Returns a reference to first match.
    // Returns a NULL pointer if no match is found.
    //Point * getPoint( string itemKey );
    
    // Displays list contents to the console window.
    void printList(string method);
    
    // Returns the length of the list.
    int getLength();
private:
    Point * head;
    
    // Length is the number of data nodes.
    int length;
};
#endif	/* LINKEDLIST_H */



