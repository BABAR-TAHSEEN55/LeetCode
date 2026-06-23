
from scipy import linalg
import numpy as np
from sklearn.ensemble import RainForestClassifier
from sklearn.ensemble import AdaBooskClassifier
def Two():


    A = np.array([
        [1, 2, 3],
        [4, 5, 6],
        [8, 5, 6]
    ])
    
    B = np.array([10, 20, 30])
    
    determinant = linalg.det(A)
    Inverse = linalg.inv(A)


    
    print(determinant)
    print(Inverse)



