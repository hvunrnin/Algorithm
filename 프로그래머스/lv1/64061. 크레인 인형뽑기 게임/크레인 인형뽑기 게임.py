def solution(board, moves):
    array=[]
    answer = 0
    for i in moves:
        for b in range(len(board)):
            if board[b][i-1] != 0:
                if len(array)==0:
                    array.append(board[b][i-1])
                elif len(array)!=0:
                    if array[-1]==board[b][i-1]:
                        array.pop()
                        answer+=2
                    else:
                        array.append(board[b][i-1])  
                board[b][i-1]=0
                break
    return answer