/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DistanceMatrix.h
 * Author: pv
 *
 * Created on 26 October 2016
 */

#ifndef DISTANCEMATRIX_H
#define DISTANCEMATRIX_H
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




