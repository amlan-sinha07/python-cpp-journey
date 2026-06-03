#include <iostream>
#include <stdexcept>
using namespace std;

float divide(float a,float b){
    if (b==0){
        throw runtime_error("cant divide by zero");
    }
    return a/b;
}
int main(){
    try{
        cout<<divide(10,2)<<endl;
        cout<<divide(10,0)<<endl;
    }
    catch (runtime_error& e){
        cout<<"error: "<<e.what()<<endl;    
    }
    return 0;
}