def countdown(n):
    if n==0:
        print("Stop")
        return
    print(n)
    countdown(n-1)
print(countdown(5))

def power_fn(n,x):
    if x==0:
        return 1
    if n==0:
        return 0
    print(f"{n^x}   =   {n**x}")
    return n**x
print(power_fn(5,6))

def fast_power_fn(n,x):
    if x==0:
        return 1
    if n==0:
        return 0
    if x<0:
        return 1/fast_power_fn(n,-x)
    half=fast_power_fn(n,x//2)
    if x%2==0:
        return half*half
    else:
        return n*half*half 
print(fast_power_fn(4,6))

def sum(n):
    if n==0:
        return 0
    print(f"sum({n})={n}+sum({n-1})")
    return n+sum(n-1)
print(sum(5))

def factorial(n):
    if n==0:
        return 1
    print(f"factorial({n})={n}x factorial({n-1})")
    return n* factorial(n-1)
print(factorial(5))

def fibonnaci(n):
    if n==0:
        return 0
    if n==1:
        return 1
    
    return fibonnaci(n-1)+fibonnaci(n-2)
for i in range(25):
    print(fibonnaci(i),end=" ")

def fibonnaci(n,memo={}):
    if n in memo:
        return memo[n]
    if n==1:
        return 1
    if n==0:
        return 0
    memo[n]=fibonnaci(n-1)+fibonnaci(n-2)
    return memo[n]
print("\n")
for i in range(25):
    print(fibonnaci(i),end=" ")