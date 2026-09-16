#include <iostream>
using namespace std;
//function to swap the values
void swap(int **a,int **b){ 
    int temp;
    temp =**a;
    **a = **b;
    **b = temp;}

int main(){
    int a=5, b=10, *pa=&a, *pb=&b, **ppa= &pa, **ppb=&pb;
    cout << "Value of a: " << **ppa << endl;      //Values before swapping
    cout << "Value of b: " << **ppb << endl;      
swap(ppa,ppb);     //calling the function
    cout << "Value of a: " << **ppa << endl;      //Values after swapping
    cout << "Value of b: " << **ppb << endl;
return 0;}