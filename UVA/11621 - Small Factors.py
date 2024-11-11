'''
Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2668

By Soliman Elhassanein

TC: O(log n)
MC: O(1)

Date: 11 Nov 2024
'''

from math import ceil, log, log2

def cal(i, j):
    return 2**i * 3**j

def print23(n):
    min_n = float('inf')
    
    max_j = int(log(n, 3)) + 1
    
    for j in range(max_j + 1):
        t = n / 3 ** j
        i = ceil(log2(t))
        if i < 0:
            continue
        current_n = cal(i, j)
        if current_n >= n:
            min_n = min(min_n, current_n)

    return min_n

while(True)
        n = int(input())
        if(not n):
            break
        print( print23(n) )
