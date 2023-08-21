def solution(n):
    arr=[0,1]
    for i in range(1,n):
        arr.append(arr[i-1]+arr[i])
    answer = arr[n]
    answer%=1234567
    return answer