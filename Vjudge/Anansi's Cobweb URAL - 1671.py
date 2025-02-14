'''
Link: https://vjudge.net/problem/URAL-1671

By Soliman Elhassanein

TC: O( Q )
MC: O( n )

Date: 15 Feb 2024
'''

import sys
input = sys.stdin.readline

class DSU:
    def __init__(self, n):
        self.parent = [-1] * n
        self.comp = n
        self.sz = [1] * n
        
    def find(self, a):
        if self.parent[a] == -1:
            return a
        self.parent[a] = self.find(self.parent[a])
        return self.parent[a]

    def join(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return
        
        self.comp -= 1
        
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        
        self.parent[b] = a

# Read input
n, m = list(map(int, input().split()))

ops = []
for _ in range(m):
    u, v = list(map(int, input().split()))
    u = u - 1
    v = v - 1
    ops.append((u, v))

q = list(map(int, input().split()))[0]

rm_num = list(map(lambda x: int(x)-1, input().split()))
rm_e = []
for e in (rm_num):
    rm_e.append(ops[e])
    ops[e] = 0


dsu = DSU(n)

for op in ops:
    if op != 0:
        dsu.join(op[0], op[1])

rm_e.reverse()

answers = []

for e in rm_e:
    answers.append(dsu.comp)
    dsu.join(e[0], e[1])

answers.reverse()

sys.stdout.write("\n".join(map(str, answers)))
