# Matrix Algebra with SymPy (Symbolic):Defining symbolic matrices using sp.
# Matrix.Matrix addition, multiplication, transpose (.T), determinant (.det()), and matrix inversion (.inv()).
# Solving linear system $Ax = B$ using matrix inversion ($x = A^{-1}B$).
# Transition to NumPy (Numerical Computing):Creating 1D arrays and 2D matrices (np.array).
# Array shape, indexing, slicing, and reshaping.Element-wise operations vs. Matrix Dot Product (np.dot or @).
# Why this matters for placements:Core Roles (Embedded/Automation): Essential for state-space control models,
# Kalman filters, and sensor data arrays.IT/Software Roles: Crucial for DSA array manipulation, 
# dynamic programming grid problems, and data science interviews.
#symbolic matrix algebra with sympy 
import sympy as sp
x,y=sp.symbols('x y')
A=sp.Matrix([[1,2],[3,4]])

B=sp.Matrix([[x,0],[0,y]])
A_trans=A.T
A_det=A.det()

A_inv=A.inv()
C=A*B
print("Inverse of A:\n",A_inv)

print("Symbolic product A*B: \n",C)
D=sp.Matrix([[2,3],[5,4]])
E=sp.Matrix([8,13])

X=D.inv()*E
print(X)

import numpy as np
arr1d=np.array([10,20,30,40,50,60])
arr2d=np.array([[1,2,3],[4,5,6]])

print("Original Shape: ",arr1d.shape)
reshaped=arr1d.reshape(2,3)
print(reshaped)

#indexing and slicing crucial for matrix & image processing
grid=np.array([
    [10,11,12,13],
    [20,21,22,23],
    [30,31,32,33]
])
sub_grid=grid[0:2,1:3]
print(sub_grid)

#critical difference element wise vs matrix dot product
X1=np.array([[1,2,],[3,4]])
X2=np.array([[5,6],[7,8]])

elem_prod=X1*X2
print(elem_prod)

matrix_prod=X1 @ X2
print(matrix_prod)

# Tomorrow, move directly into **Pandas & Matplotlib/Seaborn**—the natural next step after NumPy for working with
#  real-world data and signals.

# **Tomorrow's Focus Areas (Short & High-ROI):**

# 1. **Pandas Core Data Structures:** `Series` (1D) and `DataFrame` (2D).
# 2. **Data Manipulation:** Loading CSVs, filtering rows, handling missing values (`NaN`), and grouping data
#  (`.groupby()`).
# 3. **Data & Signal Visualization:** Plotting 2D matrix outputs, sensor trends, and time-series data using
#  `matplotlib.pyplot` (`plt.plot`, `plt.scatter`, `plt.imshow`).

# **Why It Matters for Placements:**

# * **Core (Embedded/Automation):** Filtering noise from incoming time-series sensor data and visualizing system
#  responses (bode plots, step responses, telemetry log analysis).
# * **IT/Data/SDE:** The baseline standard for data handling in technical assessments, data pipelines, and AI/ML 
# interviews.

# Rest up and close for the night—great work today! Tomorrow we'll turn these raw matrices into structured data 
# and visual plots.
