import heapq
from operator import ne


def aStarAlgo(graph, heuristic, start, goal):
    open_list = []
    heapq.heappush(open_list, (0, start))
    came_from = {}
    g_cost = {node: float("inf") for node in graph}
    f_cost = {node: float("inf") for node in graph}

    g_cost = 0
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
                g_cost[neighbor] = current
                f_cost[neighbor] = temp_g
                f_cost[neighbor] = temp_g + heuristic[neighbor]
                heapq.heappush(open_list, (f_cost[neighbor], neighbor))
