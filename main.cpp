/* 
 * File:   main.cpp
 * Author: angelique
 *
 * Created on October 17, 2016, 6:45 PM
 */

#include <cstdlib>
#include <fstream>
#include <string.h>
#include "Hashtable.h"
#include "CosineSim.h"

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
    int k=4;
    int L=5;
    myfile.open("DataEuclidean.csv");
    if (myfile.is_open())
    {
        //cout << "im here";
        getline (myfile,line);          //First line of file shows which method to implement
        //cout << "line =" << line << line.size()<< '\n';
        line.erase(line.size()-1);
        cout << "line =" << line << line.size()<< '\n';
        

        /*if (line ==  "@metric_space hamming")
        {
            cout << line << '\n';
            int i, j = 0;
            Hashtable **PointersToHashtable = new Hashtable*[L];  //Table which points to g1,g2,...,gl hashtables
            char temp1[10];
            for (i = 0; i < L; i++)
            {
                sprintf(temp1, "%d", i);        //Hashtable number
                temp = 'g' + temp1;
                PointersToHashtable[i] = new Hashtable (temp, k);
            }
            //for (i=0; i< L;i++) PointersToHashtable[i]->printTable();
            size_t pos;
            Hamming **hamming;
            while ( getline (myfile,line) )
            {
                cout << line << '\n';
                pos = line.find("\t");
                temp = line.substr(pos, line.size()-2);
                cout << temp << '\n';
                //for (int i = 0 ; i < temp.length(); i++)
                //    if (temp[i] == ' ') temp.erase(i, 1);
                //remove(temp.begin(), temp.end(), ' ');
                //cout << temp << '\n';
                hamming[j] = new Hamming(temp);     //pointer to hamming class for point j
                for (i = 0; i < L; i++)             //insert point into all hashtables
                {
                    //g = hamming[j]->ConstructGFunction(L, k);      //g function=concatenation of random h
                    g = "00001";
                    cout << "g = " << g << endl;
                    PointersToHashtable[i]->insertHamming(g, hamming[j]);
                    cout << "after insert hamming to hash" << endl;
                    //break;
                }
                j++;
                PointersToHashtable[0]->printTable();
                cout << "before break" << endl;
                break;
            }
        }
        cout << "after break" << endl;
        myfile.close();
        cout << "!!!" << endl;*/
        getline (myfile,line);  
        cout << "line =" << line << line.size()<< '\n';
        line.erase(line.size()-1);
        cout << line;
         if (5==5)
          {
             cout << '\n';
              cout <<"EIMAI XAZO KAI DEN DIAVAZW THN PRWTH GRAMMH";
              cout << line << '\n';
              int i, j = 0;
              Hashtable **PointersToHashtable = new Hashtable*[L];  //Table which points to g1,g2,...,gl hashtables
              char temp1[10];
              for (i = 0; i < L; i++)
                    {
                sprintf(temp1, "%d", i);        //Hashtable number
                temp = 'g' + temp1;
                PointersToHashtable[i] = new Hashtable (temp, k);
            }
            
            int counter = 0;
            cout << "im here";
            while ( getline (myfile,line) ) counter++;
            
            cout << "file has number of records: " << counter << endl; 
            myfile.clear() ;
            myfile.seekg(0, ios::beg) ; //reread the file 
            size_t pos;
           CosineSim **cosine = new CosineSim*[counter];
           cout << line;
           getline (myfile,line);
           line.erase(line.size()-1);
           getline (myfile,line);
           line.erase(line.size()-1);
           cout << "line =" << line << line.size()<< '\n';
           
            while ( getline (myfile,line) )
            {
                
               // cout << line << '\n';
                pos = line.find("\t");
                //cout << pos;
                temp = line.substr(pos, line.size()-2);
                //cout << temp << '\n';
                cout << '\n';
                cosine[j] = new CosineSim(temp);   //pointer to class for point 
                cout << L;
                for (i = 0; i < L; i++)             //insert point into all hashtables
                {
                    g = cosine[j]->ConstructGFunctionC(L, k);      //g function=concatenation of random h
                   // g = "00001";
                    cout << "g = " << g << endl;
                    //PointersToHashtable[i]->insertHamming(g, hamming[j]);
                   // cout << "after insert cosine to hash" << endl;
                    break;
                }
                j++;
                //PointersToHashtable[0]->printTable();
                cout << "before break" << endl;
                break;}
                 
        } 
        cout << "after break" << endl;
        myfile.close();
        cout << "!!!" << endl;
    
    
    }
    
    else cout << "Unable to open file";

    return 0;

}