#
# from sklearn.neighbors import KNeighborsClassifier
# import numpy as np
# def one():
#
#     x = np.array([[1],[2],[3],[4],[5],[6]])
#     y = np.array([0,0,0,1,1,0])
#     model = KNeighborsClassifier(n_neighbors=3)
#     model.fit(x, y)
#
#     new_hours = np.array([[4]])
#     prediction_marks = model.predict(new_hours)
#
#     print("Predicted Marks:", prediction_marks[0])
#     if prediction_marks[0]==1:
#         print("PASS")
#     else:
#         print("FAIL")
#
#
#
from sklearn.neighbors import KNeighborsClassifier
import numpy as np

def One():
    
    # Training data
    X = np.array([[1], [2], [3], [5], [6], [7]])
    y = np.array([0, 0, 0, 1, 1, 1])
    
    # Create KNN model
    model = KNeighborsClassifier(n_neighbors=3)
    
    # Train model
    model.fit(X, y)
    
    # New instance
    new_student = np.array([[4]])
    
    # Predict
    prediction = model.predict(new_student)
    
    print("Prediction:", prediction[0])
    
    if prediction[0] == 1:
        print("Result: Pass")
    else:
        print("Result: Fail")
