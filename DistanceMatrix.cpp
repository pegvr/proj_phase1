/* 
 * File:   DistanceMatrix.cpp
 * Author: angelique
 * 
 * Created on October 25, 2016, 4:04 PM
 */

#include "DistanceMatrix.h"


DistanceMatrix::DistanceMatrix(char *file, int counter, int k) 
{
    NumOfRecords = counter;;
    Array = new int*[NumOfRecords];
    int i, column, num, row = 0;
    for(i = 0; i < NumOfRecords; ++i)
    {
        Array[i] = new int[NumOfRecords];   
        for(int j = 0; j < NumOfRecords; j++) Array[i][j] = 0;
    } 
    string line, temp;
    ifstream myfile(file);
    if (myfile.is_open())
    {
        getline (myfile,line);
        getline (myfile,line);
        while ( getline (myfile,line) )
        {
            column = 0;
            string tmp;
            for(i = 0; i < line.size() - 1; i++)
            {
                tmp = line[i];
                if(tmp != "\t")
                {
                    num = stoi(tmp,nullptr,10);                  
                    Array[row][column] = num;
                    column++;

                }
            }
            row++;            
        }
    }
    else cout << "Unable to open file"; 
    myfile.close();
    t1 = (k + 1) / 2;
    t2 = (rand() / (RAND_MAX + 1.0))*10000;
}

DistanceMatrix::DistanceMatrix(const DistanceMatrix& orig) 
{
    
}

DistanceMatrix::~DistanceMatrix() 
{
    for (int i = 0; i < NumOfRecords; i++ )
    {
        cout<< i<< endl;
        delete[] Array[i];
    }       
    delete [] Array;
}

int* DistanceMatrix:: getRow(int i)
{
    return *(Array + i);
}

int DistanceMatrix:: getNumOfRecors()
{
    return NumOfRecords;
}

void DistanceMatrix:: PrintMatrix()
{
    for(int i = 0; i < NumOfRecords; i++)
    {
        cout << "\nitem" << i << "\t" ;
        for (int j = 0; j < NumOfRecords; j++)
            cout << Array[i][j] << "\t";
    }
    cout << '\n' ;
}


string DistanceMatrix:: ConstructGFunction(int item, int k)
{
    int i, h;  
    string g;
    for (i = 0; i < k ; i++)
    {        
        int x11 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
        int x22 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
        //cout << x11 << "         " << x22 << '\n';
        //int w = (pow(Array[item][x11], 2.0) + pow(Array[item][x22], 2.0) - pow(Array[x11][x22], 2.0)) / (2 * Array[x11][x22]);
        int sum = (Array[item][x11]*Array[item][x11] + Array[item][x22]*Array[item][x22] - Array[x11][x22]*Array[x11][x22]);
        //cout << "sum " << sum << endl;
        int mult = Array[x11][x22] * 2;
        //cout << "mult " << mult  <<  endl;
        if (mult != 0)  h = sum / mult;
        else  h = sum ;

        if(h >= t1 && t2 >= h)
        {
            g = g + "1";
        }
        else
        {
            g = g + "0";
        }
    }
    return g;
}