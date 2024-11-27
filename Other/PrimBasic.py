import math

def dist2(x1, y1, x2, y2):
    """Compute the squared distance between two points."""
    return (x2 - x1)**2 + (y2 - y1)**2

def prim_basic(n, coordinates):
    """Compute the MST using Prim's algorithm (basic realization)."""
    INF = float('inf')

    # Initialize distance and used arrays
    dist = [INF] * n
    used = [False] * n

    # Start from the first city
    dist[0] = 0
    res = 0

    for _ in range(n):
        # Find the next vertex with the smallest distance
        cur = -1
        for i in range(n):
            if not used[i] and (cur == -1 or dist[i] < dist[cur]):
                cur = i
        
        # Include this vertex in the MST
        used[cur] = True
        res += math.sqrt(dist[cur])

        # Update distances to the rest of the vertices
        for i in range(n):
            if not used[i]:
                d2 = dist2(coordinates[cur][0], coordinates[cur][1], coordinates[i][0], coordinates[i][1])
                if d2 < dist[i]:
                    dist[i] = d2

    return res


# Input reading
n = int(input())
coordinates = [tuple(map(int, input().split())) for _ in range(n)]

# Calculate and print result
result = prim_basic(n, coordinates)
print(f"{result:.6f}")
