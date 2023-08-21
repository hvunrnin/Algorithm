def solution(n, lost, reserve):
    reserve_real = set(reserve)-set(lost)
    lost_real = set(lost)-set(reserve)
    
    for i in reserve_real:
        if i-1 in lost_real:
            lost_real.remove(i-1)
        elif i+1 in lost_real: 
            lost_real.remove(i+1)
    answer=n-len(lost_real)
    
    return answer