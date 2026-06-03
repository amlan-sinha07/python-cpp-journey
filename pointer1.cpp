#include <iostream>
using namespace std;

void double_value(int* n){
    *n *= 2;
}
int main(){
    int x=10;
    cout<<x<<endl;
    double_value(&x);
    cout<<x<<endl;
    return 0;
}