import matplotlib.pyplot as plt
from sklearn.cluster import AgglomerativeClustering, KMeans
from sklearn.datasets import load_iris
from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics import (
    accuracy_score,
    confusion_matrix,
    precision_score,
    recall_score,
)
from sklearn.model_selection import cross_validate, train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.preprocessing import StandardScaler


def KKK():
    iris = load_iris()
    X = iris.data[:, :2]

    kmeans = KMeans(n_clusters=3, random_state=42, n_init=10)
    kmeans.fit(X)

    labels = kmeans.labels_
    centers = kmeans.cluster_centers_

    # There isn't : , :1
    plt.scatter(X[:, 0], X[:, 1], c=labels)
    plt.scatter(centers[:, 0], centers[:, 1], color="red", marker="x", s=100)

    plt.title("K-Means Clustering")
    plt.xlabel("Sepal Length")
    plt.ylabel("Sepal Width")

    plt.show()


def Agglomerative():
    X = load_iris.data[:, :2]
    model = AgglomerativeClustering(n_clusters=3)
    labels = model.fit_predict(X)
    plt.scatter(X[:, 0], X[:, 1], c=labels)
    plt.title("Agglomerative")
    plt.show()


# Revise
def Rain():
    X = load_iris().data
    y = load_iris().target
    scaler = StandardScaler()
    scaled_x = scaler.fit_transform(X)

    model = RandomForestClassifier(n_estimators=3)
    x_train, x_test, y_train, y_test = train_test_split(
        scaled_x, y, test_size=0.25, random_state=42, stratify=y
    )
    model.fit(x_train, y_train)
    y_pred = model.predict(x_test)
    accuracy = accuracy_score(y_test, y_pred)
    scores = cross_validate(scaled_x, y, cv=5)
    print(scores)
    print(accuracy)


def sain():
    Rain()


def ClassShit():
    iris = load_iris()
    X = iris.data
    y = iris.target
    scaler = StandardScaler()
    scaled_x = scaler.fit_transform(X)

    x_train, x_test, y_train, y_test = train_test_split(
        scaled_x, y, test_size=0.25, stratify=y, random_state=42
    )
    models = {
        "RandomForest": RandomForestClassifier(n_estimators=3),
        "Naive Bayes": GaussianNB(),
    }
    for name, model in models.items():
        model.fit(x_train, y_train)
        y_pred = model.predict(x_test)
        tp, fn, tn, fp = confusion_matrix(y_test, y_pred).ravel()
        recall = recall_score(y_test, y_pred)
        precision = precision_score(y_test, y_pred)
        tpr = tp / (tp + fp)
        fpr = fp / (fp + tn)


def pra():
    docments = [
        "I love Programmin",
        "I hate bugs",
        "Debugging is fun",
        "Python is Amazing",
    ]
    labels = ["Postive", "Negative", "Postive", "Negative"]

    vectorizer = CountVectorizer()
    X = vectorizer.fit_transform(docments)

    model = GaussianNB()
    model.fit(X.toarray(), labels)
    test = vectorizer.transform(docments[0])

    model.predict(test.toarray())


if __name__ == "__main__":
    sain()


def Phir():
    documents = [
        "I love programming",
        "I hate bugs",
        "I love debugging",
        "Pythong is Amazing",
    ]
    labels = ["Postive", "Negative", "Postive", "Negative"]

    vectorize = CountVectorizer()

    X = vectorize.fit_transform(documents)

    model = GaussianNB()

    model.fit(X.toarray(), label)

    test = vectorize.transform(document[0])
    model.predict(test.toarray())
