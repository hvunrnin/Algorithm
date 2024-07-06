function solution(a, b) {
    var answer = 0;
    let small = Math.min(a,b);
    let big = Math.max(a,b);
    for(let i=small;i<=big;i++){
        answer+=i;
    }
    return answer;
}