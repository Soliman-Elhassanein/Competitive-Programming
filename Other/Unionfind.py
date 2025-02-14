'''
Link: https://vjudge.net/problem/Yosupo-unionfind

By Soliman Elhassanein

TC: O( Q )
MC: O( n )

Date: 14 Feb 2024
'''

class DSU:
    def __init__(self, n):
        self.par = [-1] * n
        self.sz = [1] * n
    
    def find(self, u):
        if self.par[u] == -1:
            return u
        self.par[u] = self.find(self.par[u])  # Path compression
        return self.par[u]
        
    
    def join(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if u == v:
            return
        if self.sz[v] < self.sz[u]:
            u, v = v, u
        
        self.par[u] = v  # Union 
        self.sz[v] += self.sz[u]

n, Q = list(map(int, input().split()))

dsu = DSU(n)

while(Q):
    Q -= 1
    s, u, v = list(map(int, input().split()))
    
    if s:
        print(1 if dsu.find(u) == dsu.find(v) else 0)
    else:
        dsu.join(u,v)


