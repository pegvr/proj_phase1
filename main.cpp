#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <vector>
#include <time.h>
#include <ctime>
#include "Hamming.h"
#include "Hashtable.h"
#include "CosineSim.h"
#include "DistanceMatrix.h"
#include "Euclidean.h"
#include "randomfunc.h"
#include "NeighbourSearch.h"

using namespace std;

/*
 * 
 */
void QuerySearch(char *tmp1,char *tmp2, char *tmp, Hashtable **PointersToHashtable, int L, int k, string method, int counter);
void QuerySearchMatrix(char *tmp1,char *tmp2, char *tmp, Hashtable **PointersToHashtable, int L, int k, string method, int counter);
Hashtable ** CreateHash(int L, int k, int tablesize);


int main(int argc, char** argv) 
{
    unsigned int time_ui = static_cast<unsigned int>( time(NULL) % 1000 );
    string line, temp, g;
    int k = 4 , L = 5;
    ifstream myfile(argv[2]);
    if (argv[6] != NULL && argv[8] != NULL)
    {
	k = atoi(argv[6]);
        L = atoi(argv[8]);
    }

    if (myfile.is_open())
    {
        getline (myfile,line);          //First line of file shows which method to implement        
        line.erase(line.size()-1);       
        int counter = 0;
        while ( getline (myfile,line) ) counter++;                  //Count num of records into given file
 
        myfile.clear() ;                                    //Start reading file again
        myfile.seekg(0, ios::beg) ;
        getline (myfile,line) ;
        line.erase(line.size()-1);

        
        if (line ==  "@metric_space hamming")
        {
            cout << line << '\n';
            int i, j = 0;
            Hashtable **PointersToHashtable = CreateHash(L, k, 0);      //Construct L HashTables
            size_t pos;
            Hamming **hamming = new Hamming*[counter];              //Construct as many pointers to Hamming Classes as the num of points in given file
            while ( getline (myfile,line) )                         //Read file line by line
            {
                pos = line.find("\t");
                string temp1 = line.substr(0, pos);                 //Name of point: itemY 
                temp = line.substr(pos, line.size()-2);
                
                hamming[j] = new Hamming(temp,temp1);     //Construct hamming class for point j
                for (i = 0; i < L; i++)             //insert point into all hashtables
                {
                    g = hamming[j]->ConstructGFunction(k);    //g function = concatenation of random h
                   // cout << g;
                    PointersToHashtable[i]->InsertIntoHashtable(g, hamming[j], NULL, NULL, NULL, -1); //Insert Hamming point into HasttableI
                }
                j++;
            }
            myfile.close();
            string method = "@metric_space hamming";
            QuerySearch(argv[2], argv[10], argv[4], PointersToHashtable, L, k, method, counter); //Search NN
            
            //for (i = 0; i< L; i++) PointersToHashtable[i]->printTable("@metric_space hamming", 0);
            for (i = 0; i < L; i++) delete PointersToHashtable[i];
            for (i = 0; i < j; i++) delete hamming[i];
        }

        if (line ==  "@metric_space cosine")
        {
            getline (myfile,line);
            int i, j = 0;
            size_t pos;
            Hashtable **PointersToHashtable = CreateHash(L, k, 0);      //Construct L HashTables
            CosineSim **cosine = new CosineSim*[counter];               //Construct as many pointers to Cosine Classes as the num of points in given file
            while ( getline (myfile,line) )
            {
                pos = line.find("\t");
                string temp1 = line.substr(0, pos);
                temp = line.substr(pos, line.size()-2);
                cosine[j] = new CosineSim(temp, temp1);  //Construct cosine class for point j             
                srand(time(0));
                for (i = 0; i < L; i++)             //insert point into all hashtables
                {   
                    g = cosine[j]->ConstructGFunctionC( k);      //g function = concatenation of random h               
                    PointersToHashtable[i]->InsertIntoHashtable(g, NULL, cosine[j], NULL, NULL, -1);    //Insert Cosine point into HashtableI
                }
                j++;
            }
            
            myfile.close();
            string method = "@metric_space cosine";
            QuerySearch(argv[2], argv[10], argv[4], PointersToHashtable, L, k, method, counter);    //Search NN
            
            //for (i = 0; i< L;i++) PointersToHashtable[i]->printTable("@metric_space cosine",counter);
            for (i = 0; i < L; i++) delete PointersToHashtable[i];
            for (i = 0; i < j; i++) delete cosine[i];
                 
        } 
        
        //if (line == "@metric_space euclidean")
        if (5==6)
        {
            getline (myfile,line);
            int i, j = 0;
            Hashtable **PointersToHashtable = CreateHash(L, k, counter);   //Construct L HashTables
            size_t pos;
            Euclidean **euclidean = new Euclidean*[counter];            //Construct as many pointers to Euclidean Classes as the num of points in given file
            
            while ( getline (myfile,line) )
            {
                pos = line.find("\t");
                string temp1 = line.substr(0, pos);
                temp = line.substr(pos, line.size()-2);
                euclidean[j] = new Euclidean(temp, temp1);   //Construct euclidean class for point j  
                for (i = 0; i < L; i++)             //insert point into all hashtables
                {
                    int length = PointersToHashtable[i]->getLength();
                    int fi = euclidean[j]->ConstructFiFunctionC(length, k);      //Construct fi
                    PointersToHashtable[i]->InsertIntoHashtable("", NULL, NULL, euclidean[j], NULL, fi);
                }
                j++;
            }
            
            myfile.close();
            string method = "@metric_space euclidean";
            QuerySearch(argv[2], argv[10], argv[4], PointersToHashtable, L, k, method, counter);  //Search NN
            
            //for (i = 0; i< L;i++) PointersToHashtable[i]->printTable("@metric_space euclidean", 0);
            for (i = 0; i < L; i++) delete PointersToHashtable[i];
            for (i = 0; i < j; i++) delete euclidean[i];
        }
        
        if( line == "@metric_space matri")
        {
            getline (myfile,line);
            Hashtable **PointersToHashtable = CreateHash(L, k, 0);   //Construct L HashTables
            int i;
            DistanceMatrix *distancematrix = new DistanceMatrix(argv[2],counter-1, k); //Construct DistanceMatrix
            //distancematrix->PrintMatrix();
            for (i = 0; i < distancematrix->getNumOfRecors(); i++)
            {
                int *row = distancematrix->getRow(i);       //Get row i of DistanceMatrix              
                for (int j = 0; j < L; j++)            //insert point into all hashtables
                {                   
                    string g = distancematrix->ConstructGFunction(i, k);      //g function=concatenation of random h
                    PointersToHashtable[j]->InsertIntoHashtable(g, NULL, NULL, NULL, row, -1); //Insert row -> point into the hashtabel
                }
            }
            
            myfile.close();
            string method = "@metric_space matrix";
            QuerySearchMatrix(argv[2], argv[10], argv[4], PointersToHashtable, L, k, method, counter);  //Search NN
            
            //for (i = 0; i < L;i++) PointersToHashtable[i]->printTable("@metric_space matrix", counter);
            for (i = 0; i < L; i++)  delete PointersToHashtable[i];
            delete distancematrix;
        }
         
    }
    else cout << "Unable to open file"; 
    
    myfile.close();   
    return 0;
}

Hashtable ** CreateHash(int L, int k, int tablesize)
{
    Hashtable **PointersToHashtable = new Hashtable*[L];  //Table which points to g1,g2,...,gl hashtables
    char temp1[10];
    string temp = "g0";
    for (int i = 0; i < L; i++)
    {                
        sprintf(temp1, "%d", i);        //Hashtable number
        temp = 'g' + temp1;
        PointersToHashtable[i] = new Hashtable (temp, k, tablesize);
    }
    return PointersToHashtable;
}


void QuerySearch(char *tmp1, char *tmp2, char *tmp, Hashtable **PointersToHashtable, int L, int k, string method, int counter)
{
    cout<< "bhka";
    string line, temp, neighbour, min_neighbour;
    ifstream queryfile(tmp);
    int min, distance;
    if (queryfile.is_open())
    {
        cout << "query file is opened\n";
        getline (queryfile,line);          //First line of file gives radius       
        size_t pos = line.find(":");
        temp = line.substr(pos+2, line.size());
        
        int radius = stoi(temp, nullptr, 10);
        ofstream outputFile(tmp2);
        if (radius == 0)
        {
            int i = 0;
            while (getline(queryfile, line))        //Read line by line
            {
                size_t pos = line.find("\t");
                temp = line.substr(pos, line.size()-2);
                outputFile << "Query:   " << line.substr(0, pos) << endl;
                clock_t start;
                double duration;
                start = clock();
                for (i = 0; i < L; i++) //Search NN into every Hashtable
                {                                
                    distance = Nearest_Neighbor_Search(line.substr(0, pos), radius, PointersToHashtable[i], temp, k, L, method, counter, tmp1, outputFile, neighbour);
                    if (distance < min)
                    {
                        min = distance;
                        min_neighbour = neighbour;
                    }                    
                }
                duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
                outputFile << "NN found   " <<  min_neighbour << endl;
                outputFile << "DistanceLSH:   " << distance << endl;
                outputFile << "tLSH:   " << duration << endl;
            }
        }
        else 
        {
           int i = 0;
           while (getline(queryfile, line))
           {
                min = 1000; 
                size_t pos = line.find("\t");
                temp = line.substr(pos, line.size()-2);
                outputFile << "Query:   " << line.substr(0, pos) << endl;
                outputFile << "R-near neighbors:" << endl;
                for (i = 0; i < 1; i++)   //Search  neighbour within radius
                {
                    if (method == "@metric_space matrix")
                    {
                        DistanceMatrix *distancematrix = new DistanceMatrix(tmp1, counter, k);
                        RangeNeighbourSearch(line.substr(0, pos), radius, PointersToHashtable[i], temp, k, L, method, counter, tmp1, outputFile, neighbour, distancematrix);              
                    }
                    else
                    {
                       // DistanceMatrix distancematrix(tmp1, counter, k);
                        RangeNeighbourSearch(line.substr(0, pos), radius, PointersToHashtable[i], temp, k, L, method, counter, tmp1, outputFile, neighbour, NULL);

                    }
                }
                    
                clock_t start;
                double duration;
                start = clock();
                for (i = 0; i < L; i++) //Search NN into every Hashtable
                {                                
                    distance = Nearest_Neighbor_Search(line.substr(0, pos), radius, PointersToHashtable[i], temp, k, L, method, counter, tmp1, outputFile, neighbour);
                    if (distance < min)
                    {
                        min = distance;
                        min_neighbour = neighbour;
                    }                    
                }
                duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
                outputFile << "NN found   " <<  min_neighbour << endl;
                outputFile << "DistanceLSH:   " << distance << endl;
                outputFile << "tLSH:   " << duration << endl;
            }
        }
        outputFile.close();
        queryfile.close();
    }
    
    else cout << "Unable to open query file";
}

                

void QuerySearchMatrix(char *tmp1, char *tmp2, char *tmp, Hashtable **PointersToHashtable, int L, int k, string method, int counter)
{
    string line, temp, neighbour, min_neighbour ;
    ifstream queryfile(tmp);
    int min, distance, radius, numofrec = 0;
    
    if (queryfile.is_open())
    {
        getline (queryfile,line);          //First line of file gives radius       
        size_t pos = line.find(":");
        temp = line.substr(pos+2, line.size());
        
        radius = stoi(temp, nullptr, 10);
        while ( getline (queryfile,line) ) numofrec++;  
        queryfile.close();
    }
    else cout << "Unable to open query file";
    //cout << "!!!    " << numofrec << endl;
    DistanceMatrix *matrix = new DistanceMatrix(tmp,numofrec, counter-1, k);
    //matrix->PrintMatrix();
    //cout << "after construct matrix" << endl;
        ofstream outputFile(tmp2);
        if (radius == 0)
        {
            int i = 1;

            outputFile << "Query:   item_idS" << i << endl;
                clock_t start;
                double duration;
                start = clock();
                for (i = 0; i < L; i++) //Search NN into every Hashtable
                {                                
                    distance = Nearest_Neighbor_Search("", radius, PointersToHashtable[i], temp, k, L, method, numofrec, tmp1, outputFile, neighbour);
                    if (distance < min)
                    {
                        min = distance;
                        min_neighbour = neighbour;
                    }                    
                }
                duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
                outputFile << "NN found   " <<  min_neighbour << endl;
                outputFile << "DistanceLSH:   " << distance << endl;
                outputFile << "tLSH:   " << duration << endl;
            
        }
        else 
        {
            int i = 0;

            
            for (i = 0; i < 1; i++)   //Search  neighbour within radius
            {  
                RangeNeighbourSearch("", radius, PointersToHashtable[i], temp, k, L, method, numofrec, tmp1, outputFile, neighbour, matrix);              
            }
                    
                clock_t start;
                double duration;
                start = clock();
                for (i = 0; i < L; i++) //Search NN into every Hashtable
                {                                
                    distance = Nearest_Neighbor_Search("", radius, PointersToHashtable[i], temp, k, L, method, counter, tmp1, outputFile, neighbour);
                    if (distance < min)
                    {
                        min = distance;
                        min_neighbour = neighbour;
                    }                    
                }
                duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
                outputFile << "NN found   " <<  min_neighbour << endl;
                outputFile << "DistanceLSH:   " << distance << endl;
                outputFile << "tLSH:   " << duration << endl;
            
        }
        outputFile.close();
        
    
    
    
    
}

//./lsh –d <input file> –q <query file> –k <int> -L <int> -ο <output file>
//./lsh 1 DataEuclidean.csv 3 QueryEuclidean.csv 5 4 7 4 9 QueryResults.txt