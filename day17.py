squares=[i**2 for i in range(1,11)]
print(squares)

evens=[i for i in range(1,21) if i%2==0]
print(evens)

words=["hello","world","python"]
upper=[w.upper() for w in words]
print(upper)

marks=[58,90,98,10,48,93,85,70]
passed=[m for m in marks if m>=60]
print(passed)

cubes=[i**3 for i in range(1,11)]
print(cubes)

words=["cat","python","dog","elephant","programming"]
alphabet_count=[i for i in words if len(i)>=4]
print(alphabet_count)

marks_1=[85,42,78,55,92]
extra_credits=[i*2 for i in marks_1]
print(extra_credits)

numbers=[3,-1,7,-5,2,-8,9,-3]
negative_numbers=[i for i in numbers if i<0]
print(negative_numbers)

square_1=lambda x: x**2
print(square_1(5))

add=lambda a,b: a+b
print(add(3,4))

is_even=lambda n: True if n%2==0 else False
print(is_even(4))
print(is_even(7))

students=[("Amlan",90),("Riya",78),("dev",80)]
sorted_students=sorted(students,key=lambda x:x[1],reverse=True)
print(sorted_students)

numbers_1=[1,2,3,4,5]
square_2=list(map(lambda x:x**2,numbers_1))
print(square_2)

evens_1=list(filter(lambda x:x%2==0,numbers_1))
print(evens_1)

marks_2=[85,42,78,55,82,38,67]
students_1=["Amlan","Riya","Mia","Dev","Sara","Raj","Tom"]
marks_above_60=list(filter(lambda x:x[1]>60, zip(students_1,marks_2)))
for stud,mark in marks_above_60:
    print(stud," -> ",mark)

adding_5_marks=list(map(lambda x:(x[0],x[1]+5),zip(students_1,marks_2)))
for stud,mark in adding_5_marks:
    print(f"after adding 5 marks to each\n {stud} -> {mark}")

sorting_alphabetically=sorted(adding_5_marks,key=lambda x:x[0])
print(sorting_alphabetically)

marks_descending=sorted(adding_5_marks,key=lambda x:x[1],reverse=True)
print(marks_descending)