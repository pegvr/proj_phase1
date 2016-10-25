/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <sstream>
#include "CosineSim.h"
#include "Hashtable.h"
#include "randomfunc.h"
#include "time.h"


CosineSim::CosineSim(string temp) 
{
    id=temp;
    int count;
    cout << id;
    cout << "\n";
    cout << "hello";
    length = id.length();
    cout << "hello";
    cout << length;
    /*int pos;
    for (int i=0;i<length;i++)
    {
        while (id[i] =! "\n" )
        {
            if(id[i]=="\t")
                pos=i;
                
            
        }
    }
    */
    
    
}

CosineSim::CosineSim(const CosineSim& orig) {
}

CosineSim::~CosineSim() 
{
    cout << "Cosine is destroyed";
}

string CosineSim :: getId()
{
    return id;
}

string CosineSim::ConstructGFunctionC(int L, int k)
{   srand(time(0));
    cout << "bhka";
    int i, x1, x2, p=0;
    int l; //length of the new array
    double r , res;
    string h , f;
    for(i=0;i<length;i++)
    {
        h=id[i];
        if(h == "\t")
        {
            p=p+1;
        }
    }
    l = p+1 ; 
    cout << "number \n"<<l <<"\n";
    double array[l];
    std :: istringstream iss(id);
    for (auto& i : array)
    {
        iss>> i;
    }
   
    /*char temp1[10];
    string temp;
    Hashtable **PointersToHashtable = new Hashtable*[L];  //Table which points to g1,g2,...,gl hashtables
    for(i = 0; i < L; i++)
    {       
        sprintf(temp1, "%d", i);        //Hashtable number
        temp = 'g' + temp1;
        PointersToHashtable[i] = new Hashtable (temp, k);
    }*/
    
    
  
   
    string g;
    int j;
     for (j = 0; j < (k); j++)
    {
         //srand(time(0));
        r = marsagliarandom();
        cout << "\n\n\nto r einai:"<< r;
        for (int i=0;i<l;i++)
        {
            cout << array[i]<< "\n";
            res = array[i]*r + res ; 
            cout <<"res:" << res;
            
        }
        cout << res;
        if(res >= 0)
        {
            //cout << "bainw";
             g = g + "0";
             //cout << "\nto neo g einai :"<< g;
        }
        else
        {
             g = g + "1";
             //cout << "\nto neo g einai :"<< g;
        }
        
        cout << g;
        //g = "0010";
    }
  
    return g;
}