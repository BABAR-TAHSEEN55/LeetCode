import heapq


def astar(graph, heuristic, start, goal):
    open_list = []
    heapq.heappush(open_list, (heuristic[start], start))

    came_from = {}

    g_cost = {node: float("inf") for node in graph}
    g_cost[start] = 0

    f_cost = {node: float("inf") for node in graph}
    f_cost[start] = heuristic[start]

    while open_list:
        _, current = heapq.heappop(open_list)

        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]

        for neighbor, cost in graph[current]:
            temp_g = g_cost[current] + cost

            if temp_g < g_cost[neighbor]:
                came_from[neighbor] = current
                g_cost[neighbor] = temp_g
                f_cost[neighbor] = temp_g + heuristic[neighbor]
                heapq.heappush(open_list, (f_cost[neighbor], neighbor))

    return None


graph = {
    "A": [("B", 1), ("C", 4)],
    "B": [("D", 2), ("E", 5)],
    "C": [("E", 1)],
    "D": [("G", 3)],
    "E": [("G", 1)],
    "G": [],
}

heuristic = {"A": 7, "B": 6, "C": 4, "D": 2, "E": 1, "G": 0}

path = astar(graph, heuristic, "A", "G")
print("Shortest path:", path)
