#include "NeighbourSearch.h"
#include "DistanceMatrix.h"


void RangeNeighbourSearch(string name, int radius, Hashtable *Hashtable, string temp,int k, int L, string method, int counter, char *tmp1, ofstream &outputFile, string &neighbour)
{
    
    if (method == "@metric_space hamming")
    {
        Hamming hamming(temp,name);
        string g = hamming.ConstructGFunction(k);
        Hashtable->SearchBucket(0, g, temp, name, 0, NULL, -1, method, radius, outputFile, 1, neighbour);
    }
    else if (method == "@metric_space cosine")
    {
        CosineSim cosine(temp, name);
        string g = cosine.ConstructGFunctionC(k);
        Hashtable->SearchBucket(0, g, temp, name,  0, NULL, -1, method, radius, outputFile, 1, neighbour);
    }    
    else if (method == "@metric_space euclidean")
    {
        Euclidean euclidean(temp, name);
        int fi = euclidean.ConstructFiFunctionC(L, k);
        Hashtable->SearchBucket(0, "", temp, name,  0, NULL, fi, method, radius, outputFile, 1, neighbour);
    }     
    else
    {
        DistanceMatrix distancematrix(tmp1, counter, k);
        for (int i = 0; i < distancematrix.getNumOfRecors(); i++)
        {                 
            string g = distancematrix.ConstructGFunction(i, k) ;     //g function=concatenation of random h
            name = distancematrix.getName();
            int *row = distancematrix.getRow(i);
            Hashtable->SearchBucket(0, g, temp, name, counter, row, -1, method, radius, outputFile, 1, neighbour);
        }
    }
}


int Nearest_Neighbor_Search(string name, int radius, Hashtable *Hashtable, string temp,int k, int L, string method, int counter, char *tmp1, ofstream &outputFile, string &neighbour)
{
    int distance = 0;
    if (method == "@metric_space hamming")
    {
        Hamming hamming(temp,name);
        string g = hamming.ConstructGFunction(k);
        distance = Hashtable->SearchBucket(L, g, temp, name,  0, NULL, -1, method, radius, outputFile, 2, neighbour);
    }
    else if (method == "@metric_space cosine")
    {
        CosineSim cosine(temp, name);
        string g = cosine.ConstructGFunctionC(k);
        distance = Hashtable->SearchBucket(L, g, temp, name, 0, NULL, -1, method, radius, outputFile, 2, neighbour);
    }    
    else if (method == "@metric_space euclidean")
    {
        Euclidean euclidean(temp, name);
        int fi = euclidean.ConstructFiFunctionC(L, k);
        distance = Hashtable->SearchBucket(L,"", temp, name, 0, NULL, fi, method, radius, outputFile, 2, neighbour);
    }     
    else
    {
        DistanceMatrix distancematrix(tmp1, counter, k);
        for (int i = 0; i < distancematrix.getNumOfRecors(); i++)
        {                 
            string g = distancematrix.ConstructGFunction(i, k) ;     //g function=concatenation of random h
            distance = Hashtable->SearchBucket(L, g, temp, name, counter, NULL, -1, method, radius, outputFile, 2, neighbour);
        }
    }
    return distance;
}
