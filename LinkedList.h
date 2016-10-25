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
    int *row;
    Point * next;
    Point()
    {
        hamming_key = NULL;
        euclidean_key = NULL;
        cosine_key = NULL;
        row = NULL;
        next = NULL; 
    };
    Point(Hamming *HammingPoint, CosineSim *CosinePoint,Euclidean *EuclideanPoint, int *Row)
    {
        //cout << "!!!!" << endl;
        //cout << "point " << newPoint->getId() << endl;
        //key = newPoint; 

        hamming_key = HammingPoint;
        euclidean_key = EuclideanPoint;
        cosine_key = CosinePoint;
        row = Row;
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
    void insertPoint( Hamming * newPoint,CosineSim *CosinePoint,Euclidean *EuclideanPoint, int * Row);
    
    void printList(string method, int counter);
    
    // Returns the length of the list.
    int getLength();
private:
    Point * head;
    
    // Length is the number of data nodes.
    int length;
};
#endif	/* LINKEDLIST_H */



