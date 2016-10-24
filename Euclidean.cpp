

#include "Euclidean.h"
#include "randomfunc.h"
#include <sstream>



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

string Euclidean:: getId()
{
    return id;
}

int Euclidean::ConstructFiFunctionC(int L, int k)
{
    int sum = 0 ,l=0, p=0, r, w = 4, h , fi;
    //int l=0;
    //int p = 0;
    double res , v;
    string st;
    float t;
    long long M = pow(2.0,32) - 5;
    for( int i=0;i<length;i++)
        {
            //cout << "hello here \n";
            st = id[i];
            if(st == "\t")
            {
                p=p+1;
            }
        }
        cout << p;
        l = p+1 ; //number of doubles
        double array[l];
        std :: istringstream iss(id);
        for (auto& i : array)
        {
            iss>> i;
        }
     srand(time(NULL));    
       // cout <<"the number of doubles is :" << l<<"\n";
    for(int i = 0; i < k; i++)
    {
       
        r = (rand() / (RAND_MAX + 1.0)) * ( (pow(2.0,31)-1) + 1);
        
        cout << "r = " << r << endl;
        srand(1);
        t = float (rand() / (RAND_MAX + 1.0)) * ( w + 1);
        //srand(time(NULL));
        cout << "t = " << t << endl;
        v = marsagliarandom();
        cout << "v = " << v << endl;
        
        for (int j=0;j<l;j++)
        {
            res = array[j]*v + res ; //eswteriko ginomeno
            
        }
        int h = int((res + t) / w);
        sum = sum + r * h;
        cout << "sum = " << sum << endl;      
        //srand(time(NULL));
    }
    euclideanid = sum % M;
    return fi = euclideanid % (L / 2); //mod
    
}
