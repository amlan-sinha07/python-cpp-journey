#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    int a1[] = {1, 5, 9, 13};
    int n1 = 4;
    int k = 4;
    set<int> s1(a1, a1 + n1);

    bool found = false;
    for (int x : a1) {
        if (s1.find(x - k) != s1.end()) {
            found = true;
            break;
        }
    }
    cout << (found ? "YES" : "NO") << '\n';

    set<int> s2;
    int a2[] = {4, 7, 2, 4, 9};
    for (int x : a2) {
        if (s2.find(x) != s2.end()) {
            cout << x << " already exists\n";
        } else {
            s2.insert(x);
            cout << x << " inserted\n";
        }
    }

    set<int> s3;
    int a3[] = {5, 2, 8, 1, 10};
    for (int x : a3) {
        s3.insert(x);
        cout << x << " Min = " << *s3.begin()
             << ", Max = " << *s3.rbegin() << '\n';
    }

    int a4[] = {1, 4, 8, 12, 17};
    int x2 = 10;
    set<int> s4(a4, a4 + 5);
    auto it1 = s4.lower_bound(x2);
    if (it1 == s4.begin()) {
        cout << *it1 << '\n';
    } else if (it1 == s4.end()) {
        cout << *prev(s4.end()) << '\n';
    } else {
        int right = *it1;
        int left = *prev(it1);
        if (x2 - left <= right - x2) {
            cout << left << '\n';
        } else {
            cout << right << '\n';
        }
    }

    int a5[] = {4, 2, 7, 1, 5};
    set<int> s5(a5, a5 + 5);
    for (int x : a5) {
        auto it2 = s5.lower_bound(x);
        cout << x << " -> ";
        if (it2 == s5.begin()) {
            cout << "none\n";
        } else {
            --it2;
            cout << *it2 << '\n';
        }
    }

    int a6[] = {4, 2, 7, 1, 5};
    set<int> s6(a6, a6 + 5);
    for (int x : a6) {
        auto it3 = s6.upper_bound(x);
        cout << x << " -> ";
        if (it3 == s6.end()) {
            cout << "none\n";
        } else {
            cout << *it3 << '\n';
        }
    }

    set<int> s7 = {2, 5, 8, 12, 15};
    set<int> s8 = {1, 4, 6, 10, 15};
    set<int> s9 = {1, 3, 5, 7, 9, 11, 15};
    int L = 5;
    int R = 11;
    auto left = s8.lower_bound(L);
    auto right = s8.upper_bound(R);
    int count = 0;
    for (auto it4 = left; it4 != right; ++it4) {
        ++count;
    }
    cout << "Count in range [" << L << ", " << R << "] = " << count << '\n';

    int q;
    cout << "Enter q: ";
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        auto it5 = s9.lower_bound(x);
        if (it5 == s9.end()) {
            cout << "No such element\n";
        } else {
            cout << *it5 << '\n';
        }
    }

    int x1 = 9;
    auto it6 = s7.lower_bound(x1);
    if (it6 == s7.begin()) {
        cout << "No element <= " << x1 << '\n';
    } else {
        --it6;
        cout << "Largest element <= " << x1 << " is " << *it6 << '\n';
    }

    int n4;
    cout << "how many numbers = ";
    cin >> n4;

    set<int> s10;
    for (int i = 0; i < n4; ++i) {
        int x;
        cin >> x;
        if (!s10.insert(x).second) {
            cout << "Duplicate Found !!\n";
            return 0;
        }
    }

    cout << "Set elements: ";
    for (int x : s10) {
        cout << x << ' ';
    }
    cout << "\nNo duplicate\n";
    return 0;
}