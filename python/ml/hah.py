from scipy import linalg
import numpy as np

# Coefficient matrix
A = np.array([
    [2, 1],
    [1, 3]
])

# Constant matrix
B = np.array([5, 6])

# Solve
solution = linalg.solve(A, B)

print("Solution:")
print("x =", solution[0])
print("y =", solution[1])
