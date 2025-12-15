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
queue = []


def bfs_graph(node, graph):
    visited.append(node)
    queue.append(node)
    while queue:
        m = queue.pop(0)
        print(m, end="")
        for neighbor in graph[m]:
            if neighbor not in visited:
                visited.append(neighbor)
                queue.append(neighbor)


print("BFS :")

bfs_graph("5", graph)
print("Visited List ", visited)
