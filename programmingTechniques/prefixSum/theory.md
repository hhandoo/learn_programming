# The Prefix Sum Technique

Prefix Sum is a popular technique in programming used to preprocess an array for efficient range sum queries. It involves creating a new array, often called a **prefix sum array**, where each element at index `i` stores the sum of elements from the beginning of the original array up to index `i`. This enables constant-time sum queries for any subarray.

### Steps to Use Prefix Sum Technique:

1. **Build the Prefix Sum Array**:
   - Let the original array be `arr`.
   - Create a prefix sum array `prefix` where:
     \[
     prefix[i] = arr[0] + arr[1] + \dots + arr[i]
     \]

2. **Use the Prefix Sum Array**:
   - To find the sum of elements in the range `[L, R]` (inclusive):
     \[
     sum(L, R) = prefix[R] - prefix[L-1]
     \]
   - If \( L = 0 \), then:
     \[
     sum(0, R) = prefix[R]
     \]

---

### Example:

#### Problem:
Given an array `arr = [2, 4, 6, 8, 10]`, find the sum of elements in the range `[1, 3]`.

#### Step 1: Build the Prefix Sum Array
\[
prefix[0] = arr[0] = 2
\]
\[
prefix[1] = prefix[0] + arr[1] = 2 + 4 = 6
\]
\[
prefix[2] = prefix[1] + arr[2] = 6 + 6 = 12
\]
\[
prefix[3] = prefix[2] + arr[3] = 12 + 8 = 20
\]
\[
prefix[4] = prefix[3] + arr[4] = 20 + 10 = 30
\]

So, `prefix = [2, 6, 12, 20, 30]`.

#### Step 2: Compute the Range Sum
To find the sum of elements in `[1, 3]`:
\[
sum(1, 3) = prefix[3] - prefix[0] = 20 - 2 = 18
\]

---

### Code Implementation (Python):

```python
def build_prefix_sum(arr):
    prefix = [0] * len(arr)
    prefix[0] = arr[0]
    for i in range(1, len(arr)):
        prefix[i] = prefix[i - 1] + arr[i]
    return prefix

def range_sum(prefix, L, R):
    if L == 0:
        return prefix[R]
    else:
        return prefix[R] - prefix[L - 1]

# Example
arr = [2, 4, 6, 8, 10]
prefix = build_prefix_sum(arr)
print("Prefix Sum Array:", prefix)
print("Sum of range [1, 3]:", range_sum(prefix, 1, 3))
```

---

### Applications of Prefix Sum:
1. **Efficient Range Queries**: Solve problems involving multiple range sum queries efficiently.
2. **2D Prefix Sum**: For 2D grids, useful in matrix-related problems.
3. **Difference Arrays**: Modify arrays efficiently within a range.

Let me know if you'd like to dive deeper into problems using this technique! 🚀