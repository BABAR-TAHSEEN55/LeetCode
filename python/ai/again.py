import heapq


def astar(graph, heauristic, goal, start):
    open_list = []
    heapq.heappush(open_list, (0, start))

    came_from = {}
    g_cost = {node: float("inf") for node in graph}
    g_cost[start] = 0
    f_cost = {node: float("inf") for node in graph}
    f_cost[start] = heauristic[start]
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
