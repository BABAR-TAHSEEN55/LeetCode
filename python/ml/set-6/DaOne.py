from sklearn.svm import SVC
import numpy as np

def One():
    
    # Training data
    X = np.array([[1], [2], [3], [5], [6], [7]])
    y = np.array([0, 0, 0, 1, 1, 1])
    
    # Create KNN model
    model = SVC(kernel='linear')
    
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
