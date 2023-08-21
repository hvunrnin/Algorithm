def solution(s):
    num=0
    length=0
    while s!="1":
        for i in s:
            if i=="0":
                num+=1
        length+=1
        s = s.replace("0","")
        s = format(len(s), 'b')
    answer = []
    answer.append(length)
    answer.append(num)
    return answer