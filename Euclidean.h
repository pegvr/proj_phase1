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

using namespace std;

class Euclidean {
public:
    Euclidean(string temp);
    Euclidean(const Euclidean& orig);
    virtual ~Euclidean();
    string ConstructGFunctionC(int L, int k);
private:
    string id;
    int length;
    int pos;
    int euclideanid;
};

#endif	/* EUCLIDEAN_H */

