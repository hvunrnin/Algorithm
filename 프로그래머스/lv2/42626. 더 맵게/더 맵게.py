import heapq
def solution(scoville, K):
    num=0
    heapq.heapify(scoville)
    
    while scoville[0]<K:
        if len(scoville)==1:
            return -1
        min1=heapq.heappop(scoville)
        min2=heapq.heappop(scoville)
        new=min1+(min2*2)
        heapq.heappush(scoville, new)
        num+=1
    return num