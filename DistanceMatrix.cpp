#include "DistanceMatrix.h"


DistanceMatrix::DistanceMatrix(char *file, int counter, int k) 
{
    NumOfRecords = counter;;
    Array = new int*[NumOfRecords];             //Number of rows = num of items
    int i, column, num, row = 0;
    for(i = 0; i < NumOfRecords; ++i)           //Number of colums = num of items (symmetric matrix)
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
        while ( getline (myfile,line) )         //Read line by line to get each item
        {
            size_t pos = line.find("\t");
            name = line.substr(0, pos);         //Name m itemY
            column = 0;
            string tmp;
            istringstream iss(line);
            while (getline(iss, tmp, '\t'))     //For each itemY store in columns distances from other items
            {
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
    t2 = (rand() / (RAND_MAX + 1.0)) * 10000;
}

DistanceMatrix::DistanceMatrix(const DistanceMatrix& orig) 
{
    
}

DistanceMatrix::~DistanceMatrix() 
{
    for (int i = 0; i < NumOfRecords; ++i )
        delete[] Array[i];     
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

string DistanceMatrix :: getName()
{
    return name;
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
        int x1 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
        int x2 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
        int dist = (Array[item][x1]*Array[item][x1] + Array[item][x2]*Array[item][x2] - Array[x1][x2]*Array[x1][x2]);
        int mult = Array[x1][x2] * 2;
        if (mult != 0)  h = dist / mult;
        else  h = dist ;
        
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