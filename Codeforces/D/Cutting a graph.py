'''
Link: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

By Soliman Elhassanein

TC: O( Q )
MC: O( n )

Date: 15 Feb 2024
'''

import sys
input = sys.stdin.readline

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, a):
        if self.parent[a] != a:
            self.parent[a] = self.find(self.parent[a])
        return self.parent[a]

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return
        if self.rank[a] < self.rank[b]:
            self.parent[a] = b
        elif self.rank[a] > self.rank[b]:
            self.parent[b] = a
        else:
            self.parent[b] = a
            self.rank[a] += 1

# Read input
n, m, k = map(int, input().split())

# Read the m edges.
# Note: In this problem, each edge will be "cut" exactly once.
edges = [tuple(map(lambda x: int(x)-1, input().split())) for _ in range(m)]

# Read operations.
# We'll store each operation as a tuple: (op, u, v)
ops = []
for _ in range(k):
    parts = input().split()
    op = parts[0]
    u = int(parts[1]) - 1
    v = int(parts[2]) - 1
    ops.append((op, u, v))

# Process the operations in reverse order.
# Initially, after all operations, the graph is empty.
dsu = DSU(n)
answers = []

# Process reversed operations:
for op, u, v in reversed(ops):
    if op == "ask":
        # Check connectivity
        if dsu.find(u) == dsu.find(v):
            answers.append("YES")
        else:
            answers.append("NO")
    else:  # op == "cut"
        # In reverse, a cut becomes an addition.
        dsu.union(u, v)

# The answers list was collected in reverse order, so reverse it back.
answers.reverse()
sys.stdout.write("\n".join(answers))


