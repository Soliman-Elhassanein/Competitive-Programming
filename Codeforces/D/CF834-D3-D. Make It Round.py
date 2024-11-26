'''
Link: https://codeforces.com/problemset/problem/1759/D

By Soliman Elhassanein

TC: O( t * log(n * m) )
MC: O( 1 )

Date: 26-Nov-2024
'''


t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    original_n = n
    cnt2 = cnt5 = 0
    temp_n = n
    while temp_n % 2 == 0:
        temp_n //= 2
        cnt2 += 1
    while temp_n % 5 == 0:
        temp_n //= 5
        cnt5 += 1

    k = 1
    # Balance exponents by multiplying with powers of 2 or 5
    if cnt2 < cnt5:
        # Multiply k by as many 2s as possible without exceeding m
        while cnt2 < cnt5 and k * 2 <= m:
            k *= 2
            cnt2 += 1
    elif cnt5 < cnt2:
        # Multiply k by as many 5s as possible without exceeding m
        while cnt5 < cnt2 and k * 5 <= m:
            k *= 5
            cnt5 += 1

    # Multiply k by as many 10s as possible without exceeding m
    while k * 10 <= m:
        k *= 10
        cnt2 += 1
        cnt5 += 1

    # Maximize n * k
    q = m // k
    k *= q
    print(original_n * k)
