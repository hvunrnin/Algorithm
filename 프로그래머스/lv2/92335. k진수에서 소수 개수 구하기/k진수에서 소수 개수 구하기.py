import math

def check(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n%i==0:
            return False
    return True
    
def solution(n, k):
    changed = ''
    while n > 0:
        n, mod = divmod(n, k)
        changed+=str(mod)
    changed = changed[::-1]
    changed_split = changed.split('0')
    
    answer=0
    print(changed_split)
    for i in changed_split:
        if i=='1':
            continue
        if i:  # 빈 문자열이 아닌 경우에만 검사
            num = int(i)  # 문자열을 정수로 변환
            if check(num):
                answer += 1  # 소수인 경우 카운트 증가
            
    return answer