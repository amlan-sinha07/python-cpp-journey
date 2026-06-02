class Person:
    def __init__(self,name,age):
        self.name=name
        self.age=age    
    def introduce(self):
        print(f"hi i am {self.name}, {self.age} years old")
    
class Student(Person):
    def __init__(self,name,age,grade):
        super().__init__(name,age)
        self.grade=grade
        self.subjects=[]
        self.marks=[]
    def study(self):
        print(f"{self.name} is studying Grade {self.grade}")
    def add_marks(self,sub,mark):
        self.marks.append(mark)
        self.subjects.append(sub)
    def get_average(self):
        if not self.marks:
            return 0
        return sum(self.marks)/len(self.marks)
    def print_report(self):
        self.introduce()
        print(f"Grade {self.grade}")
        for sub,mark in zip(self.subjects,self.marks):
            print(f"{sub} -> {mark}")
        print(self.get_average())

class Teacher(Person):
    def __init__(self,name,age,subject):
        super().__init__(name,age)
        self.subject=subject
        self.students=[]
    def add_student(self,student):
        self.students.append(student)
    def class_average(self):
        if not self.students:
            return 0
        total=0
        for student in self.students:
            total+=student.get_average()
        return total/len(self.students) 
    def print_class(self):
        print(f"{self.name} -> {self.subject}")
        for s in self.students:
            print(f"Student {s.name} | Grade {s.grade}")
        print(f"Average {self.class_average()}")
        
s1=Student("Amlan",19,"A")
s2=Student("Riya",17,"B")
t1=Teacher("Mr. Roy",35,"Physics")

s1.add_marks("Physics",92)
s1.add_marks("maths",88)

t1.add_student(s1)
t1.add_student(s2)

s1.print_report()
t1.print_class()