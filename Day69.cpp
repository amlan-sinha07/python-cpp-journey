#include <iostream>
#include <set>
using namespace std;
int main(){
    //int n;
    //int a[] = {2, 5, 8, 12, 15};
    //set <int> s = {2, 5, 8, 12, 15} ;
    set<int>s = {1, 4, 6, 10, 15};
    int q ;
    cin >> q ;
    while(q--){
        int x ;
        cin >> x ;
        auto it = s.lower_bound(x);
        if (it == s.end()){
            cout << "No such element\n";
        } else {
            cout << *it << '\n' ;
        }
    }
    // int x = 9 ;
    // auto it = s.lower_bound(x) ;
    // if (it == s.begin()){
    //     // no element <= x
    // } else {
    //     --it ;
    //     cout << *it ;
    // }
    //int n = 5 ;
    //cout << "how many numbers = "<< endl;
    //cin >> n ;
    //set<int>s;
    // if ( it != s.end()){
    //     cout<< *it ;
    // } else {
    //     cout << "No such element !";
    // }
    // for (int i=0; i<n ; i++){
    //     if (s.find(a[i]) != s.end()) {
    //         cout << "Duplicate Found !! \n";
    //         return 0;
    //     }
      //  int x;
        //cin >> x;
        //s.insert(x);
    //     s.insert(a[i]);
    // }
    // for (int x: s){
    //     cout << x << " ";
    // }
    // cout << "No duplicate ";
    return 0;
}