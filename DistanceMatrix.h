/* 
 * File:   DistanceMatrix.h
 * Author: angelique
 *
 * Created on October 25, 2016, 4:03 PM
 */

#ifndef DISTANCEMATRIX_H
#define	DISTANCEMATRIX_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

class DistanceMatrix {
public:
    DistanceMatrix(char *file, int counter, int k);
    DistanceMatrix(const DistanceMatrix& orig);
    virtual ~DistanceMatrix();
    void  PrintMatrix();
    int*  getRow(int i);
    int  getNumOfRecors();
    string ConstructGFunction(int item,int k);
private:
    int ** Array;
    int NumOfRecords, x1, x2, t1, t2;
};

#endif	/* DISTANCEMATRIX_H */

