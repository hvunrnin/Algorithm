import java.lang.*;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] numbers, int num1, int num2) {
        System.out.println(num2-num1);
        int[] answer = Arrays.copyOfRange(numbers, num1, num2+1);
        return answer;
    }
}