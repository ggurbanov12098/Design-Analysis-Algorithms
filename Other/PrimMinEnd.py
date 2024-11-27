import math

def dist2(x1, y1, x2, y2):
    """Compute the squared distance between two points."""
    return (x2 - x1)**2 + (y2 - y1)**2

def prim_min_e(n, coordinates):
    """Compute the MST using Prim's algorithm with min_e and end_e."""
    INF = float('inf')

    # Initialize arrays
    min_e = [INF] * n
    end_e = [-1] * n
    used = [False] * n

    # Start from the first city
    min_e[0] = 0
    res = 0

    for _ in range(n):
        # Find the vertex with the smallest min_e value
        cur = -1
        for i in range(n):
            if not used[i] and (cur == -1 or min_e[i] < min_e[cur]):
                cur = i
        
        # Include this vertex in the MST
        used[cur] = True
        if end_e[cur] != -1:
            res += math.sqrt(min_e[cur])

        # Update min_e and end_e for the rest of the vertices
        for to in range(n):
            if not used[to]:
                d2 = dist2(coordinates[cur][0], coordinates[cur][1], coordinates[to][0], coordinates[to][1])
                if d2 < min_e[to]:
                    min_e[to] = d2
                    end_e[to] = cur

    return res


# Input reading
n = int(input())
coordinates = [tuple(map(int, input().split())) for _ in range(n)]

# Calculate and print result
result = prim_min_e(n, coordinates)
print(f"{result:.6f}")
 