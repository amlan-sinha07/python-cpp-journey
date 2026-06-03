#include <iostream>
using namespace std;

int main(){
    int age=19;
    int* ptr=&age;

    cout<<"value of age "<<age<<endl;
    cout<<"address of age "<<&age<<endl;
    cout<<"ptr hold adress "<<ptr<<endl;
    cout<<"ptr value "<<*ptr<<endl;

    *ptr=25;
    cout<<"age after modification "<<age<<endl;

    return 0;
}
