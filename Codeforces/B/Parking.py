'''
Link: https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/B

By Soliman Elhassanein

TC: O( Q )
MC: O( n )

Date: 14 Feb 2024
'''

import sys
input = sys.stdin.readline

class DSU:
    def __init__(self, n):
        self.par = [-1] * n # parking slots
        self.n = n
        self.result = []
        
    def find(self, u):
        if self.par[u] == -1:
            return u
        self.par[u] = self.find(self.par[u])
        return self.par[u]
        
    def join(self, v): # car, wanted parking slot
        v = ( self.find(v) ) % self.n
        self.result.append(v + 1)
        
        self.par[v]= (v + 1) % self.n

n = list(map(int, input().split()))[0]
dsu = DSU(n)

P = list(map(int, input().split()))

for i, p in enumerate(P):
    dsu.join(i, p - 1)

sys.stdout.write(" ".join(map(str,dsu.result)))

