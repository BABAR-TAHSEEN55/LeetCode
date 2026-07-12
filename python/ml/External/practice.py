import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.datasets import load_iris


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


def sain():
    KKK()


if __name__ == "__main__":
    sain()
