#include <iostream>
#include <string>
bool isSequence(const std::string& s,const std::string& t){
    int i=0;
    int j=0;
    while ( i<s.size() && j<t.size()){
        if (s[i]==t[j]){
            i++;
        }
        j++;
    }
    return i==s.size();
}
int countMatchedCharacters(const std::string& s,const std::string& t){
    int i=0;
    int j=0;
    int count =0;
    while(i <s.size() && j<t.size()){
        if (s[i] == t[j]){
            i++ ;
            count++ ;
        }
        j++ ;
    }
    return count;
}
int countUnmatched(const std::string& s , const std::string& t){
    int i=0;
    int j=0;
    int matched = 0;
    while (i<s.size() && j<t.size()){
        if (s[i]==t[j]){
            i++ ;
            matched++ ;
        }
        j++ ;
    }
    return s.size()-matched ;
}
int main() {
    std::cout<< std::boolalpha;
    
    std::cout<<isSequence("ace","abcde")<<'\n';
    std::cout<<isSequence("aec","abcde")<<'\n';
    std::cout<<isSequence("","abcde")<<'\n';

    std::cout<<isSequence("aab","bbaaaab")<<'\n';

    std::cout<<countMatchedCharacters("abc","axbyrc")<<'\n';
    std::cout<<countMatchedCharacters("abc","amnblldcoi")<<'\n';

    std::cout<<countUnmatched("abc","axbyc")<<'\n';

    return 0;
}