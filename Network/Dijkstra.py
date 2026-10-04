# Dijkstra's Algorithm

INF = 999

n = int(input("Enter number of vertices: "))

print("Enter the cost matrix:")
graph = []

for i in range(n):
    graph.append(list(map(int, input().split())))

source = int(input("Enter source vertex: ")) - 1

distance = [INF] * n
visited = [False] * n

distance[source] = 0

for i in range(n):
    # Find nearest unvisited vertex
    min_dist = INF
    u = -1

    for j in range(n):
        if not visited[j] and distance[j] < min_dist:
            min_dist = distance[j]
            u = j

    if u == -1:
        break

    visited[u] = True

    # Update distances
    for v in range(n):
        if graph[u][v] != 0 and not visited[v]:
            new_dist = distance[u] + graph[u][v]

            if new_dist < distance[v]:
                distance[v] = new_dist

print("\nShortest distances from vertex", source + 1)

for i in range(n):
    print("To vertex", i + 1, "=", distance[i])



    