class Solution {
    int count=0;
    
    public int solution(int[] numbers, int target) {
        int answer = 0;
        dfs(numbers, 0, target, 0);
        answer=count;
        return answer;
    }
    
    public void dfs(int[] numbers, int depth, int target, int sum){
        if(numbers.length==depth && sum==target){
            count++;
            return;
        }
        else if(numbers.length>depth){
            dfs(numbers, depth+1, target, sum-numbers[depth]);
            dfs(numbers, depth+1, target, sum+numbers[depth]);
            return;   
        }
    }
}