def solution(nums):
    length = len(nums)/2
    nums = set(nums)
    if len(nums)>length:
        answer=length
    else:
        answer=len(nums)
    return answer