import functools
def my_decorator(func):
    def wrapper():
        print("before function runs")
        func()
        print("after function runs")
    return wrapper
@my_decorator
def greet():
    print("hello!")
greet()
import time
def timer(func):
    def wrapper(*args,**kwargs):
        start=time.time()
        result=func(*args,**kwargs)
        end=time.time()
        print(f"{func.__name__} took {end-start:.4f} seconds")
        return result
    return wrapper
@timer 
def slow_function():
    time.sleep(1)
    print("done!")
#@timer
#def fibonacci(n):
#   if n<=1:
#       return n
#    return fibonacci(n-1)+fibonacci(n-2)
@timer
def fibonacci_fast(n,memo={}):
    if n in memo:
        return n
    if n<=1:
        return n
    memo[n]=fibonacci_fast(n-1)+fibonacci_fast(n-2)
    return memo[n]
#print(fibonacci_fast(30))
slow_function()
print(fibonacci_fast(30))
def logger(func):
    @functools.wraps(func)
    def wrapper(*args,**kwargs):
        print(f"calling {func.__name__} with args {args} ")
        result=func(*args,**kwargs)
        return result
    return wrapper
def validator(func):
    @functools.wraps(func)
    def wrapper(*args,**kwargs):
        for i in args:
            if i<0:
                print("invalid input!")
                return None
        for j in kwargs.values():
            if j<0:
                return None
        return func(*args,**kwargs)
    return wrapper
@logger
@validator
def add(a,b):
    result=a+b
    return result
print(add(9,6))
@logger
@validator
def multiply(n,x):
    result=n*x
    return result
print(multiply(6,5))