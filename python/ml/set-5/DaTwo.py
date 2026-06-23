
from scipy import linalg
import numpy as np
def Two():


    A = np.array([
        [1, 2, 3],
        [4, 5, 6]
    ])
    
    B = np.array([10, 20, 30])
    
    solution = linalg.solve(A,B)
    
    print(solution)
    print(solution[0])
    print(solution[1])



