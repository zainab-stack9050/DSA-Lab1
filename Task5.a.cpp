#include <iostream>
using namespace std;
//function to swap the values
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a=5, b=10, *pa=&a, *pb=&b;
    cout << "Value of a: " << *pa << endl;        //Values before swapping
    cout << "Value of b: " << *pb << endl;
    swap(pa,pb);        //calling the function
    cout << "Value of a: " << *pa << endl;        //Values after swapping
    cout << "Value of b: " << *pb << endl;
    return 0;}