MAX = 10**6 # Define the max_value for input
d = [0] * (MAX + 1) # Init the array for DP
d[1] = 0 # Base case

# Fill the DP table using the given recurrence
for i in range(2, MAX + 1):
    d[i] = d[i - 1]  # Minimum operations by subtracting 1
    if i % 2 == 0:
        d[i] = min(d[i], d[i // 2])  # Check division by 2
    if i % 3 == 0:
        d[i] = min(d[i], d[i // 3])  # Check division by 3
    d[i] += 1  # Add the operation count

# Function to process inputs and return results
def min_operations_to_one(numbers):
    return [d[n] for n in numbers]

# Main function to handle CLI input and output
if __name__ == "__main__":
    import sys
    inputs = list(map(int, sys.stdin.read().strip().split()))
    results = min_operations_to_one(inputs)
    
    # Output
    for result in results:
        print(result)
