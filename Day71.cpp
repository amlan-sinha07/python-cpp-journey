#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set=
tree<T, // int values
null_type, // matching maybe 
less<T>, // greater does the opposite
        // less equal does the multiset work
rb_tree_tag, // arbitary
tree_order_statistics_node_update>; // i am not sure about this

int main(){
    // Dynamic Rank Query
    // insert x
    // delete x
    // query x
    // set = {2, 5, 8, 10}
    // query 8 
    // answer 2
    // because 2 , 5 < 8 
    // O (log n)
    ordered_set <int> s;
    s.insert(2);
    s.insert(5);
    s.insert(8);
    s.insert(10);

    cout<< s.order_of_key(8) <<'\n';
    // order_of_key returns no. of elements strictly smaller than 8

    // 24. k-th smallest element
    // insert(x)
    // erase(x)
    // k-th smallest element
    // s = {2,5,8,10,15}
    // ans = 8
    // 3rd smallest element
    // O(log n)
    ordered_set <int> s1 ;
    s1.insert(2);
    s1.insert(5);
    s1.insert(8);
    s1.insert(10);
    s1.insert(15);
    int k = 3 ;
    cout << *s1.find_by_order(k-1)<<'\n';

    // median in a data stream
    // two heaps -> standard solution
    // pbds -> order-statistics solution 

    // sliding window maximum and minimum

    // O(log n)
    // O( N log n)
    vector <int> a1 = {1,3,-1,-3,5,3,6,7};
    int k1 = 3;
    multiset <int> ms;
    for (int i=0; i<k1 ; i++){
        ms.insert(a1[i]);
    }
    for (int i=k1; i<=a1.size(); i++){
        cout<< "Min = "<<*ms.begin()<<'\t';
        cout << "Max = "<<*ms.rbegin()<<'\n';
        if (i==a1.size()){
            break;


        }
        ms.erase(ms.find(a1[i-k]));
        ms.insert(a1[i]);

    }
    // sliding window median

    // detect overlapping intervals

    // sorting O(n log n)
    // scanning O(n)
    // overall O(n log n)
    vector<pair<int,int>> intervals = {
        {1,5},
        {4,8},
        {7,10}
    };
    sort(intervals.begin(),intervals.end());
    for(int i=1;i<intervals.size();i++){
        if (intervals[i].first<=intervals[i-1].second){
            cout << "Overlap exists";
            return 0;
        }
    }
    cout << "No overlaps";
    return 0;
}