
from sklearn.tree import DecisionTreeClassifier
import numpy as np
def Two():
    x = np.array([[1],[2],[3],[4],[5],[6]])
    y = np.array([0,0,0,1,1,0])

    # Train
    model = DecisionTreeClassifier()

    model.fit(x,y)


    new_student = np.array([[3.5]])

    prediction = model.predict(new_student)
    print("Prediction",prediction[0])
    if prediction==0:
        print("FAIL")
    else:
        print("PASS")

    pass


def Three_ACTUALY_TWO():

    
    A = np.array([[1, 2],
                  [3, 4]])
    
    B = np.array([[5, 6],
                  [7, 8]])
    
    print("Matrix A:")
    print(A)
    
    print("\nMatrix B:")
    print(B)
    
    # Arithmetic Operations
    print("\nAddition:")
    print(A + B)
    
    print("\nSubtraction:")
    print(A - B)
    
    print("\nMultiplication:")
    print(A * B)
    
    print("\nDivision:")
    print(A / B)
    
    # Matrix Operations
    print("\nMatrix Product:")
    print(np.dot(A, B))
    
    print("\nTranspose of A:")
    print(A.T)
    
    print("\nDeterminant of A:")
    print(np.linalg.det(A))
    
    print("\nInverse of A:")
    print(np.linalg.inv(A))
