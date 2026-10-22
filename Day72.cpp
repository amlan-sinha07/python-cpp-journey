#include <iostream>
#include <set>
#include <vector> 
#include <stack>
using namespace std;

vector <int> nextGreaterBruteFore(const vector<int>& arr){
    int n = static_cast<int>(arr.size());
    vector<int>ans(n,-1);

    for (int i= 0; i<n ;i++){
        for (int j= i+1;j<n;j++){
            if (arr[i]<arr[j]){
                ans[i]=arr[j];
                break ;
            }
        }
    }
    return ans;
}
vector <int> nextGreaterElement(const vector<int>& arr){
    int n = static_cast<int>(arr.size());
    vector <int> ans(n,-1);
    stack <int> st;

    for (int i = n-1 ; i >= 0 ; i--){
        while ( !st.empty() && arr[st.top()] <= arr[i] ){
            st.pop() ;
        }
        if ( !st.empty() ){
            ans[i] = arr[st.top()] ; 
        }
        st.push(i) ;
    }
    return ans ;
}
vector <int> nextSmallerElement(const vector<int>& arr) {
    int n = static_cast <int> (arr.size()) ;
    vector <int> ans (n , -1);
    stack <int> st ;

    for (int i = 0 ; i < n ; i++ ) {
        while (!st.empty() && arr[st.top()] > arr[i]){
            ans[st.top()] = arr[i] ; 
            st.pop();
        }
        st.push(i) ;
    }
    return ans ;
}
int main() {
    // next smaller element
    cout << "NEXT SMALLER ELEMENT\n";
    vector <int> arr_2 = {5,3,8,2,6,1} ;
    vector <int> ans_2 = nextSmallerElement(arr_2) ;
    for (int x : ans_2) {
        cout << x << ' ';
    }

    cout << '\n';
    // Next greater Element
    cout << "NEXT GREATER ELEMENT\n"; 
    
    vector <int> arr_1 = {2, 1, 4, 3} ;
    vector <int> ans_1 = nextGreaterElement(arr_1);

    for (int x : ans_1) {
        cout << x << ' ';
    }
    cout << '\n' ;
    // Brute Force next Greater Element

    cout << "BRUTE FORCE NEXT GREATER ELEMENT\n";

    vector<int> arr ={4, 5, 2, 10, 8};
    vector <int> ans = nextGreaterBruteFore(arr);

    for (int x : ans){
        cout << x << ' ';

    }
    cout << '\n' ;
    // Dynamic set queries
    // set<int>s;

    // int q;
    // cin >> q;

    // while (q--){
    //     int type, x;
    //     cin >> type >> x;

    //     if (type==1){
    //         s.insert(x);

    //     }
    //     else if (type==2){
    //         s.erase(x);
    //     }
    //     else if (type==3){
    //         auto it = s.lower_bound(x);
            
    //         if (it == s.end()){
    //             cout << "-1" << '\n';
    //         } else {
    //             cout << *it << '\n';
    //         }
    //     } else if (type == 4){
    //         auto it = s.upper_bound(x);

    //         if (it == s.begin()){
    //             cout << -1 << '\n';
    //         } else {
    //             --it ;
    //             cout << *it << '\n';
    //         }
    //     }

    // }
 
    return 0;
}