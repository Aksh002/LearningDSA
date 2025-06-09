/*

//                          Giving output

#include <iostream>         // iostream is a library for basic input output
//#include<math.h>            // math library provides various arathematic fxnalities
//#include<string>            // provides string fxnality
int main(){
    std::cout << "HI Akshit"<< "\n";
    std::cout << "HI Akshit";
    // cout is a fxn that exists under std, which is used to give output

    // Another way
    std::cout << "HI Akshit" << std::endl << "HI Akshit" << "\n" << "HI Akshit";
}


// Better way       :- removing std::
#include <iostream> 

using namespace std;
// If we use this, no need to use std:: in whole code

int main(){
    cout << "HI Akshit"<< "\n";
    cout << "HI Akshit";
}


//                          Taking Input
#include <iostream> 
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    // Take "10 12" as input, can also take in sep lines
    cout << "Value of x:" << x << "and y:" << y;
}

//                          Importing all the libraries
#include <bits/stdc++.h>
// THis is more covenient 


//                          Datatypes
// Order of size :-  int  <  long  <  long long
//                  float  <  double  <  long double
// for charachter, use "string",BUT it only takes one word per variable
// To take the whole line/string , an internal fxn named "getline" is used 

#include <bits/stdc++.h>
using namespace std;

int main(){

    string str;
    getline(cin,str);

    string ch="A";          // Always use double quotes for string

    char ch='a';            // Always use single quotes for char

    cout << str;
    return 0;
}
*/

//                          IF-ELSE Starements
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    if (x>18){
        cout << "Adult";
    }
    else if(x==18){
        cout << "Reached adulthood";
    }
    else{
        cout << "Child";
    }
    return 0;
}
// use of "&&",else if ladder,nested if else,switch