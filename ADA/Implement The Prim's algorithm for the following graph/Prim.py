INF = 9999999

V = 8

G = [[0,8,4,0,9,0,0,0],
     [8,0,0,8,0,9,2,0],
     [4,0,0,0,3,0,2,0],
     [0,8,0,0,0,0,0,8],
     [9,0,3,0,0,0,0,0],
     [0,9,0,0,0,0,0,2],
     [0,2,2,0,0,0,0,6],
     [0,0,0,8,0,2,6,0]]

selected = [0, 0, 0, 0, 0, 0, 0, 0]

no_edge = 0

selected[0] = True

print("Edge : Weight\n")
while (no_edge < V - 1):
   
    minimum = INF
    x = 0
    y = 0
    for i in range(V):
        if selected[i]:
            for j in range(V):
                if ((not selected[j]) and G[i][j]):  
                    if minimum > G[i][j]:
                        minimum = G[i][j]
                        x = i
                        y = j
    print(str(x) + "-" + str(y) + ":" + str(G[x][y]))
    selected[y] = True
    no_edge += 1