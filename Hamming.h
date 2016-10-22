/* 
 * File:   Hamming.h
 * Author: angelique
 *
 * Created on October 17, 2016, 9:16 PM
 */

#ifndef HAMMING_H
#define	HAMMING_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Hamming {
public:
    Hamming(string temp);
    Hamming(const Hamming& orig);
    virtual ~Hamming();
    string ConstructGFunction(int L, int k);
    string getId();
private:
    string id;
    int length;
};


#endif	/* HAMMING_H */

