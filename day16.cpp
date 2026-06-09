#include <iostream>
#include <map>
#include <cmath>

using namespace std;
void countdown(int n){
    if (n==0){
        return ;
    }
    cout<<n<<endl;
    countdown(n-1);
}
int sum(int n){
    if (n==0) return 0;
    return n+sum(n-1);
}
double power_fn(double n, double x ){
    if (n==0.0) return 0.0;
    if (x==0.0) return 1.0;
    double result=pow(n,x);
    return result;
}
double fast_power_fn(double n , double x ){
    if (n==0) return 0.0;
    if (x==0) return 1.0;
    if (x<0) return 1.0/fast_power_fn(n, -x);
    double half=fast_power_fn(n,floor(x/2));
    if (fmod(x ,2.0)==0.0) {
        return half * half;
    }
    return n * half * half;
}
int factorial(int n){
    if (n==0){
        return 1;
    }
    cout<<"factorial("<<n<<")="<<n<<"*factorial("<<n-1<<")"<<endl;
    int p=n*factorial(n-1);
    cout<<"factorial    "<<n<<"="<<p<<endl;
    return p;
}

int fibonnaci(int n){
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    return fibonnaci(n-1)+fibonnaci(n-2);
}
map<int,int>memo;
int fibonnaci_fast(int n){
    if (memo.count(n)) return memo[n];
    if (n==0) return 0;
    if (n==1) return 1;
    memo[n]=fibonnaci_fast(n-1)+fibonnaci_fast(n-2);
    return memo[n];
}
int main(){
    countdown(5);
    cout<<"sum =    "<<sum(5)<<endl;
    cout<<"power=   "<<power_fn(4.0,5.0)<<endl;
    cout<<factorial(5)<<endl;
    cout<<"fast power=  "<<fast_power_fn(6.0,7.0)<<endl;
    for (int i=0;i<30;++i){
        cout<<fibonnaci(i)<<" ";
    }
    cout<<endl;
    for (int i=0;i<30;++i){
        cout<<fibonnaci_fast(i)<<" ";
    }
    cout<<endl;
    return 0;
}