#day 73
import sympy as sp
#first task

x=sp.Symbol('x')
p=x**3-6*x**2+11*x-6
a1=sp.factor(p)

print(a1) #(x - 3)*(x - 2)*(x - 1)
#task 2
x,y=sp.symbols('x y')

a2=x**2+3*x*y+y**2
a3=a2.subs({x:2,y:-1})
print(a3)

#returns -1
#task 3
a4=sp.Eq(2*x+y,8)

a5=sp.Eq(x-y,1)
a6=sp.solve([a4,a5],[x,y])
print(a6)

#it returns {x: 3, y: 2}
#task 4
a7=sp.Eq(x**2+4,0)

a8=sp.solve([a7],[x])
print(a8)
#returns [(-2*I,), (2*I,)]

a9=sp.sin(x)*sp.exp(x)
a10=sp.diff(a9,x)
print(a10)

#exp(x)*sin(x) + exp(x)*cos(x)
a11=sp.integrate(a10,x)
print(a11)

#exp(x)*sin(x)