def solution(numbers):
    tmp=list(map(str,numbers))
    tmp.sort(key = lambda x:x*3, reverse=True)
    #tmp=''.join(str(x) for x in tmp)
    tmp=str(int(''.join(tmp)))
    return tmp
