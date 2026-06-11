def get_grade(marks):
    if marks>=90:
        return "A"
    elif marks>=80:
        return "B"
    elif marks>=70:
        return "C"
    elif marks>=60:
        return "D"
    else:
        return "F"
def class_average(marks_list):
    return sum(marks_list)/len(marks_list)
def top_student(names,marks):
    index=marks.index(max(marks))
    return names[index]
def passed_students(names,marks):
    passed=[name for name,mark in zip(names,marks) if mark>60]
    return passed