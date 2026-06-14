#include <iostream>
#include <set>
#include <vector>
using namespace std;
template <typename T>
T get_max(T a ,T b){
    return (a>b) ? a:b ;
}
template <typename T>
T get_min(T a, T b){
    return (a<b) ? a:b ;
}
template <typename T, typename U>
void print_pair(T a,U b){
    cout<<a<<" and "<<b<<endl;
}
template <typename T>
void print_array(vector<T>arr){
    for (T x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}
int main(){
    cout<<get_min(5,10)<<endl;
    cout<<get_min(3.7,1.2)<<endl;

    vector<int>nums={1,2,3};
    vector<string>names={"Amlan","Anand"};

    print_array(nums);
    print_array(names);

    print_pair(5,'x');
    print_pair(0.5,"hello");

    cout<<get_max(5,10)<<endl;
    cout<<get_max(3.5,2.1)<<endl;
    cout<<get_max('a','z')<<endl;
    cout<<get_max(string("abc"),string("xyz"));

    set<int>s;
    s.insert(5);
    s.insert(3);
    s.insert(1);
    s.insert(7);
    s.insert(5);

    for (int x:s){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<s.count(5)<<endl;
    cout<<s.size()<<endl;
    if (s.count(5)){
        cout<<"5 is in the set"<<endl;

    }
    pair<string,int>student("Amlan",92);

    cout<<student.first<<endl;
    cout<<student.second<<endl;
    vector<pair<string,int>>students;
    students.push_back({"Amlan",92});
    students.push_back({"Anand",78});
    for (auto& s:students){
        cout<<s.first<<"->"<<s.second<<endl;

    }
    return 0;
}