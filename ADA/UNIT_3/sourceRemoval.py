def bfs(adjacency_list, start_vertex):
    visited = set()
    queue = [start_vertex]
    traversal_order = []

    while queue:
        vertex = queue.pop(0)

        if vertex not in visited:
            traversal_order.append(vertex)
            visited.add(vertex)

            for neighbor in adjacency_list[vertex]:
                if neighbor not in visited:
                    queue.append(neighbor)

    return traversal_order


adjacency_list = {
    0: [1, 3],
    1: [0, 3, 5],
    2: [4, 6],
    3: [0, 5, 1, 7],
    4: [2, 6, 7],
    5: [1, 3, 6],
    6: [2, 4, 5, 7],
    7: [3, 4, 6],

}
start_vertex = 0

traversal_order = bfs(adjacency_list, start_vertex)

print("The BFS traversal order is:", traversal_order)
