/* 
 * File:   Hamming.cpp
 * Author: angelique
 * 
 * Created on October 17, 2016, 9:16 PM
 */

#include "Hamming.h"

Hamming::Hamming(string temp) 
{
    id = temp;
    length = id.size() - 1;
    cout << "item id = " << id << endl;
}

Hamming::Hamming(const Hamming& orig) {
}

Hamming::~Hamming() 
{
    cout << "hamming destruct 1" << endl;
}

string Hamming:: getId()
{
    return id;
}

string Hamming::ConstructGFunction(int L, int k)
{
    int i, x1, x2;
    /*char temp1[10];
    string temp;
    Hashtable **PointersToHashtable = new Hashtable*[L];  //Table which points to g1,g2,...,gl hashtables
    for(i = 0; i < L; i++)
    {       
        sprintf(temp1, "%d", i);        //Hashtable number
        temp = 'g' + temp1;
        PointersToHashtable[i] = new Hashtable (temp, k);
    }*/
    string g;
    for (i = 0; i < (k / 2); i++)
    {
        //pick uniformly k random numbers from 0 to 63
        int x1 = (rand() / (RAND_MAX + 1.0))*(id[id.size()-1] + 1);
        int x2 = (rand() / (RAND_MAX + 1.0))*(id[id.size()-1] + 1);
        g = g + id[x1] + id[x2];
        cout << "x1 = " << x1 << " and x2 = " << x2 << endl;
        cout << "g = " << g << endl;
        //g = "0010";
    }
    return g;
}
