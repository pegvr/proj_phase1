
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <time.h>
//#include <vector>
#include "Hamming.h"
#include "Hashtable.h"
#include "CosineSim.h"
#include "Euclidean.h"

using namespace std;

/*
 *
 */

int main(int argc, char** argv) 
{
   /* string temp = "0000000011";
    const char  *l = temp.c_str();
    int kol = strtol(l, NULL, 2);
    cout << kol << endl;*/
    string line, temp, g;
    //if (argv[2] != NULL)
    ifstream myfile(argv[2]);
    //int k = atoi(argv[6]);
    //int L = atoi(argv[8]);
    int k=5;
    int L=4;
    myfile.open("DataEuclidean.csv");
    if (myfile.is_open())
    {
        getline (myfile,line);          //First line of file shows which method to implement        
        //cout << "line =" << line << line.size()<< '\n';
        line.erase(line.size()-1);
        string method = line;
        cout << "method =" << method << line.size()<< '\n';
        Hashtable **PointersToHashtable = new Hashtable*[L];  //Table which points to g1,g2,...,gl hashtables
        char temp1[10];
        for (int i = 0; i < L; i++)
        {                
            sprintf(temp1, "%d", i);        //Hashtable number
            temp = 'g' + temp1;
            PointersToHashtable[i] = new Hashtable (temp, k);
        }
        //for (i=0; i< L;i++) PointersToHashtable[i]->printTable();
        int counter = 0;
        while ( getline (myfile,line) ) counter++;                  //Count num of records into given file
        cout << "file has number of records: " << counter << endl; 
        myfile.clear() ;
        myfile.seekg(0, ios::beg) ;
        getline (myfile,line) ;
        line.erase(line.size()-1);
        cout << line << '\n';
        
        if (line ==  "@metric_space hamming")
        {
            cout << line << '\n';
            int i, j = 0;
           /* Hashtable **PointersToHashtable = new Hashtable*[L];  //Table which points to g1,g2,...,gl hashtables
            char temp1[10];
            for (i = 0; i < L; i++)
            {                
                sprintf(temp1, "%d", i);        //Hashtable number
                temp = 'g' + temp1;
                PointersToHashtable[i] = new Hashtable (temp, k);
            }*/
            //for (i=0; i< L;i++) PointersToHashtable[i]->printTable();
            /*int counter = 0;
            while ( getline (myfile,line) ) counter++;
            cout << "file has number of records: " << counter << endl; 
            myfile.clear() ;
            myfile.seekg(0, ios::beg) ;
            getline (myfile,line) ;*/
            size_t pos;
            Hamming **hamming = new Hamming*[counter];
            while ( getline (myfile,line) )
            {
                cout << line << '\n';
                pos = line.find("\t");
                temp = line.substr(pos, line.size()-2);
                //cout << temp << '\n';
                //for (int i = 0 ; i < temp.length(); i++)
                //    if (temp[i] == ' ') temp.erase(i, 1);
                //remove(temp.begin(), temp.end(), ' ');
                //cout << temp << '\n';
                hamming[j] = new Hamming(temp);     //pointer to hamming class for point j
                for (i = 0; i < L; i++)             //insert point into all hashtables
                {
                    g = hamming[j]->ConstructGFunction(L, k);      //g function=concatenation of random h
                    //g = "00001";
                    //cout << "g = " << g << endl;
                    PointersToHashtable[i]->InsertIntoHashtable(g, hamming[j], NULL, NULL, 0);
                    //cout << "after insert hamming to hash" << endl;
                    //break;
                }
                j++;
                //PointersToHashtable[0]->printTable();
                //cout << "before break" << endl;
                //break;
            }
            for (i=0; i< L;i++) PointersToHashtable[i]->printTable(method);
            for (i = 0; i < L; i++) { cout << "delete hash " << i << endl;delete PointersToHashtable[i];}
            for (i = 0; i < j; i++) delete hamming[i];
        }
        //cout << "after break" << endl;
        
    
        if ( 5==5)//line ==  "@metric_space cosine")
        {
            cout << '\n';
            getline (myfile,line);
            //cout <<"EIMAI XAZO KAI DEN DIAVAZW THN PRWTH GRAMMH" << endl;
            cout << line << '\n';
            int i, j = 0;
           /* Hashtable **PointersToHashtable = new Hashtable*[L];  //Table which points to g1,g2,...,gl hashtables
            char temp1[10];
            for (i = 0; i < L; i++)
            {
                sprintf(temp1, "%d", i);        //Hashtable number
                temp = 'g' + temp1;
                PointersToHashtable[i] = new Hashtable (temp, k);
            }
            
            int counter = 0;
            //cout << "im here";
            while ( getline (myfile,line) ) counter++;
            
            cout << "file has number of records: " << counter << endl; 
            myfile.clear() ;
            myfile.seekg(0, ios::beg) ; //reread the file */
            size_t pos;
            CosineSim **cosine = new CosineSim*[counter];
            /*cout << line << endl;;
            getline (myfile,line);
            line.erase(line.size()-1);
            getline (myfile,line);
            line.erase(line.size()-1);
            cout << "line = " << line << line.size()<< '\n';*/
           
            while ( getline (myfile,line) )
            {
                
                cout << line << '\n';
                pos = line.find("\t");
                //cout << pos;
                temp = line.substr(pos, line.size()-2);
                //cout << temp << '\n';
                cout << '\n';
                cosine[j] = new CosineSim(temp);   //pointer to class for point 
                cout << L;
               
                for (i = 0; i < L; i++)             //insert point into all hashtables
                {
                    //srand(time(0));
                    g = cosine[j]->ConstructGFunctionC(L, k);      //g function=concatenation of random h
                   // g = "00001";
                    cout << "g = " << g << endl;
                    PointersToHashtable[i]->InsertIntoHashtable(g, NULL, cosine[j], NULL, 0);
                   // cout << "after insert cosine to hash" << endl;
                   
                    
                }
               
                j++;
                PointersToHashtable[0]->printTable("@metric_space cosine");
                
                cout << "before break" << endl;
                break;
            }
            
                 
        } 
       
        if ( 3==5)//line ==  "@metric_space euclidean")
        {
            getline (myfile,line);
            cout <<"grammh"<< line << '\n';
            int i, j = 0;

            size_t pos;
            Euclidean **euclidean = new Euclidean*[counter];
            //getline (myfile,line) ;
            //line.erase(line.size()-1);
            //getline (myfile,line) ;
            //line.erase(line.size()-1);
            //cout << line;
            while ( getline (myfile,line) )
            {
                //cout << "GRAMMH"<<line << '\n';
                pos = line.find("\t");
                //cout << pos;
                temp = line.substr(pos, line.size()-2);
                //cout << "TO TEMP EINAI" << temp << '\n';
                cout << '\n';
                euclidean[j] = new Euclidean(temp);   //pointer to class for point 
                cout << L;
                for (i = 0; i < L; i++)             //insert point into all hashtables
                {
                    cout << "yah";
                    int fi = euclidean[j]->ConstructFiFunctionC(L, k);      //g function=concatenation of random h
                    cout << "fi = " << fi << endl;
                    //PointersToHashtable[i]->InsertIntoHashtable("", NULL, NULL, euclidean[j], fi);
                   // cout << "after insert cosine to hash" << endl;
                    break;
                }
                j++;
                //PointersToHashtable[0]->printTable();
                cout << "before break" << endl;
                break;
            }
        }
    }
    else cout << "Unable to open file"; 
    cout << "!!!" << endl;
    myfile.close();
    
    cout << "!!!!!!!!!!!!" << endl;
    
    return 0;
}