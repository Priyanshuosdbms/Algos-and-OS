#include<iostream>
using namespace std;

struct component
{
  unsigned freq : 16;
  unsigned int pw : 24;
  unsigned int amp : 16;
  unsigned int toa : 48;
  unsigned int mod : 8;
  //struct component *next;

};

int main()
{
    component cst;
    cst.freq = 2;
    cst.pw = 4;
    cst.amp = 5;
    cst.toa = 9;
    cst.mod = 1;
    cout << "Size of int : "<< sizeof(int) <<endl;
    cout << "Size of struct component :" <<sizeof(cst);
    return 0;   
}