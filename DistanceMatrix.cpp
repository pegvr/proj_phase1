#include "DistanceMatrix.h"


DistanceMatrix::DistanceMatrix(char *file, int counter, int k) 
{
    NumOfRecords = counter;
    NumOfColumns = counter;
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

DistanceMatrix::DistanceMatrix(char *file,int numofrecords, int counter, int k) 
{
    NumOfRecords = numofrecords;
    NumOfColumns = counter;
    Array = new int*[NumOfRecords];             //Number of rows = num of items
    //cout << "1" << endl;
    int i, column, num, row = 0;
    //cout << "2" << endl;
    
    for(i = 0; i < numofrecords; ++i)           //Number of colums = num of items (symmetric matrix)
    {
        Array[i] = new int[NumOfColumns];   
        //for(int j = 0; j < counter; j++) Array[i][j] = 0;
    } 
    //cout << "3" << endl;
    string line, temp;
    ifstream myfile(file);
    if (myfile.is_open())
    {
        getline (myfile,line);
        //cout << line << endl;
        //getline (myfile,line);
        while ( getline (myfile,line) )         //Read line by line to get each item
        {
            
            //cout << "4" << endl;
            size_t pos = line.find("\t");
            //cout << "5" << endl;
            name = line.substr(0, pos);         //Name m itemY
            //cout << "6" << endl;
            column = 0;
            string tmp;
            istringstream iss(line);
            //cout << "7" << endl;
            while (getline(iss, tmp, '\t'))     //For each itemY store in columns distances from other items
            {
                //cout << "8  " << tmp[0]<< tmp[1] << endl;
                if(tmp != "\t" && tmp[0] != 'i')
                {
                    //cout << "9" << row << endl;
                    num = stoi(tmp, nullptr, 10);                  
                    Array[row][column] = num;
                    column++;
                    //cout << "10" << endl;
                }               
            }
            //cout << "11  " << column << endl;
            row++;           
        }
    }
    else cout << "Unable to open file"; 
    myfile.close();
    t1 = (k + 1) / 2;
   // t2 = (rand() / (RAND_MAX + 1.0)) * 10000;
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

int DistanceMatrix:: getNumOfColumns()
{
    return NumOfColumns;
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
    
    int i, j, h, ii =0, jj= 0, matrix[k], matrix2[k], sum = 0;  
    string g;
    srand(time(NULL)); 
    for (i = 0; i < k ; i++)
    {        
        int x1 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
        int x2 = (rand() / (RAND_MAX + 1.0))*NumOfRecords;
        int dist = (Array[item][x1]*Array[item][x1] + Array[item][x2]*Array[item][x2] - Array[x1][x2]*Array[x1][x2]);
        int mult = Array[x1][x2] * 2;
        if (mult != 0)  h = dist / mult;
        else  h = dist ;
        matrix[i] = h;
        matrix2[i] = h;
    }
    for (i = 0; i < k; i++)
        for(j = 0; j < k - 1; j++)
            if (matrix[j] > matrix[j+1]) 
            {
                h = matrix[j] ;
                matrix[j] = matrix[j+1];
                matrix[j+1] = h;
            }
    if (k % 2 == 0) t1 =  matrix[k / 2];
    else t1 =  matrix[(k + 1) / 2];
                
    for (i = 0; i < k ; i++)
    {
        if(matrix2[i] >= t1)
        {
            //ii++;
            g = g + "1";
        }
        else
        {
            //jj++;
            g = g + "0";
        }
    }
    //cout << ii << "             " << jj << "         g= " << g << endl;
    return g;
}
