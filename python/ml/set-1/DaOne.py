from sklearn.linear_model import LinearRegression
import numpy as np

def one():
    x = [[1], [2], [3], [4], [5], [6]]
    y = [35, 45, 55, 65, 75, 85]

    model = LinearRegression()
    model.fit(x, y)

    new_hours = np.array([[6]])
    prediction_marks = model.predict(new_hours)

    print("Predicted Marks:", prediction_marks[0])
    print(model)
    print("Slope (M):", model.coef_[0])
    print("Intercept:", model.intercept_)
