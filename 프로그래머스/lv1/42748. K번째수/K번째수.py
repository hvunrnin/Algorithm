def solution(array, commands):
    answer=[]
    for i in commands:
        array_new = array[i[0]-1:i[1]]
        array_new.sort()
        answer.append(array_new[i[2]-1])
    return answer