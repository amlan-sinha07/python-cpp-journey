#include <iostream>
#include <vector>
#include <string>
#include <numeric> 
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

class Person{
    protected:
    string name;
    int age;
    
    public:
    string get_name() const {return name;}
    int get_age() const {return age;}
    Person (string n, int a):name(n),age(a){}

    virtual ~Person() {}

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
    string get_grade() const {return grade;}
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
void save_all_students(const vector<Student*>&student_list) {
        ofstream file("student.txt");
        if (!file){
            throw runtime_error("database is missing!");
        }

        for (auto student:student_list){
            file<<student->get_name()<<","<<student->get_age()<<","<<student->get_grade()<<endl;
    
    }
    cout<<"\n[system: database syncronised succesfully!]"<<endl;
    file.close();
}
void load_students_from_files(){
    ifstream file("student.txt");
    if (!file){
        throw runtime_error("database file missing");
    }
    string line;
    cout<<"\n-----reconstructed csv roster (industrial csv loaded)-----"<<endl;

    while (getline(file,line)){
        if (line.empty())  continue;
        stringstream ss(line);
        string name,age_str,grade;
        getline(ss,name,',');
        getline(ss,age_str,',');
        getline(ss,grade,',');
        if (!age_str.empty()){
            int age=stoi(age_str);
            cout<<"loaded "<<"("<<age<<")"<<" grade "<<grade<<endl;
        }
        else{
            cout<<"[skip the unseperable part: "<<line<<"]"<<endl;
        }
    }
file.close();
}
int main(){
    Student s1("Amlan",19,"A");
    Student s2("Riya",17,"A");
    Teacher t1("Mr.Roy",45,"maths");

    s1.add_marks("physics",92);
    s1.add_marks("maths",88);
    s2.add_marks("physics",90);
    s2.add_marks("maths",86);

    s1.print_report();
    s2.print_report();
    t1.add_student(&s1);
    t1.add_student(&s2);
    t1.print_class();
    vector<Student*>roster={&s1, &s2};
    
    try{
        save_all_students(roster);
        
        load_students_from_files();
    }
    catch (const runtime_error& e){
        cout<<"caught exception: "<<e.what()<<endl;
        cout<<"system action creating a fresh new 'student.txt' database file"<<endl;
    
        ofstream new_file("student.txt");
        new_file.close();
    }
    return 0;
}