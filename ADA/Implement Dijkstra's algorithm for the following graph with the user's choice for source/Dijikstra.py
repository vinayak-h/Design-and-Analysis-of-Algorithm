class Graph():

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def printSolution(self, dist):
        print("Vertex \t Distance from Source")
        for node in range(self.V):
            print(node, "\t\t", dist[node])

    def minDistance(self, dist, sptSet):
        min_dist = float('inf')
        min_index = -1

        for v in range(self.V):
            if dist[v] < min_dist and not sptSet[v]:
                min_dist = dist[v]
                min_index = v

        return min_index

    def dijkstra(self, src):
        dist = [float('inf')] * self.V
        dist[src] = 0
        sptSet = [False] * self.V

        for cout in range(self.V):
            u = self.minDistance(dist, sptSet)
            sptSet[u] = True

            for v in range(self.V):
                if (self.graph[u][v] > 0 and
                    not sptSet[v] and
                    dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]

        self.printSolution(dist)


g = Graph(8)
g.graph = [[0, 8, 4, 0, 9, 0, 0, 0],
          [8, 0, 0, 8, 0, 9, 2, 0],
          [4, 0, 0, 0, 3, 0, 2, 0],
          [0, 8, 0, 0, 0, 0, 0, 8],
          [9, 0, 3, 0, 0, 0, 0, 0],
          [0, 9, 0, 0, 0, 0, 0, 2],
          [0, 2, 2, 0, 0, 0, 0, 6],
          [0, 0, 0, 8, 0, 2, 6, 0]]

source_vertex = int(input("Enter the source vertex: "))
g.dijkstra(source_vertex)
