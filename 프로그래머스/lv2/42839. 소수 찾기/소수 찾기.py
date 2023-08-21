from itertools import permutations
import math

def solution(numbers):
    arr=[]
    for i in range(1, len(numbers)+1):    
        arr += list(permutations(numbers, i))
    arr = set([int(("").join(p)) for p in arr])
    
    ans=[]
    for i in arr:
        check = True
        if i<2:
            check = False
            continue
        for n in range(2, int(math.sqrt(i)) + 1):
            if i%n==0:
                check = False
                break
        if check==True:
            ans.append(arr)
    
    answer = len(ans)
    return answer