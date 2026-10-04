# Distance Vector Routing Algorithm

INF = 999

n = int(input("Enter number of routers: "))

print("Enter the cost matrix:")
cost = []

for i in range(n):
    cost.append(list(map(int, input().split())))

# Initially, distance table = cost matrix
dist = [row[:] for row in cost]

# Distance Vector Algorithm
for k in range(n):
    for i in range(n):
        for j in range(n):
            if dist[i][j] > dist[i][k] + dist[k][j]:
                dist[i][j] = dist[i][k] + dist[k][j]

# Display shortest distances
print("\nShortest Distance Table:")

for i in range(n):
    print("Router", i + 1, ":", dist[i])


