def solution(numbers, hand):
    pad = {1:[0,0], 2:[0,1], 3:[0,2],
           4:[1,0], 5:[1,1], 6:[1,2],
           7:[2,0], 8:[2,1], 9:[2,2],
           '*':[3,0], 0:[3,1], '#':[3,2]}
    answer = ''
    
    left=pad['*']
    right=pad['#']
    
    for num in numbers:
        if num==1 or num==4 or num==7:
            left=pad[num]
            answer+='L'
        elif num==3 or num==6 or num==9:
            right=pad[num]
            answer+='R'
        else:
            left_diff=abs(left[0]-pad[num][0])+abs(left[1]-pad[num][1])
            right_diff=abs(right[0]-pad[num][0])+abs(right[1]-pad[num][1])
            if left_diff<right_diff:
                left=pad[num]
                answer+='L'
            elif left_diff>right_diff:
                right=pad[num]
                answer+='R'
            else:
                if hand=="left":
                    left=pad[num]
                    answer+='L'
                else:
                    right=pad[num]
                    answer+='R'
    return answer