# Agglomerative
import matplotlib.pyplot as plt
import scipy.cluster.hierarchy as sch
from sklearn.cluster import AgglomerativeClustering
from sklearn.datasets import load_iris


def question_8a():
    # Load Iris dataset
    iris = load_iris()
    X = iris.data[:, :2]  # Sepal Length and Sepal Width

    # Plot Dendrogram
    plt.figure(figsize=(10, 5))
    sch.dendrogram(sch.linkage(X, method="ward"))
    plt.title("Dendrogram")
    plt.xlabel("Sample Index")
    plt.ylabel("Euclidean Distance")
    plt.show()

    # Apply Agglomerative Clustering
    model = AgglomerativeClustering(n_clusters=3, linkage="ward")

    labels = model.fit_predict(X)

    # Plot Clusters
    plt.figure(figsize=(8, 6))
    plt.scatter(X[labels == 0, 0], X[labels == 0, 1], c="blue", s=50, label="Cluster 1")
    plt.scatter(
        X[labels == 1, 0], X[labels == 1, 1], c="green", s=50, label="Cluster 2"
    )
    plt.scatter(X[labels == 2, 0], X[labels == 2, 1], c="red", s=50, label="Cluster 3")

    plt.title("Agglomerative Hierarchical Clustering")
    plt.xlabel("Sepal Length")
    plt.ylabel("Sepal Width")
    plt.legend()
    plt.show()


def main():
    question_8a()


if __name__ == "__main__":
    main()
