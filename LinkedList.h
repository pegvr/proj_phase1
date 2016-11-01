#ifndef LINKEDLIST_H
#define	LINKEDLIST_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Hamming.h"
#include "CosineSim.h"
#include "Euclidean.h"
#include <math.h>

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
    void Search(int radius, string temp,string item, int counter, int * Row, string method, ofstream& file);
    void printList(string method, int counter);
    string NN_Search(int L,int radius, string temp,string item,Euclidean *EuclideanPoint, int * Row, string method, int &distance);
    
    // Returns the length of the list.
    int getLength();
private:
    Point * head;
    
    // Length is the number of data nodes.
    int length;
};

#endif	/* LINKEDLIST_H */

