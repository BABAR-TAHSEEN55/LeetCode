import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from scipy.linalg import det, inv, solve
from sklearn.datasets import load_iris
from sklearn.linear_model import LinearRegression, LogisticRegression
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier

# Question 1(A)
# Linear Regression


def question_1a():
    # Sample data
    X = np.array([[1], [2], [3], [4], [5]])
    y = np.array([2, 4, 6, 8, 10])

    # Create model
    model = LinearRegression()

    # Train model
    model.fit(X, y)

    # Predict new value
    prediction = model.predict([[6]])

    print("Prediction for x = 6 :", prediction[0])


# Question 1(B)
# NumPy Broadcasting


def question_1b():
    matrix = np.array([[1, 2, 3], [4, 5, 6]])

    row = np.array([10, 20, 30])

    print("Matrix")
    print(matrix)

    print("\nRow")
    print(row)

    print("\nBroadcasted Result")
    print(matrix + row)


# Question 2(A)
# Logistic Regression


def question_2a():

    iris = load_iris()

    X = iris.data
    y = iris.target

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42, stratify=y
    )

    model = LogisticRegression(max_iter=200)

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    accuracy = accuracy_score(y_test, y_pred)

    print("Accuracy :", accuracy)


# Question 2(B)
# NumPy Arithmetic & Matrix Operations


def question_2b():

    A = np.array([[1, 2, 3], [4, 5, 6]])

    B = np.array([[7, 8, 9], [1, 2, 3]])

    print("Matrix A")
    print(A)

    print("\nMatrix B")
    print(B)

    print("\nAddition")
    print(A + B)

    print("\nSubtraction")
    print(A - B)

    print("\nElement-wise Multiplication")
    print(A * B)

    print("\nDivision")
    print(A / B)

    print("\nPower")
    print(A**2)

    print("\nTranspose")
    print(A.T)

    print("\nMatrix Multiplication")
    print(np.dot(A, B.T))


# Question 3(A)
# Decision Tree


def question_3a():

    iris = load_iris()

    X = iris.data
    y = iris.target

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42, stratify=y
    )

    model = DecisionTreeClassifier(random_state=42)

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    accuracy = accuracy_score(y_test, y_pred)

    print("Accuracy :", accuracy)


# Question 3(B)
# Pandas Line Plot & Bar Plot


def question_3b():

    data = {"Month": ["Jan", "Feb", "Mar", "Apr"], "Sales": [100, 150, 120, 180]}

    df = pd.DataFrame(data)

    print(df)

    # Line Plot
    df.plot(x="Month", y="Sales", kind="line", title="Line Plot")

    plt.show()

    # Bar Plot
    df.plot(x="Month", y="Sales", kind="bar", title="Bar Plot")

    plt.show()


# Question 4(A)
# Naive Bayes


def question_4a():

    iris = load_iris()

    X = iris.data
    y = iris.target

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42, stratify=y
    )

    model = GaussianNB()

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    accuracy = accuracy_score(y_test, y_pred)

    print("Accuracy :", accuracy)


# Question 4(B)
# Pandas Series & DataFrame


def question_4b():

    series = pd.Series([10, 20, 30, 40])

    print("Series")
    print(series)

    data = {"Name": ["Farhan", "Ahmed", "Imran"], "Age": [20, 21, 22]}

    df = pd.DataFrame(data)

    print("\nDataFrame")
    print(df)


# Question 5(A)
# K Nearest Neighbours


def question_5a():

    iris = load_iris()

    X = iris.data
    y = iris.target

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42, stratify=y
    )

    model = KNeighborsClassifier(n_neighbors=3)

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    accuracy = accuracy_score(y_test, y_pred)

    print("Accuracy :", accuracy)


# Question 5(B)
# Solve Linear Equations using SciPy


def question_5b():

    A = np.array([[2, 1], [1, 3]])

    B = np.array([8, 13])

    solution = solve(A, B)

    print("Solution")

    print("x =", solution[0])
    print("y =", solution[1])


# Question 6(A)
# Support Vector Machine


def question_6a():

    iris = load_iris()

    X = iris.data
    y = iris.target

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42, stratify=y
    )

    model = SVC(kernel="linear")

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    accuracy = accuracy_score(y_test, y_pred)

    print("Accuracy :", accuracy)


# Question 6(B)
# Determinant & Inverse using SciPy


def question_6b():

    A = np.array([[1, 2], [3, 4]], dtype=float)

    determinant = det(A)

    print("Matrix")
    print(A)

    print("\nDeterminant")
    print(determinant)

    if determinant != 0:
        inverse = inv(A)

        print("\nInverse")
        print(inverse)

    else:
        print("Inverse does not exist.")


# Uncomment any function to test


# question_1a()
# question_1b()
# question_2a()
# question_2b()
# question_3a()
# question_3b()
# question_4a()
# question_4b()
# question_5a()
# question_5b()
# question_6a()
# question_6b()

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from scipy.linalg import det, inv
from sklearn.cluster import AgglomerativeClustering, KMeans
from sklearn.dataets import (
    load_breast_cancer,
    load_digits,
    load_iris,
)
from sklearn.ensemble import AdaBoostClassifier, RandomForestClassifier
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics import (
    accuracy_score,
    confusion_matrix,
    precision_score,
    recall_score,
)
from sklearn.model_selection import (
    cross_val_score,
    train_test_split,
)
from sklearn.naive_bayes import GaussianNB
from sklearn.preprocessing import StandardScaler

# Question 7(A)
# K-Means Clustering


def question_7a():

    iris = load_iris()

    X = iris.data[:, :2]

    model = KMeans(n_clusters=3, random_state=42, n_init=10)

    model.fit(X)

    labels = model.labels_

    centers = model.cluster_centers_

    plt.scatter(X[:, 0], X[:, 1], c=labels)

    plt.scatter(centers[:, 0], centers[:, 1], marker="x", s=200, color="red")

    plt.title("K-Means Clustering")

    plt.show()


# Question 7(B)
# Structured Array


def question_7b():

    student_dtype = [("name", "U20"), ("height", "f4"), ("class", "i4")]

    students = np.array(
        [("Farhan", 170.5, 3), ("Ahmed", 165.4, 2), ("Imran", 180.2, 4)],
        dtype=student_dtype,
    )

    print("Original")

    print(students)

    students.sort(order="height")

    print("\nSorted by Height")

    print(students)


# Question 8(A)
# Agglomerative Clustering


def question_8a():

    iris = load_iris()

    X = iris.data[:, :2]

    model = AgglomerativeClustering(n_clusters=3)

    labels = model.fit_predict(X)

    plt.scatter(X[:, 0], X[:, 1], c=labels)

    plt.title("Agglomerative Clustering")

    plt.show()


# Question 8(B)
# Determinant of Matrix


def question_8b():

    matrix = np.array([[1, 2], [3, 4]])

    determinant = np.linalg.det(matrix)

    print(matrix)

    print("\nDeterminant")

    print(determinant)


# Question 9(A)
# Random Forest


def question_9a():

    iris = load_iris()

    X = iris.data

    y = iris.target

    scaler = StandardScaler()

    X = scaler.fit_transform(X)

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42, stratify=y
    )

    model = RandomForestClassifier(n_estimators=100, random_state=42)

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    accuracy = accuracy_score(y_test, y_pred)

    print("Accuracy :", accuracy)

    scores = cross_val_score(model, X, y, cv=5)

    print("Cross Validation")

    print(scores)

    print("Mean :", scores.mean())


# Question 9(B)
# NumPy Indexing & Slicing


def question_9b():

    arr = np.array([[10, 20, 30], [40, 50, 60], [70, 80, 90]])

    print(arr)

    print("\nFirst Row")

    print(arr[0])

    print("\nSecond Column")

    print(arr[:, 1])

    print("\nFirst Two Rows")

    print(arr[:2])

    print("\n2x2 Slice")

    print(arr[:2, :2])


# Question 10(A)
# AdaBoost


def question_10a():

    iris = load_iris()

    X = iris.data

    y = iris.target

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42, stratify=y
    )

    model = AdaBoostClassifier(n_estimators=50, random_state=42)

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    accuracy = accuracy_score(y_test, y_pred)

    print("Accuracy :", accuracy)


# Question 10(B)
# Determinant & Inverse


def question_10b():

    matrix = np.array([[2, 3], [1, 4]], dtype=float)

    determinant = det(matrix)

    print("Determinant")

    print(determinant)

    if determinant != 0:
        print("\nInverse")

        print(inv(matrix))

    else:
        print("Inverse does not exist.")


# Question 11(A)
# Classification Evaluation


def question_11a():

    data = load_breast_cancer()

    X = data.data

    y = data.target

    scaler = StandardScaler()

    X = scaler.fit_transform(X)

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42, stratify=y
    )

    models = {
        "Naive Bayes": GaussianNB(),
        "Random Forest": RandomForestClassifier(),
    }

    for name, model in models.items():
        model.fit(X_train, y_train)

        y_pred = model.predict(X_test)

        tn, fp, fn, tp = confusion_matrix(y_test, y_pred).ravel()

        precision = precision_score(y_test, y_pred)

        recall = recall_score(y_test, y_pred)

        tpr = tp / (tp + fn)

        fpr = fp / (fp + tn)

        print("=" * 40)

        print(name)

        print("Accuracy :", accuracy_score(y_test, y_pred))

        print("Precision :", precision)

        print("Recall :", recall)

        print("TPR :", tpr)

        print("FPR :", fpr)


# Question 11(B)
# NumPy Arithmetic


def question_11b():

    A = np.array([[1, 2], [3, 4]])

    B = np.array([[5, 6], [7, 8]])

    print(A + B)

    print(A - B)

    print(A * B)

    print(np.dot(A, B))


# Question 12(A)
# Text Classification


def question_12a():

    documents = [
        "I love machine learning",
        "Python is amazing",
        "I hate bugs",
        "Debugging is fun",
    ]

    labels = ["Positive", "Positive", "Negative", "Positive"]

    vectorizer = CountVectorizer()

    X = vectorizer.fit_transform(documents)

    model = GaussianNB()

    model.fit(X.toarray(), labels)

    test = vectorizer.transform(["I love Python"])

    prediction = model.predict(test.toarray())

    print(prediction)


# Question 12(B)
# Determinant


def question_12b():

    matrix = np.array([[4, 2], [1, 3]])

    print(np.linalg.det(matrix))


# Question 13(A)
# Handwritten Digit Classification


def question_13a():

    digits = load_digits()

    X = digits.data

    y = digits.target

    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.25, random_state=42
    )

    # Simple classifier for demonstration
    model = RandomForestClassifier()

    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    print("Accuracy :", accuracy_score(y_test, y_pred))


# Question 13(B)
# Solve Linear Equation


def question_13b():

    from scipy.linalg import solve

    A = np.array([[3, 2], [1, 2]])

    B = np.array([18, 14])

    solution = solve(A, B)

    print("x =", solution[0])

    print("y =", solution[1])


# Uncomment any function to test

# question_7a()
# question_7b()
# question_8a()
# question_8b()
# question_9a()
# question_9b()
# question_10a()
# question_10b()
# question_11a()
# question_11b()
# question_12a()
# question_12b()
# question_13a()
# question_13b()

## IMPORTANT NOTE
# # Linear Regression
# LinearRegression()

# # Logistic Regression
# LogisticRegression(max_iter=200)

# # Decision Tree
# DecisionTreeClassifier(random_state=42)

# # Naive Bayes
# GaussianNB()

# # K-Nearest Neighbours
# KNeighborsClassifier(n_neighbors=3)

# # Support Vector Machine
# SVC(kernel="linear")

# # K-Means Clustering
# KMeans(
#     n_clusters=3,
#     random_state=42,
#     n_init=10
# )

# # Agglomerative Clustering
# AgglomerativeClustering(n_clusters=3)

# # Random Forest
# RandomForestClassifier(
#     n_estimators=100,
#     random_state=42
# )

# # AdaBoost
# AdaBoostClassifier(
#     n_estimators=50,
#     random_state=42
# )
# max_iter  # Maximum training iterations

# n_neighbors  # Number of nearest neighbours (KNN)

# kernel  # Type of SVM kernel ("linear", "rbf", etc.)

# n_clusters  # Number of clusters (KMeans/Agglomerative)

# n_estimators  # Number of trees/weak learners (Random Forest/AdaBoost)

# random_state  # Makes results reproducible

# n_init  # Number of KMeans initializations; best one is chosen


# plt.gray()
# plt.plot(dataset.images[1730])
# plt.show()

# # Import required libraries
# import tensorflow as tf
# import matplotlib.pyplot as plt

# # -----------------------------
# # STEP 1: Define a 3x3 edge detection kernel
# # -----------------------------
# kernel = tf.constant([
#     [-1, -1, -1],
#     [-1,  8, -1],
#     [-1, -1, -1]
# ])

# # -----------------------------
# # STEP 2: Load the image
# # -----------------------------
# image = tf.io.read_file("AI.jpg")                # Read image from file
# image = tf.io.decode_jpeg(image, channels=1)     # Convert to grayscale (1 channel)
# image = tf.image.resize(image, [500, 500])       # Resize to 500x500 pixels

# # -----------------------------
# # STEP 3: Display original image
# # -----------------------------
# plt.figure(figsize=(5, 5))
# plt.imshow(tf.squeeze(image), cmap="gray")       # Remove extra dimension for plotting
# plt.title("Original Image")
# plt.axis("off")
# plt.show()

# # -----------------------------
# # STEP 4: Prepare image for CNN
# # -----------------------------
# image = tf.image.convert_image_dtype(image, tf.float32)  # Convert pixel values to float (0-1)

# # Add batch dimension
# # Shape changes:
# # (500, 500, 1) -> (1, 500, 500, 1)
# image = tf.expand_dims(image, axis=0)

# # -----------------------------
# # STEP 5: Prepare kernel
# # -----------------------------
# # CNN expects kernel shape:
# # (height, width, input_channels, output_channels)
# kernel = tf.reshape(kernel, [3, 3, 1, 1])
# kernel = tf.cast(kernel, tf.float32)

# # -----------------------------
# # STEP 6: Apply Convolution
# # -----------------------------
# conv_image = tf.nn.conv2d(
#     input=image,
#     filters=kernel,
#     strides=1,
#     padding="SAME"
# )

# # -----------------------------
# # STEP 7: Apply ReLU Activation
# # -----------------------------
# relu_image = tf.nn.relu(conv_image)

# # -----------------------------
# # STEP 8: Apply Max Pooling
# # -----------------------------
# pool_image = tf.nn.pool(
#     input=relu_image,
#     window_shape=(2, 2),      # 2x2 pooling window
#     pooling_type="MAX",        # Max Pooling
#     strides=(2, 2),            # Move window by 2 pixels
#     padding="SAME"
# )

# # -----------------------------
# # STEP 9: Display Results
# # -----------------------------
# plt.figure(figsize=(15, 5))

# # Convolution Output
# plt.subplot(1, 3, 1)
# plt.imshow(tf.squeeze(conv_image))
# plt.title("Convolution")
# plt.axis("off")

# # ReLU Output
# plt.subplot(1, 3, 2)
# plt.imshow(tf.squeeze(relu_image))
# plt.title("ReLU Activation")
# plt.axis("off")

# # Max Pooling Output
# plt.subplot(1, 3, 3)
# plt.imshow(tf.squeeze(pool_image))
# plt.title("Max Pooling")
# plt.axis("off")

# plt.show()

# X = df.drop("Outcome", axis=1).values
# y = df["Outcome"].values
