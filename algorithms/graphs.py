def prims-mst(G, startNode):
    # G: [[costs], [costs], [costs]]
    # output tree: [list of visiting]
    visited = [False] * len(G)
    parent = [None] * len(G)
    distance = [float('inf')]*len(G)
    
    visited[startNode] = True
    distance[startNode] = float('inf')
    
    MSTtree = [chr(startNode+65)]
    currNode = startNode
    i=1
    while(i<len(G)):
        minIndex = 0

        for j in range(len(G[currNode])):
            if visited[j]!=True and distance[j]>G[currNode][j]:
                distance[j] = G[currNode][j]
                parent[j] = currNode
            
        for j in range(len(distance)):
            if distance[j]<distance[minIndex] and visited[j]!=True:
                minIndex = j
                
        currNode = minIndex
        visited[currNode] = True
        MSTtree.append(chr(currNode+65))
        i+=1
    
    return MSTtree

G = [
        [float('inf'), 1, 3, 2, float('inf'), float('inf'), float('inf'), float('inf')],
        [1, float('inf'), float('inf'), float('inf'), 2, float('inf'), float('inf'), float('inf')],
        [3, float('inf'), float('inf'), 1, 4, 2, float('inf'), float('inf')],
        [2, float('inf'), 1, float('inf'), 5, float('inf'), float('inf'), float('inf')],
        [float('inf'), 2, 4, float('inf'), float('inf'), float('inf'), 2, float('inf')],
        [float('inf'), float('inf'), 2, 5, float('inf'), 1, 2],
        [float('inf'), float('inf'), float('inf'), float('inf'), 2, 1, float('inf'), 4],
        [float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), 2, 4, float('inf')]
     ]
startNode = 0

print(mst(G, startNode))