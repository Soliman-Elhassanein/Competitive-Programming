'''
Link: https://codeforces.com/problemset/problem/1062/B

By Soliman Elhassanein

TC: O( n^0.5 )
MC: O( n^0.5 )

Date: 26-Nov-2024
'''

from collections import Counter
from math import log, ceil

def factorization(n):
    
    factors = Counter()
    
    for i in range(2, int(n**0.5) + 1):        
        while n % i == 0:
            factors[i] += 1
            n //= i
    
    if n != 1:
        factors[n] += 1
    
    return factors



n = int(input())
if n == 1:
    print(1, 0)
    exit()

factors = factorization(n)

primes = list(factors.keys())
exp = list(factors.values())

max_exp = 2**ceil(log(max(exp), 2))

m = 1
for i in primes:
    m *= i 

count = int(log(max_exp, 2))

if(min(exp) != max_exp):
    count += 1

min_n = 1
for p in primes:
    min_n *= p

print(m, count)
