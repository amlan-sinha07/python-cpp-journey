import math
import random
import os
from math_tools import square, cube , is_prime, factorial, PI
from string_tools import reverse_string, is_palindrome, word_count
from student_tools import get_grade ,class_average,top_student ,passed_students

names=["Amlan","Raya","Dev","Sara","Raj"]
marks=[92,78,55,85,60]

print(get_grade(92))
print(class_average(marks))
print(top_student(names,marks))
print(passed_students(names,marks))


print(square(5))
print(cube(3))
print(is_prime(17))
print(factorial(5))
print(PI)

print(reverse_string("hello"))
print(is_palindrome("racecar"))
print(word_count("the quick brown fox"))

print(math.sqrt(144))
print(math.pi)
print(math.floor(3.9))
print(math.ceil(3.1))

print(random.randint(1,100))
print(random.choice(["Amlan","Riya","Dev"]))

print(os.getcwd())
print(os.listdir("."))