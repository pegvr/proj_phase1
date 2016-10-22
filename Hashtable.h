/* 
 * File:   Hashtable.h
 * Author: angelique
 *
 * Created on October 17, 2016, 6:47 PM
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H
#include "LinkedList.h"

class Hashtable {
public:
    Hashtable(string temp, int k);
    Hashtable(const Hashtable& orig);
    virtual ~Hashtable();
    
    // Adds an item to the Hash Table.
    void insertPoint( Point * newPoint );
    
    // Deletes an Point by key from the Hash Table.
    // Returns true if the operation is successful.
    bool removePoint( string itemKey );
    
    // Returns an item from the Hash Table by key.
    // If the item isn't found, a null pointer is returned.
    Point * getPointByKey( string itemKey );
    
    // Display the contents of the Hash Table to console window.
    void printTable(string method);
    
    // Prints a histogram illustrating the Point distribution.
    void printHistogram();
    
    // Returns the number of locations in the Hash Table.
    int getLength();
    
    // Returns the number of Points in the Hash Table.
    int getNumberOfPoints();
    void InsertIntoHashtable(string temp, Hamming *HammingPoint, CosineSim *CosinePoint,Euclidean *EuclideanPoint);
private:
    // Array is a reference to an array of Linked Lists.
    string name;
    LinkedList * array;
    
    // Length is the size of the Hash Table array.
    int length;
    
    // Returns an array location for a given item key.
    int hash( string itemKey );
};