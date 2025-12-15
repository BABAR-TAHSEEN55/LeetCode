import heapq


def AStarAlgo(start, goal, heuristic, graph):
    open_list = []
    came_from = {}
    heapq.heappush(graph, (0, start))
    g_cost = {node: float("inf") for node in graph}
    g_cost[start] = 0

    f_cost = {node: float("inf") for node in graph}
    f_cost = heuristic[start]

    while open_list:
        current = heapq.heappop(open_list)
        path = []
        if current == goal:
            pass
        for neighbour, cost in graph[current]:
            temp_g = g_cost[current] + cost
