Graph = {
    '5' : ['3','7'],
    '3' : ['2', '4'],
    '7' : [ '8'],
    '2' : [],
    '4' : ['8'],
    '8' : []
}

def iterative_deepening_search(graph, root, goal):
    for depth in range(1, len(graph)):
        visited = set()
        if recursive_dls(graph, root, visited, goal, depth):
            return True
    return False

def recursive_dls(graph, node, visited, goal, limit):
    if node == goal:
        print(node, end=" ")
        return True
    if limit == 0:
        return False
    visited.add(node)
    for neighbour in graph[node]:
        if neighbour not in visited:
            if recursive_dls(graph, neighbour, visited, goal, limit-1):
                print(node, end=" ")
                return True
    return False

iterative_deepening_search(Graph,'5','8')
