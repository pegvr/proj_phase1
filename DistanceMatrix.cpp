/* 
 * File:   DistanceMatrix.cpp
 * Author: angelique
 * 
 * Created on October 25, 2016, 4:04 PM
 */


#include "DistanceMatrix.h"


DistanceMatrix::DistanceMatrix(char *file, int counter, int k) 
{
    cout << "inside constructor " << counter << endl;
    NumOfRecords = counter;
    cout << "NumOfRecords  " << NumOfRecords << endl;
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
            //cout << line << '\n';
            //size_t pos = line.find("\t");
            //cout << pos;
            //temp = line.substr(pos, line.size()-2);
            //cout << temp << '\n';
            //break;
            column = 0;
            string tmp;
            int count =0, c =0;
            for(i = 0; i < line.size() - 1; i++)
            {
                //count++;
                tmp = line[i];
                //cout << tmp << "                  " << line[i] << endl;
                if(tmp != "\t")
                {
                    //cout << "im here\n" ;
                    num = stoi(tmp,nullptr,10);
                    Array[row][column] = num;
                    column++;
                    //c++;
                }
                //else cout <<"den mphka\n" ;
            }
            //cout << "count    " << count << endl;
            //cout << "cols created    " << c << endl;
            row++;
            
        }
    }
    else cout << "Unable to open file"; 
    //srand(time(NULL)); 
    //x1 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
    //x2 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
    //cout << x1 << "         " << x2 << '\n';
    t1 = (k + 1) / 2;
    t2 = (rand() / (RAND_MAX + 1.0))*10000;
    //cout << t1 << "         " <<  t2 << '\n';
    //int rows =  sizeof Array / sizeof Array[0]; // 2 rows  

    //int cols = sizeof Array[0] / sizeof(int); // 5 cols
    //cout << "rows = " << rows << " columns = " << cols << endl;
}

DistanceMatrix::DistanceMatrix(const DistanceMatrix& orig) {
}

DistanceMatrix::~DistanceMatrix() {
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
    int x11 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
    int x22 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
    cout << x11 << "         " << x22 << '\n';
    for (i = 0; i < k ; i++)
    {        
        //int w = (pow(Array[item][x11], 2.0) + pow(Array[item][x22], 2.0) - pow(Array[x11][x22], 2.0)) / (2 * Array[x11][x22]);
        int sum = (Array[item][x11]*Array[item][x11] + Array[item][x22]*Array[item][x22] - Array[x11][x22]*Array[x11][x22]);
        cout << "sum " << sum << endl;
        int mult = Array[x11][x22] * 2;
        cout << "mult " << mult  <<  endl;
        if (mult != 0)  h = sum / mult;
        else  h = sum ;
        cout << "h =      " <<  h << '\n'; 
        
        if(h >= t1 && t2 >= h)
        {
            //cout << "bainw sto 1" << endl;
            g = g + "1";
             //cout << "\nto neo g einai :"<< g;
        }
        else
        {
            //cout << "bainw sto 0" << endl;
            g = g + "0";
            //cout << "\nto neo g einai :"<< g;
        }
    }
    cout << t1 << "         " <<  t2 << '\n';
    return g;
}