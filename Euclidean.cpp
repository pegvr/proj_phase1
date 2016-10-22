/* 
 * File:   Euclidean.cpp
 * Author: angelique
 * 
 * Created on October 21, 2016, 12:11 AM
 */

#include "Euclidean.h"
#include "randomfunc.h"

Euclidean::Euclidean(string temp) 
{
    id = temp;
    //int count;
    cout << id << endl;
    length = id.length();
    cout << length << endl;;
}

Euclidean::Euclidean(const Euclidean& orig) {
}

Euclidean::~Euclidean() 
{
    cout << "Euclidean is destroyed";
}

string Euclidean::ConstructGFunctionC(int L, int k)
{
    int sum = 0 , r, w = 4, h , fi;
    double r , res;
    string h;
    double v;
    float t;
    long long M = pow(2.0,32) - 5;
    for(int i = 0; i < k; i++)
    {
        r = (rand() / (RAND_MAX + 1.0)) * ( (pow(2.0,31)-1) + 1);
        cout << "r = " << r << endl;
        t = float (rand() / (RAND_MAX + 1.0)) * ( w + 1);
        cout << "w = " << w << endl;
        v = marsagliarandom();
        cout << "v = " << v << endl;
        for(i=0;i<length;i++)
        {
            h=id[i];
            if(h == "\t")
            {
                p=p+1;
            }
        }
        double array[l];
        std :: istringstream iss(id);
        for (auto& i : array)
        {
            iss>> i;
        }
        l = p+1 ; //number of doubles
        for (int j=0;j<l;j++)
        {
            res = array[j]*v + res ; 
            
        }
        int h = int((res + t) / w);
        sum = sum + r * h;
        cout << "sum = " << sum << endl;       
    }
    euclideanid = sum % M;
    fi = euclideanid % (L / 2);
}
