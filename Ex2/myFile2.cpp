/*Ex2 devoir4 CSI2772A*/

#include <iostream> 
#include "myFile2.h"

using namespace std;


int main() {
    SetInt a; 	// object creation
    int* tab;
    



    while (a.nbElem() < 5)
    {
        cout << "add an int element" << endl;
        int elem;
        cin >> elem;
        a.add(elem);

    }
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "remove 10 " << endl;
    a.remove(10);
    cout << "a contains 10 :" << a.contains(10) << endl;
    cout << "a contains :" << a.nbElem() << " elements " << endl;
    tab = a.tabElem();
    cout << "Les elements de a sont :" << endl;
    for (int i =0; i<a.nbElem(); i++)
        cout << tab[i] << endl;

    return 0;
}

// contructor 
SetInt :: SetInt(const SetInt& n ) {
    elem =  n.elem; 
    size = n.size ; 
}


SetInt :: SetInt(int tab [] , int taille ){

   size =taille ;

   elem =new int [size];

   for (int i = 0 ; i< size ; i++){

       elem[i] = tab[i];
   }

}


// constructor 


// destructor 

SetInt :: ~SetInt(){


};

// destructor 



// ************functions **************//

 bool SetInt ::contains(int n){

    for (int i = 0; i < size; i++){

        if ( elem[i] == n ){

            return  true ; 
        }

    }
  
   return false ; 
 
}



bool SetInt :: containsIn(int n, int &x ){

      int * pointer = &x;
     int  pos = *pointer;

      if(pos > size){

          return false; 
      }

      if (elem[pos]== n ){

          return true;
           


      }
      return false;

}




void SetInt :: add(int n){

 if(contains (n) == false) {

int * pointer = new int [size +1]; // tableau dynamic

for ( int i = 0 ; i < size ; i++ ){

pointer[i] = elem[i];

}

pointer[size++] = n ;

elem = pointer; //

pointer = NULL;

delete [] pointer;

 }

}

void SetInt ::  remove(int n ) {


    int i ;

    for( i = 0 ; i < size ; i++ ){


        if (elem[i] == n){
            break;
        }  
    }

    if(i < size){

          size =   size -1 ;

            for ( int j = i ; j < size ; j++ ){

                elem[j] = elem[j+1];
            }
           
        }
}


int*  SetInt ::  tabElem() {

     if (size == 0 ) {

         return NULL ; 
     }

      
      int * tab = new int[size];

     for ( int i = 0 ; i< size ; i++ ){

        tab[i] = elem[i] ;
     }

     return tab ; 
 }


 int SetInt :: nbElem() {


     return size ;
 }







