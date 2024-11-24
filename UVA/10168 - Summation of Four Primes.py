'''
Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=35&page=show_problem&problem=1109

By Soliman Elhassanein

TC: O(n log log n)
MC: O(n)

Date: 24-Nov-2024
'''

def sieve(max_n):
    primes = []
    is_prime = [True] * (max_n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(pow(max_n, 1/2)) + 1):
        if is_prime[i]:
            for j in range(i * i, max_n + 1, i):
                is_prime[j] = False

    for i in range(max_n + 1):
        if is_prime[i]:
            primes.append(i)

    return primes, is_prime


def four_prime_sum(n, primes, is_prime):
    if n < 8:
        return "Impossible."

    if n % 2 == 0:
        p1, p2 = 2, 2
    else:
        p1, p2 = 2, 3

    remainder = n - (p1 + p2)

    for p3 in primes:
        if p3 > remainder:
            break
        p4 = remainder - p3
        if p4 > 0 and is_prime[p4]:
            return f"{p1} {p2} {p3} {p4}"

    return "Impossible."

max_n = 10_000_000
primes, is_prime = sieve(max_n)

while True:
    try:
        line = int(input())
        print(four_prime_sum(line, primes, is_prime))
    except EOFError:
        break

