
from sklearn.linear_model import LogisticRegression
import numpy as np
def One():
    x = np.array([[1],[2],[3],[4],[5],[6]])
    y = np.array([0,0,0,1,1,0])
    model = LogisticRegression()
    model.fit(x,y)
    new_student= np.array([[3.5]])
    prediction = model.predict(new_student)

    probability = model.predict_proba(new_student)
    print("Prection ",prediction[0])
    if prediction[0]==1:
        print("PASS")
    else:
        print("FAIL")
    print("PROBABILITY",probability)

    pass
