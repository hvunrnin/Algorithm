import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = new int[arr.length];
        answer[0]=arr[0];
        int cnt=1;
        for(int i=1;i<arr.length;i++){
            if(arr[i]!=arr[i-1]){
                answer[cnt]=arr[i];
                cnt++;
            }
        }
        return Arrays.copyOf(answer, cnt);
    }
}