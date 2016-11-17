#ifndef NEAREST_NEIGHBOR_H
#define NEAREST_NEIGHBOR_H


#include <string>
#include "Hamming.h"
#include "Hashtable.h"
#include "DistanceMatrix.h"

void RangeNeighbourSearch(string name, int radius, Hashtable *Hashtable, string temp,int k, int L, string method, int counter, char *tmp1, ofstream& outputFile, string &neighbour, DistanceMatrix *distancematrix);

int Nearest_Neighbor_Search(string name, int radius, Hashtable *Hashtable, string temp,int k, int L, string method, int counter, char *tmp1, ofstream &outputFile, string &neighbour);

#endif /* NEAREST_NEIGHBOR_H */

