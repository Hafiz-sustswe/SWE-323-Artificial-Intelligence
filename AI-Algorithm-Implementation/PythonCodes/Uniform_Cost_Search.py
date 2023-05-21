from heapq import heappop,heappush


Graph = {
    '5': [('3', 2), ('7', 4)],
    '3': [('2', 1), ('4', 3)],
    '7': [('8', 1)],
    '2': [],
    '4': [('8', 2)],
    '8': []
}

def uniform_cost_search(graph, start, goal):
    pq = [(0, start, [])]  # priority queue: (priority, node, path)
    visited = set()
    while pq:
        cost, node, path = heappop(pq)
        if node == goal:
            return path + [node]
        if node not in visited:
            visited.add(node)
            print(node , end=" ")
            print(cost)
            print([path])
            for neighbour, neighbour_cost in graph[node]:
                if neighbour not in visited:
                    heappush(pq, (cost + neighbour_cost, neighbour, path + [node]))

    return None

uniform_cost_search(Graph, '5', '8')
