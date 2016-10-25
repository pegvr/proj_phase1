/* 
 * File:   Hashtable.cpp
 * Author: angelique
 * 
 * Created on October 17, 2016, 6:47 PM
 */

#include "Hashtable.h"
#include "Hamming.h"
#include <math.h>


Hashtable::Hashtable(string temp, int k, int tablesize) 
{
    name = temp;
    if (tablesize == 0) length = pow(2.0, k);
    else length = tablesize / 16;
    cout << "length " << length << endl;
    array = new LinkedList[ length ];
}

Hashtable::Hashtable(const Hashtable& orig) {
}

Hashtable::~Hashtable() 
{
    //cout << "hashtable destruct 1" << endl;
    delete [] array;
   // cout << "hashtable destruct 2" << endl;
}

// Returns an array location for a given item key.
int Hashtable::hash( string itemKey )
{
    int value = 0;
    for (int i = 0; i < itemKey.length(); i++)
        value += itemKey[i];
    return (itemKey.length() * value) % length;
}
int Hashtable::getLength()
{
    return length;
}
// Adds an item to the Hash Table.
void Hashtable::insertPoint( Point * newPoint )
{
    //int index = hash( newPoint -> key );
    //array[ index ].insertPoint( newPoint );
}

void Hashtable::InsertIntoHashtable(string temp, Hamming *HammingPoint, CosineSim *CosinePoint,Euclidean *EuclideanPoint, int fi)
{    
    
    //cout << "1 " << temp << endl;
    if (fi == 0)
    {
        const char *point = temp.c_str();
        int ind = strtol(point, NULL, 2);
        cout << "temp = " << temp << "index = " << ind << endl;
        array[ind].insertPoint(HammingPoint, CosinePoint, EuclideanPoint);
    }
    else
    { int ind = fi;
    //cout << "3" << endl;
        array[ind].insertPoint(HammingPoint, CosinePoint, EuclideanPoint);}
    //array[index].printList();
    //cout << "4" << endl;
}

// Deletes an Point by key from the Hash Table.
// Returns true if the operation is successful.
/*bool Hashtable::removePoint( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].removePoint( itemKey );
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
Point * Hashtable::getPointByKey( string itemKey )
{
    int index = hash( itemKey );
    return array[index].getPoint( itemKey );
}*/

// Display the contents of the Hash Table to console window.
void Hashtable::printTable(string method)
{
    //cout << "print table 1" << endl;
    cout << length;
    //cout << "print table 2" << endl;
    cout << "\nHash Table:\n";
    
    for (int i = 0; i < length; i++)
    {
        //cout << "print table 3" << endl;
        cout << "Bucket " << i << ": ";
        array[i].printList(method);
        //cout << "print table 4" << endl;
    }
}
