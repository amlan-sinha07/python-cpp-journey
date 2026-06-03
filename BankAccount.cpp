#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class BankAccount {
    private:
    string name;
    float balance;
    
    public:
    BankAccount(string n,float b){
        if (b<0) throw invalid_argument("balance cannot be negative");
        name=n;
        balance=b;
    }
    void deposit(float amount){
        if (amount<=0) throw invalid_argument("amount must be positive");
        balance+=amount;
        cout<<"current balance "<<balance<<endl;
    }
    void withdraw(float amount){
        if (amount<=0) throw invalid_argument("amount must be positive");
        if (amount>balance) throw runtime_error("insufficient funds");
        balance-=amount;
        cout<<"current balance "<<balance<<endl;
    }
    void show_balance(){
        cout<<name<<"'s balance: "<<balance<<endl;
    }
};
int main(){
    try{
        BankAccount a1("Amlan",5000);
        a1.deposit(5000);
        a1.withdraw(2000);
        a1.show_balance();
        a1.deposit(-500);
        a1.withdraw(10000000);
    }
    catch (invalid_argument& e){
        cout<<"invalid "<<e.what()<<endl;
    }
    catch (runtime_error& e){
        cout<<"invalid "<<e.what()<<endl;
    }
}