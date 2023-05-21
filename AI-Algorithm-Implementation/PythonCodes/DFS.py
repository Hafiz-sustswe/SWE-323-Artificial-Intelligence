Graph = {
    '5' : ['3','7'],
    '3' : ['2', '4'],
    '7' : [ '8'],
    '2' : [],
    '4' : ['8'],
    '8' : []
}
visited = set()
def dfs (visited,graph,root):
    if root not in visited:
        print(root , end= " ")
        visited.add(root)
        for neighbour in graph[root]:
            dfs(visited,graph,neighbour)



dfs(visited,Graph,'5')
