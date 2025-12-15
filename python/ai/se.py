import heapq

from best_first_search import heuristic

visited = []
queue = []


def bfs_directed(graph, node):
    visited.append(node)
    queue.append(node)
    while queue:
        m = queue.pop(0)
        print("popped", m)

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)


graph = {8: [4, 5], 4: [2, 3], 2: [], 3: [1], 5: [1], 1: []}

(bfs_directed(graph, 8))


def dfs_undirected(node, graph):
    visited = set()
    if node not in visited:
        visited.add(node)

    for neighbout in graph[node]:
        dfs_undirected(neighbout, graph)


mylist = [2, 3]
mylist[0] = 9
print(mylist)


def best_first_search(start, goal, heu, graph):
    priority_queue = []
    visited = set()
    heapq.heappush(priority_queue, (heu[start], start))

    while priority_queue:
        h, current = heapq.heappop(priority_queue)

        if current == goal:
            print(current)
            return
        visited.add(current)

        for neighbout in graph[current]:
            if neighbout not in visited:
                heapq.heappush(priority_queue, (heu[neighbout], neighbout))


graph = {"A": ["B", "C"], "B": ["F", "E"], "C": [], "E": [], "F": []}
he = {"A": 2, "B": 1, "C": 0, "D": 8, "E": 8, "F": 1}

print(best_first_search("A", "F", he, graph))


# PROLOG
# sister(X, Y) :-
#     female(X),
#     parent(Z, X),
#     parent(Z, Y),
#     X \= Y.
