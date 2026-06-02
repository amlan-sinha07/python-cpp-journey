#include <iostream>
#include <vector>
#include <string>
#include <numeric> 

using namespace std;

class Person{
    protected:
    string name;
    int age;
    public:
    Person (string n, int a):name(n),age(a){}

    void introduce(){
        cout<<"Hi i am "<<name<<" , "<<age<<" years old .\n";
    }
};
class Student: public Person{
    private:
    string grade;
    vector<string>subjects;
    vector<double>marks;

    public:
    Student(string n,int a,string g): Person (n,a),grade(g){}
    void study(){
        cout<<name<<" is studying Grade"<<grade<<".\n";
    }
    void add_marks(string sub,int mark){
        marks.push_back(mark);
        subjects.push_back(sub);
    }
    double get_average(){
        if (marks.empty()){
            return 0.0;
        }
        double total=accumulate(marks.begin(),marks.end(),0.0);
        return total/marks.size();
    }
    void print_report(){
        introduce();
        cout<<"Grade :"<<grade<<"\n-----marks-----\n";
        for (size_t i=0;i<marks.size();++i){
            cout<<" "<<subjects[i]<<" -> "<<marks[i]<<"\n";
        }
        cout<<"Average "<<get_average()<<"\n----------\n";
    }
};
class Teacher: public Person{
    private:
    string subject;
    vector<Student*>students;
    public:
    Teacher(string n,int a,string sub): Person(n,a){
        subject=sub;
    }
    void teach(){
        cout<<"hi i am "<<name<<" teaching "<<subject<<endl;
    }
    void add_student(Student* student){
        students.push_back(student);
    }
    double class_average(){
        if (students.empty()) return 0.0; 
        double total=0.0;
        for (size_t i=0;i<students.size();++i){
            total+=students[i]->get_average();
        }
        return total/students.size();
    }
    virtual void print_class(){
        introduce();
        cout<<"subject: "<<subject<<endl;
        for (auto student:students){
            student->introduce();
        }
        cout<<"average "<<class_average()<<endl;
    }
};
int main(){
    Student s1("Amlan",19,"A");
    Student s2("Riya",17,"A");
    Teacher t1("Mr.Roy",45,"maths");

    s1.add_marks("physics",92);
    s1.add_marks("maths",88);
    s2.add_marks("physics",90);
    s2.add_marks("maths",86);
    s2.print_report();
    t1.add_student(&s1);
    t1.add_student(&s2);
    t1.print_class();
    s1.print_report();
    return 0;
}