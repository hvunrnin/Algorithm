def solution(citations):
    citations.sort()
    for i in citations:
        if i>=len(citations)-citations.index(i):
            return len(citations)-citations.index(i)
            # tmp=i
            # break
    #print(i)
    # num=citations.index(tmp)-1
    # answer = citations[num]
    #answer=0
    return 0