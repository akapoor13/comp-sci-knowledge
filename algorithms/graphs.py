
class Edge:
    def __init__(self, start, end, weight):
        self.start = start
        self.end = end
        self.weight = weight


def myFunc(e):
    return e.weight


def kruskal(G):
    edges = []

    for i in range(len(G)):
        for j in range(len(G[i])):
            if G[i][j] != float('inf'):
                edges.append(Edge(i, j, G[i][j]))

    edges.sort(key=myFunc)

    for i in edges:
        print(i.start, i.end, i.weight)

    mst = []
    for i in range(len(G)):
        row = []
        for j in range(len(G)):
            row.append(0)

        mst.append(row)

    count = 0

    for i in edges:
        if count == len(G)-1:
            break

        if mst[i.start][i.end] == 1:
            continue
        elif cycles(i.start, i.end, mst) == False:
            count += 1
            print(i.start, i.end)
            mst[i.start][i.end] = 1
            mst[i.end][i.start] = 1

    return mst


def parse_path(node, mst):
    seen = []
    nodeQ = [node]
    nodeS = []

    while nodeQ != []:
        currNode = nodeQ[0]

        for i in range(len(mst[currNode])):
            if ((mst[currNode][i] != 0) and (i not in seen)):
                nodeQ.append(i)
                seen.append(i)
                nodeS.append(i)

        seen.append(currNode)
        del nodeQ[0]

    return nodeS


def cycles(startNode, endNode, mst):
    startS = set(parse_path(startNode, mst))
    endS = set(parse_path(endNode, mst))
    return len(startS.intersection(endS)) != 0


def dijkstra(G, root):
    parent = [-1] * len(G)
    cost = [float('inf')] * len(G)
    visited = [False] * len(G)

    counter = 1
    src = root
    cost[root] = 0
    visited[root] = True

    while (counter != len(G)):
        for currNode in range(len(G[src])):
            if cost[currNode] > cost[src] + G[src][currNode] and not visited[currNode]:
                cost[currNode] = cost[src] + G[src][currNode]
                parent[currNode] = src

        minCost = float('inf')
        minNode = 0
        for i in range(len(cost)):
            if not visited[i] and cost[i] < minCost:
                minNode = i
                minCost = cost[i]

        src = minNode
        visited[src] = True
        counter += 1

    print(parent)
    print(cost)
    print(visited)


G2 = [
    [float('inf'), 1, float('inf'), 1, float('inf')],
    [1, float('inf'), 1, float('inf'), 1],
    [float('inf'), 1, float('inf'), 1, 1],
    [1, float('inf'), 1, float('inf'), 1],
    [float('inf'), 1, 1, 1, float('inf')]
]


G = [
    [float('inf'), 1, 3, 2, float('inf'), float(
        'inf'), float('inf'), float('inf')],
    [1, float('inf'), float('inf'), float('inf'), 2,
     float('inf'), float('inf'), float('inf')],
    [3, float('inf'), float('inf'), 1, 4, 2, float('inf'), float('inf')],
    [2, float('inf'), 1, float('inf'), 5, float(
        'inf'), float('inf'), float('inf')],
    [float('inf'), 2, 4, float('inf'), float(
        'inf'), float('inf'), 2, float('inf')],
    [float('inf'), float('inf'), 2, 5, float('inf'), float('inf'), 2],
    [float('inf'), float('inf'), float('inf'),
     float('inf'), 2, 1, float('inf'), 4],
    [float('inf'), float('inf'), float('inf'), float(
        'inf'), float('inf'), 2, 4, float('inf')]
]

print(kruskal(G))
