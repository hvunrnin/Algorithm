def solution(operations):
    arr=[]
    for i in operations:
        if i[0]=='I':
            i = i[2:]
            arr.append(i)
            arr = list(map(int, arr))
        elif i=='D 1':
            if len(arr)!=0:
                arr.remove(max(arr))
        elif i=='D -1':
            if len(arr)!=0:
                arr.remove(min(arr))
    answer=[]
    print(arr)
    if len(arr)==0:
        answer = [0,0]
    else:
        answer = [max(arr), min(arr)]
    return answer