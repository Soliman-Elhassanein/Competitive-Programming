'''
Link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=524

By Soliman Elhassanein

TC: O( n^(1.5) log log n  )
MC: O( n )

Date: 25-Nov-2024
'''

from math import floor

def sieve(n):
    isprime = [True] * (n + 1) 
    
    isprime[0] = isprime[1] = False
    
    for i in range(2, n+1):
        if isprime[i]:
            isprime[i*i:n+1:i] = [False] * len(range(i*i, n+1, i))
    
    prime = [i for i in range(n+1) if isprime[i]]
    
    return prime, isprime

def factorization(n, num_list):
    factors = []
    
    if n < 0:
        factors.append(-1)
    
    n = abs(n)
    
    for i in num_list:
        if i * i > n:
            break
        while n % i == 0:
            n //=i
            factors.append(i)
        
    if n > 1:
        factors.append(n)
    
    return factors    

max = floor(pow(2**31, 0.5)) # enough to factorize numbers upto 2**31

prime, isprime = sieve(max)

while True:
    n = int(input())
    
    if n == 0:
        break
    
    factors = factorization(n, prime)
    
    print(f"{n} = ", end='')
    print(' x '.join(map(str,factors)))
        
        
