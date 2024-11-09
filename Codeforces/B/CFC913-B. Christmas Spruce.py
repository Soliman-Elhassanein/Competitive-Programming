'''
Link: https://vjudge.net/problem/CodeForces-913B

By Soliman Elhassanein

TC: O(n)
MC: O(n)

Date: 09-Nov-2024
'''


n = 0

n = int(input())

counter = [0] * n
reduced = [0]  * n
relations = [0] * n
expected = [1]

for i in range(n-1):
    k = int(input())
    relations[i+1] = k
    counter[k] += 1
    
    if(k != 1 and reduced[k] != 1):
        expected.append(k)
        reduced[k] = 1
        counter[relations[k-1]] -= 1


f = 1 if any(counter[i] < 3 for i in expected) else 0

if f == 1:
    print("No")
else:
    print("Yes")
