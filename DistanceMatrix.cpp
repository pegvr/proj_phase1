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
    cout << " i = " << i<< endl;
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
            int c = 0;
            size_t pos_s = 0, pos_e = 0;
            istringstream iss(line);
            while (getline(iss, tmp, '\t'))//for(i = 0; i < line.size()-1; i++)
            {
                //pos_s = pos_e;
                //pos_e = line.find("\t");
                //tmp = line.substr(0, pos_e);
                //cout << "tmp = " << tmp << endl;
                //tmp = line[i];
                //cout << "tmp = " << tmp << endl;
                //if (i == 3) break;
                if(tmp != "\t")
                {
                    c++;
                    num = stoi(tmp,nullptr,10);                  
                    Array[row][column] = num;
                    column++;

                }
                
            }
            //cout << " c = " << c<< endl;
            row++;   //break;         
        }
    }
    else cout << "Unable to open file"; 
    myfile.close();
    t1 = (k + 1) / 2;
    t2 = (rand() / (RAND_MAX + 1.0))*10000;
    int rows =  sizeof Array / sizeof Array[0]; // 2 rows  

    int cols = sizeof Array[0] / sizeof(int); // 5 cols
    cout << "rows = " << row << " columns = " << column << endl;
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
        //int w = (pow(Array[item][x1], 2.0) + pow(Array[item][x2], 2.0) - pow(Array[x1][x2], 2.0)) / (2 * Array[x1][x2]);
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