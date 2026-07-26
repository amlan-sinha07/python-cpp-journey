#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void printlist(Node* head){
    Node* current=head;
    while(current!=nullptr){
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"nullptr"<<endl;
};
void insertathead(Node*& head,int value){
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=head;
    head=newnode;
};
void deletevalue(Node*& head,int target){
    if (head==nullptr) {
        return ;
    }
    if (head->data==target){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }

    Node* current=head;
    while(current->next != nullptr && current->next->data != target){
        current=current->next;
    }

    if (current->next!=nullptr){
        Node* temp=current->next;
        current->next=current->next->next;
        delete temp;
    }
};
Node* reverselist(Node* head){
    Node* prev=nullptr;
    Node* current=head;
    Node* next=nullptr;
    while(current!=nullptr){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return  prev;
};
bool isvalid(string s){
    stack<char>st;
    for (char c:s){
        if (c=='(' ||c=='{'||c=='['){
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            if ( (c==')' && top=='(') || (c=='}' && top=='{') || (c==']' && top=='[')){
                st.pop();

            } else { 
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    int arr[5]={10,20,30,40,50};
    int sum=0;
    int mx=arr[0];
    int count=0;
    for (int i=0;i<5;++i){
        cout<<arr[i]<<" ";
        sum+=arr[i];
        if (arr[i]>mx){
            mx=arr[i];
        }
        if (arr[i]%2==0){
            count++;
        }
    }
    for (int i=4;i>=0;--i){
        cout<<arr[i]<<" ";
    }
    cout<<sum<<"\n";
    cout<<mx<<"\n";
    cout<<count<<"\n";
    Node* head=new Node{1,nullptr};
    Node* second=new Node{2,nullptr};
    Node* head=nullptr;
    insertathead(head,30);
    insertathead(head,20);
    insertathead(head,10);
    head->data=10;
    head->next=second;
    head->next->next=new Node{3,nullptr};
    second->data=20;
    second->next=nullptr;
    printlist(head);
    cout<<"first "<<head->data<<" second "<<head->next->data<<endl;

    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    if (s.empty()){
        cout<<"stack is empty";
    }
    string str="hello";
    stack<char>s;
    for (char c:str){
        s.push(c);
    }

    string reversed="";
    while(!s.empty()){
        reversed+=s.top();
        s.pop();
    }
    cout<<reversed;
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.size();
    while (!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}