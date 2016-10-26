

#ifndef DISTANCEMATRIX_H
#define	DISTANCEMATRIX_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <math.h>
#include <sstream>


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
    int **Array;
    int NumOfRecords, t1, t2;
};

#endif	/* DISTANCEMATRIX_H */



