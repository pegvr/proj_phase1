/* 
 * File:   Euclidean.h
 * Author: angelique
 *
 * Created on October 21, 2016, 12:11 AM
 */

#ifndef EUCLIDEAN_H
#define	EUCLIDEAN_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Euclidean {
public:
    Euclidean(string temp);
    Euclidean(const Euclidean& orig);
    virtual ~Euclidean();
    int ConstructFiFunctionC(int L, int k);
private:
    string id;
    int length;
    int pos;
    int euclideanid;
};

#endif	/* EUCLIDEAN_H */

