graph = {
    "5": ["3", "7"],
    "3": ["2", "4"],
    "7": ["8"],
    "2": [],
    "4": ["8"],
    "8": ["10"],
    "10": [],
}

visited = []


def dfs_search(node, graph):
    if node not in visited:
        visited.append(node)

    for neighbour in graph[node]:
        dfs_search(neighbour, graph)


dfs_search("5", graph)
print(visited)
