import heapq

def dijkstra(n, s, f, graph):
    dist = [float('inf')] * n
    dist[s - 1] = 0
    pq = [(0, s - 1)]  # (distance, vertex)
    while pq:
        curr_dist, u = heapq.heappop(pq)
        if curr_dist > dist[u]:
            continue
        for v in range(n):
            if graph[u][v] != -1:  # Check if there's an edge
                new_dist = curr_dist + graph[u][v]
                if new_dist < dist[v]: # curr_dist + graph[u][v] < dist[v]
                    dist[v] = new_dist # dist[v] = curr_dist + graph[u][v]
                    heapq.heappush(pq, (new_dist, v))
    return dist[f - 1] if dist[f - 1] != float('inf') else -1

# Input
n, s, f = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

# Output
print(dijkstra(n, s, f, graph))
