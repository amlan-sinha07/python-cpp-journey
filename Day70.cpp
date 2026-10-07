#include <iostream>
#include <set>
#include <climits>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = 
    tree <T,
          nulltype,
          less<T>,
          rb_tree_tag,
          tree_order_statistics_node_update>;
int main() {

    // find the successor of every element 
    int a1[] = {4, 2, 7, 1, 5};
    int n1 = 5 ;
    set<int>s1(a1,a1+n1);
    for (int x : a1){
        auto it1 = s1.upper_bound(x);
        cout << x << " - > ";
        if (it1 == s1.end()){
            cout << "none\n";
        } else {
            cout << *it1 << '\n';
        }
    }  
    // minimum absolute value 
    int a[] = {10, 3, 20, 7, 15};
    int n = 5 ;
    set<int>s(a,a+n);
    auto prev=s.begin();
    int ans=INT_MAX;
    for (auto it = next(s.begin()); it != s.end() ; ++it){
        ans = min(ans, *it - *prev);
        prev = it ;
    }
    cout << ans ;
    return 0;
}