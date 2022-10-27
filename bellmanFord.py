class Graph: 
    def __init__(self):
        self.vertices = []
        self.edges = {}
        
    def addVertex(self, vertex: int):
        self.vertices.append(vertex)
    
    def addEdge(self, u: int, v: int, w: int):
        self.edges[(u, v)] = w
        self.edges[(v, u)] = w
        
    def getVertices(self) -> list:
        return self.vertices
    
    def getEdges(self) -> dict:
        return self.edges

def bellmanFord(G: Graph, source: int, destination: int, unreachableVertices: list) -> dict:
    vertices = G.getVertices()
    edges = G.getEdges()
    distances = {source: 0}
    unreachable = {}
    previousSet = {}

    if source not in vertices or destination not in vertices:
        print('Invalid Input!')
        return
    
    for i in vertices:
        if i != source:
            distances[i] = float('inf')
        unreachable[i] = False

    for i in unreachableVertices:
        unreachable[i] = True
            
    for i in range(len(vertices) - 1):
        edgeRelaxations = 0
        for j in list(edges.keys()):
            u, v = j[0], j[1]
            if not unreachable[u] and not unreachable[v]:
                if distances[u] + edges[(u, v)] < distances[v]:
                    distances[v] = distances[u] + edges[(u, v)]
                    previousSet[v] = u
                    edgeRelaxations += 1
                
        if edgeRelaxations == 0:
            print(f'\n{i} Iteration(s) Completed!')
            break
    
    print(f'\nShortest Distance From {source} to {destination} is {distances[destination]}!')
    print(distances)
        
    return previousSet
    
def findShortestRoute(previousSet, source, destination):
    if previousSet == None:
        return
    route = []
    
    while destination != source:
        route.append(destination)
        destination = previousSet[destination]
    route.append(source)
    
    return route[::-1]

G1 = Graph()

for i in range(1, 13):
    G1.addVertex(i)
    
G1.addEdge(1, 2, 9)
G1.addEdge(1, 3, 7)
G1.addEdge(1, 4, 3)
G1.addEdge(1, 5, 2)
G1.addEdge(2, 6, 4)
G1.addEdge(2, 7, 2)
G1.addEdge(2, 8, 1)
G1.addEdge(3, 6, 2)
G1.addEdge(3, 7, 7)
G1.addEdge(4, 8, 11)
G1.addEdge(5, 7, 11)
G1.addEdge(5, 8, 8)
G1.addEdge(6, 9, 6)
G1.addEdge(6, 10, 5)
G1.addEdge(7, 9, 4)
G1.addEdge(7, 10, 3)
G1.addEdge(8, 10, 5)
G1.addEdge(8, 11, 6)
G1.addEdge(9, 12, 4)
G1.addEdge(10, 12, 2)
G1.addEdge(11, 12, 5)

s = int(input('Enter Source: '))
t = int(input('Enter Destination: '))
x = 0
unreachableVertices = [int(i) for i in input('Enter Unreachable Vertices: ').split()]

print(f'Shortest Route From {s} to {t} is {findShortestRoute(bellmanFord(G1, s, t, unreachableVertices), s, t)}')