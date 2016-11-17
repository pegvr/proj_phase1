#include "LinkedList.h"

LinkedList::LinkedList()            //Linked List Constructor
{
    head = new Point;
    head -> next = NULL;
    length = 0;
}

LinkedList::LinkedList(const LinkedList& orig) {
}
 

LinkedList::~LinkedList()       //Linked List Destructor
{
    Point * p = head;
    Point * q = head;
    while (q != NULL)
    {
        p = q;
        q = p -> next;
        if (q != NULL) delete p;
    }
}

// Inserts an item at the head of the list.
void LinkedList::insertPoint( Hamming * HammingPoint,CosineSim *CosinePoint,Euclidean *EuclideanPoint, int * Row)
{
    Point *temp = new Point(HammingPoint, CosinePoint, EuclideanPoint, Row);
    if (!head -> next)              //If list is empty insert here
    {
        head -> next = temp;
        length++;
        return;
    }
    temp->next = head->next;
    head->next = temp;
    length++;
}



void LinkedList::Search(int radius, string temp,string item, int counter, int * Row, string method, ofstream& file, int columns)
{
    int i;
    if (length == 0)                //There are no points in bucket for searching
    {
        //cout << "\n bucket empty \n";
        return;
    }
    if (Row != NULL)
    {
        for ( i = 0; i < counter; i++) 
            if (Row[i] == 0) {break;}             //Item position
        cout << "Query Item ==  " << i << endl;
    }

    Point * p = head->next;             //Start searching whole bucket for neighbour
    while (p)
    {
        if (method == "@metric_space hamming")              //Choose method
        {
            int diff = 0;
            string temp2 = p->hamming_key->getId();
            for (int i = 0; i < temp.size() ; i++)          //Find how many bits are different
                if (temp[i] != temp2[i]) diff++;
            if (diff < radius)                              //If we found wanted distance print into file
                file <<  p->hamming_key->getName() << endl;
        }
        else if (method == "@metric_space euclidean")   //Choose method
        {
            int num = 0, sum = 0;
            string temp2 = p->euclidean_key->getId(), h;
            for(i = 0; i < length; i++)                     //Count how many dimensions the point has
            {
                h = temp2[i];
                if(h == "\t")   num++;
            }
            double array1[num + 1];                         //Array to store each distance of bucket point
            istringstream iss(temp2);
            for (auto& i : array1)                          //For every distance, store it
            {
                iss >> i;
            }
            double array2[num + 1];                         //Array to store each distance of query point
            istringstream iss2(temp);
            for (auto& i : array2)                          //For every distance, store it
            {
                iss2 >> i;
            }
            for (int i = 0; i < num + 1 ; i++)              //Calculate "almost" euclidean distance 
                sum += (array1[i] - array2[i]) * ((array1[i] - array2[i]));

            if (sqrt(sum) < radius)                         //Check if wanted distance has been found
                file << p->euclidean_key->getName() << endl;
                
        }
        else if (method == "@metric_space cosine")          //Cosine method 
        {
            int num = 0, norma1 = 0, norma2 = 0, inner_product = 0;
            string temp2 = p->cosine_key->getId(), h;
            for(i = 0; i < length; i++)                     //Count how many dimensions the point has
            {
                h = temp2[i];
                if(h == "\t")   num++;
            }
            double array1[num + 1];                         //Array to store each dimension of bucket point
            istringstream iss(temp2);
            for (auto& i : array1)                          //For every dimension, store it
            {
                iss>> i;
            }
            for(i = 0; i < num + 1; i++)
                norma1 += array1[i] * array1[i];           //norma of bucket point
            norma1 = sqrt(norma1);
            double array2[num + 1];                         //Array to store each dimension of query point
            istringstream iss2(temp);
            for (auto& i : array2)                          //For every dimension, store it
            {
                iss2>> i;
            }
            for(i = 0; i < num + 1; i++)
                norma2 += array2[i] * array2[i];        //norma of query point
            norma2 = sqrt(norma2); 
            for(i = 0; i < num + 1; i++)
                inner_product += array1[i] * array2[i];          //inner product of query and bucket point
            int dist = 1 - (inner_product / (norma1 * norma2));
            if (dist < radius)
               file << p->cosine_key->getName() << endl; 
        }
        else
        {
            int j;                                      
               /* for ( j = 0; j < columns; j++)
                {
                    if(Row[j] < radius && Row[j] > 0)
                        cout << "item" << j << endl;
                }*/

                    if(p->row[i] < radius && p->row[i] > 0 )
                    {
                        //cout << p->row[i] << endl;
                        for ( j = 0; j < columns; j++){
                            //cout << p->row[i] << endl;
                            if (p->row[j] == 0){
                                file << "item" << j+1 << endl;
                                break;
                            }
                        }
                    }
        }
        p = p->next;
    }
}



void LinkedList::printList(string method, int counter)      //Print whole bucket
{

    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Point * p = head->next;
    cout << "\n{ ";
    while (p)
    {
        if (method == "@metric_space hamming")
            cout << p->hamming_key->getId();
        else if (method == "@metric_space cosine")
            cout << p->cosine_key->getId();
        else if (method == "@metric_space euclidean")
            cout << p -> euclidean_key->getId();
        else
            for (int i = 0; i < counter; i++)
                cout << p->row[i]<< "\t";
        if (p -> next) cout << ", ";
        else break;
        p = p->next;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}

//NN_Search same as Search function with only difference that looks for min distance
string LinkedList::NN_Search(int L, int radius, string temp,string item, Euclidean *EuclideanPoint, int * Row, string method, int &distance)
{
    int MAX= 1000;
    int i; 
    string b;
    //for (i = 0; i < L; i++)
    //{
        if (length == 0)
        {
            //cout << "\n bucket empty \n";
            return b;
        }
        Point * p = head->next;
        while (p)
        {
            if (method == "@metric_space hamming")
            {
                int diff = 0;
                string temp2 = p->hamming_key->getId();

                for (int i = 0; i < temp.size(); i++)
                    if (temp[i] != temp2[i]) diff++;
                if (diff < MAX)                         //Looks for min hamming distance
                {
                    b = p->hamming_key->getName();
                    distance = diff;
                    MAX = diff;
                }
            }
            else if (method == "@metric_space euclidean")
            {
                int num = 0, sum = 0;
                string temp2 = p->euclidean_key->getId(), h;
                for(i = 0; i < length; i++)
                {
                    h = temp2[i];
                    if(h == "\t")   num++;
                }
                double array1[num + 1];
                istringstream iss(temp2);
                for (auto& i : array1)
                {
                    iss>> i;
                }
                double array2[num + 1];
                istringstream iss2(temp);
                for (auto& i : array2)
                {
                    iss2>> i;
                }
                for (int i = 0; i < num + 1 ; i++)
                    sum += (array1[i] - array2[i]) * ((array1[i] - array2[i]));

                if (sqrt(sum) < MAX)                    //Looks for min euclidean distance
                {
                    b = p->euclidean_key->getName();
                    distance = sqrt(sum);
                    MAX = sqrt(sum);
                    if (p->next == NULL) return b;
                }
                
            }
            else if (method == "@metric_space cosine")
            {
                int num = 0, norma1 = 0, norma2 = 0, inner_product = 0;
                string temp2 = p->cosine_key->getId(), h;
                for(i = 0; i < length; i++)
                {
                    h = temp2[i];
                    if(h == "\t")   num++;
                }
                double array1[num + 1];
                std :: istringstream iss(temp2);
                for (auto& i : array1)
                {
                    iss>> i;
                }
                for(i = 0; i < num + 1; i++)
                    norma1 += array1[i] * array1[i];           //norma
                norma1 = sqrt(norma1);
                double array2[num + 1];
                istringstream iss2(temp);
                for (auto& i : array2)
                {
                    iss2>> i;
                }
                for(i = 0; i < num + 1; i++)
                    norma2 += array2[i] * array2[i];        //norma 
                norma2 = sqrt(norma2); 
                for(i = 0; i < num + 1; i++)
                    inner_product += array1[i] * array2[i];             //inner product
                int dist = 1 - (inner_product / (norma1 * norma2));     //Cosine distance
                
                if (dist < MAX)                             //Looks for min cosine distance
                {
                    b = p->cosine_key->getName();
                    MAX = dist;
                    distance = dist;
                    if (p->next == NULL) return b;
                }
                    
            }
            else
            {
                //.......
                return b;
            }
                
            p = p->next;

        }
    //}
    return b;
}