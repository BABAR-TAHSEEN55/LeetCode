import heapq

# def best_first_search(start, goal, graph, heuristic):
#     priority_queue = []
#     visited = set()

#     heapq.heappush(priority_queue, (heuristic[start], start))

#     while priority_queue:
#         _, current = heapq.heappop(priority_queue)

#         if current in visited:
#             continue

#         visited.add(current)
#         print(current, end=" ")

#         if current == goal:
#             print("\nGoal reached!")
#             return

#         for neighbour in graph[current]:
#             if neighbour not in visited:
#                 heapq.heappush(priority_queue, (heuristic[neighbour], neighbour))


def best_first_search(start, goal, graph, heuristic):
    priority = []
    visited = set()
    heapq.heappush(priority, (heuristic[start], start))

    while priority:
        _, current = heapq.heappop(priority)
        if current == goal:
            print(current)
            return

        visited.add(current)
        print("visited", current)

        for neigbhour in graph[current]:
            if neigbhour not in visited:
                heapq.heappush(priority, (heuristic[neigbhour], neigbhour))


graph = {"A": ["B", "C"], "B": ["D", "E"], "C": ["F"], "D": [], "E": ["F"], "F": []}

heuristic = {"A": 6, "B": 4, "C": 5, "D": 3, "E": 2, "F": 0}

best_first_search("A", "F", graph, heuristic)
