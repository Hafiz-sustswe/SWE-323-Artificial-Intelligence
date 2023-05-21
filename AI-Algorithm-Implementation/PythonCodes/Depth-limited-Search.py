Graph = {
    '5' : ['3','7'],
    '3' : ['2', '4'],
    '7' : [ '8'],
    '2' : [],
    '4' : ['8'],
    '8' : []
}

visited = set()

def depth_limited_search(graph, root, limit):
    visited = set()
    recursive_dls(graph, root, visited, limit)

def recursive_dls(graph, node, visited, limit):
    if limit == 0:
        return
    print(node, end=" ")
    visited.add(node)
    for neighbour in graph[node]:
        if neighbour not in visited:
            recursive_dls(graph, neighbour, visited, limit-1)

depth_limited_search(Graph,'5',5)