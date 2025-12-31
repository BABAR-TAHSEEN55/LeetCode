graph = {
    "5": ["3", "7"],
    "3": ["2", "4"],
    "7": ["8"],
    "2": [],
    "4": ["8"],
    "8": ["10"],
    "10": [],
}


visited = set()
queue = set()


def bfs_search(node, graph):
    visited.add(node)
    queue.add(node)

    while queue:
        m = queue.pop()
        print(m)
        for neighbor in graph[m]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.add(neighbor)


print("BFS :")

bfs_search("5", graph)
print("Visited List ", visited)
