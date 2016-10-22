/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CosineSim.h
 * Author: pv
 *
 * Created on 18 October 2016, 18:33
 */

#ifndef COSINESIM_H
#define COSINESIM_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class CosineSim {
public:
    CosineSim(string temp);
    CosineSim(const CosineSim& orig);
    virtual ~CosineSim();
    string ConstructGFunctionC(int L, int k);
    string getId();
private:
    string id;
    int length;
    int pos;
};

#endif /* COSINESIM_H */

