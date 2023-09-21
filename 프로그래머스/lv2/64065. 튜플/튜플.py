def solution(s):
    s=s.replace(s[0],"")
    s=s.split('}')
    s=list(filter(None, s))

    for i in range(len(s)):
        if s[i][0] == ',':
            s[i] = s[i].replace(',', '', 1)
    s.sort(key=len)
    answer = []
    for i in s:
        i = i.split(',')
        for j in i:
            if int(j) not in answer:
                answer.append(int(j))
    return answer