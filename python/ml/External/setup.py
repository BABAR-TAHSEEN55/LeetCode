import matplotlib.pyplot as plt
import scipy.cluster.hierarchy as hierarchy

from sklearn.datasets import load_iris
from sklearn.cluster import AgglomerativeClustering


def demonstrate_hierarchical_clustering():
    # Load Iris dataset
    iris = load_iris()

    # Use all four flower measurements for clustering
    X = iris.data

   # Actual flower types, used only for the first comparison graph
    actual_labels = iris.target

    # ---------------------------------------------------
    # 1. Plot the actual flower classes
    # ---------------------------------------------------
    plt.figure(figsize=(10, 7))

    plt.scatter(
        X[actual_labels == 0, 0],  # Sepal length of class 0
        X[actual_labels == 0, 1],  # Sepal width of class 0
        s=100,
        label="Setosa"
    )

    plt.scatter(
        X[actual_labels == 1, 0],
        X[actual_labels == 1, 1],
        s=100,
        label="Versicolor"
    )

    plt.scatter(
        X[actual_labels == 2, 0],
        X[actual_labels == 2, 1],
        s=100,
        label="Virginica"
    )

    plt.xlabel("Sepal Length")
    plt.ylabel("Sepal Width")
    plt.title("Actual Iris Flower Classes")
    plt.legend()
    plt.show()

    # ---------------------------------------------------
    # 2. Create and display the dendrogram
    # ---------------------------------------------------
    plt.figure(figsize=(20, 7))

    # Shows how individual flowers are gradually merged
    hierarchy.dendrogram(
        hierarchy.linkage(X, method="ward")
    )

    plt.title("Hierarchical Clustering Dendrogram")
    plt.xlabel("Flower Sample Index")
    plt.ylabel("Distance")
    plt.show()

    # ---------------------------------------------------
    # 3. Apply Agglomerative Clustering
    # ---------------------------------------------------
    model = AgglomerativeClustering(
        n_clusters=3,
        metric="euclidean",
        linkage="ward"
    )

    # Assign each flower to a cluster
    predicted_labels = model.fit_predict(X)

    print("Cluster labels:")
    print(predicted_labels)

    # ---------------------------------------------------
    # 4. Plot the predicted clusters
    # ---------------------------------------------------
    plt.figure(figsize=(10, 7))

    plt.scatter(
        X[predicted_labels == 0, 0],
        X[predicted_labels == 0, 1],
        s=100,
        label="Cluster 1"
    )

    plt.scatter(
        X[predicted_labels == 1, 0],
        X[predicted_labels == 1, 1],
        s=100,
        label="Cluster 2"
    )

    plt.scatter(
        X[predicted_labels == 2, 0],
        X[predicted_labels == 2, 1],
        s=100,
        label="Cluster 3"
    )

    plt.xlabel("Sepal Length")
    plt.ylabel("Sepal Width")
    plt.title("Agglomerative Clustering")
    plt.legend()
    plt.show()


demonstrate_hierarchical_clustering()
