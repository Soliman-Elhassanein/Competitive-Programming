'''
Link: https://vjudge.net/problem/CSES-1676

By Soliman Elhassanein

TC: O( Q )
MC: O( n )

Date: 14 Feb 2024
'''

import sys
input = sys.stdin.readline

class DSU:
    def __init__(self, n):
        self.par = [-1] * n
        self.sz = [1] * n
        self.mx = 0
        self.comp = n
    
    def find(self, u):
        if self.par[u] == -1:
            return u
        self.par[u] = self.find(self.par[u])
        return self.par[u]
        
    def join(self, u, v):
        u = self.find(u)
        v = self.find(v)
        
        if u == v:
            return
        
        self.comp -= 1
        
        if self.sz[v] < self.sz[u]:
            u, v = v, u
        
        self.par[u] = v  # Union 
        self.sz[v] += self.sz[u]
        
        self.mx = max(self.mx, self.sz[v])

n, Q = list(map(int, input().split()))
dsu = DSU(n)
output_lines = []

while(Q):
    Q -= 1
    u, v = list(map(int, input().split()))
    
    dsu.join(u - 1, v - 1)
    
    output_lines.append(f'{dsu.comp} {dsu.mx}')
    
sys.stdout.write("\n".join(output_lines))

