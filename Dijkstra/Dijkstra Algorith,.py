import heapq

def dijkstra(n, start, end, matrix):
    dist = [float('inf')] * n
    dist[start] = 0

    pq = [(0, start)]
    while pq:
        curr_dist, u = heapq.heappop(pq)
        if u == end:
            return curr_dist
        for v in range(n):
            if matrix[u][v] != -1 and curr_dist + matrix[u][v] < dist[v]:
                dist[v] = curr_dist + matrix[u][v]
                heapq.heappush(pq, (dist[v], v))
    return -1

n, s, f = map(int, input().split())
s -= 1
f -= 1
matrix = [list(map(int, input().split())) for _ in range(n)]
print(dijkstra(n, s, f, matrix))
