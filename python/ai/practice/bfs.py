visited = []
queue = []


def bfs_search(node, graph):
    visited.append(node)
    queue.append(node)

    while queue:
        m = queue.pop(0)
        print("Popped ", m)
        for neighbor in graph[m]:
            if neighbor not in visited:
                visited.append(neighbor)
                queue.append(neighbor)
