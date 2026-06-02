try:
    age=int(input("enter your age= "))
    a=100/age
    print(f"your age is {a}")
except ValueError:
    print("please enter integer not text !")
except ZeroDivisionError:
    print("age can't be zero!")
finally:
    print("program executed!")