#day 72
#understanding symbols the core concept
import sympy as sp

#declare single symbol
x=sp.Symbol('x')
y=sp.Symbol('y')

#declare multiple symbols at once (most common way)
x,y,z=sp.symbols('x y z')

#define algebric expressions
expr=x**2 + 2*x+ 1

print(expr)


#basic algebric expressions

a1=sp.expand((x+2)**2)
print(a1)

a2=sp.factor(x**2-y**2)
print(a2)

a3=sp.simplify(sp.sin(x)**2+sp.cos(x)**2)
print(a3)

a4=expr.subs(x,3)
print(a4)

#solving equations
equation=sp.Eq(x**2-2**3,0)
solutions=sp.solve(equation,x)

print("solutions: ",solutions)

