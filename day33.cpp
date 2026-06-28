#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <set>




int main() {
    std::map< std::string , std::pair<int,int>> student;
    std::cout << "\nhow many students data do you want to input ? " ;
    int n5 ;
    std::cin >> n5 ;
    for ( int i5 = 0 ; i5 < n5 ; i5++ ) { 
        std::cout << "\nenter " << i5 + 1 << " name : " ;
        std::string  s5 ;
        std::cin >> s5 ;
        std::cout << "\nenter " << i5 + 1 << " marks : ";
        int f5 ;
        std::cin >> f5 ;
        if ( student.count(s5)==0 || f5> student[s5].first ) {
            student[s5].first = f5 ;
        }
        student[s5].second++ ;
    }
    for ( auto& pair : student ) {
        std::cout << pair.first << " "<< pair.second.first << "\n" ;
    }
    for (auto& pair : student ) {
        std::cout << "\n" << pair.first << " appeared " << pair.second.second << " times "<< "\n" ;
    }




    std::set < int > s;
    int n3 ;
    std::cout << "\nhow many elements you want to enter : ";
    std::cin >> n3;
    for ( int i3 = 0 ; i3 < n3 ; i3++) {
        std::cout << "\nenter "<< i3+1 << " number = ";
        int n4;
        std::cin >> n4;
        s.insert(n4) ;
    }
    std::cout << "\nset : " ;
    for ( int x3 : s) {
        std::cout << x3 <<" ";
    }



    std::vector < int > v ;
    int n ;
    std::cout << "\nenter how many numbers: " ;
    std::cin >> n ;
    for (int i =0 ; i<n ; ++i ) {
        int x ;
        std::cout << "\nenter " << i + 1 << " integer for list: " ;
        std::cin >> x ;
        v.push_back(x) ;
    }
    for ( int f = (int)v.size()-1 ; f>=0 ; --f)
    {
        std::cout<<"\nreversed: "<<v[f]<<"\n";
    }
    if ( !v.empty() ) {
    int maxval = v[0] ;
    for (int p=1 ; p< (int)v.size() ; ++p){
        if ( v[p] >= maxval) {
            maxval = v[p] ;
        }       
    }
    std::cout << "\nmax value: " << maxval ;
    }



    std::map < std::string , int > m1 ;
    int n1 ;
    std::cout << "\nhow many strings you will enter ? ";
    std::cin >> n1;
    for (int i=0; i<n1 ; ++i) {
        std::cout << i << ".enter string: " << "\n";
        std:: string m2;
        std:: cin >> m2;
        m1[m2]++ ;
    }
    std::cout << "\nshowing frequencies : " << "\n" ;
    for ( auto& pair : m1 ) {
        std::cout << pair.first << " " << pair.second << "\n" ;
    }
    // std::string  word ;
    // while (std::cin >> word) {
    //     m1[word]++ ;
    // }
    return 0;
}