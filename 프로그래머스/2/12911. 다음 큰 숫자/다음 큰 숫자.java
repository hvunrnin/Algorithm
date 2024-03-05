import java.lang.Integer;
import java.util.Arrays;

class Solution {
    public int solution(int n) {
        int answer = 0;
        String bin = Integer.toBinaryString(n); //먼저 2진수로 변환
        int count = 0;
        for(int i=0;i<bin.length();i++){
            if(bin.charAt(i)=='1'){ //1 개수 세기
                count++;
            }
        }
        
        for(int i=n+1;i<1000000;i++){ //n보다 큰 수 중 1 개수 같은 거 찾으려고
            int count2=0;
            String bin2 = Integer.toBinaryString(i);
            for(int j=0;j<bin2.length();j++){
                if(bin2.charAt(j)=='1'){
                    count2++;
                }
            }
            if(count==count2){
                answer=i;
                break; // 찾으면 바로 나오기
            }
        }
        
        return answer;
    }
}