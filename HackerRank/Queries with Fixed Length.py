'''
Link: https://www.hackerrank.com/challenges/queries-with-fixed-length/problem

By Soliman Elhassanein

TC: O( n * q )
MC: O( n )

Date: 11 Feb 2024
'''

from collections import deque

In = input()
m, n = list ( map ( int , In.split() ) )

In = input()
arr = list ( map ( int , In.split() ) )

while n:
    n -= 1
    
    In = input()
    d = list(map ( int , In.split() ))[0]
    
    deq = deque()
    min_of_max = float('inf')
    
    for i, value in enumerate(arr):
        # Remove indices that are out of the current window.
        if deq and deq[0] <= i - d:
            deq.popleft()
        
        # Remove indices whose corresponding values are less than or equal
        # to the current value (to maintain a decreasing order).
        while deq and arr[deq[-1]] <= value:
            deq.pop()
        
        deq.append(i)
        
        # When we have a complete window, update the result.
        if i >= d - 1:
            current_window_max = arr[deq[0]]
            if current_window_max < min_of_max:
                min_of_max = current_window_max
    
    print(min_of_max)
