import java.util.Arrays;
class Solution {
    public String solution(String s) {
        String answer = "";
        char[] arr = s.toCharArray();
        if (Character.isAlphabetic(arr[0])&&Character.isLowerCase(arr[0])){
            arr[0]=Character.toUpperCase(arr[0]);
        }
        for(int i=1;i<s.length();i++){
            if(arr[i-1]==' '&&Character.isLowerCase(arr[i])){
                arr[i]=Character.toUpperCase(arr[i]);
            }
            else if(arr[i-1]!=' '&&Character.isUpperCase(arr[i])){
                arr[i]=Character.toLowerCase(arr[i]);
            }
        }
        answer=new String(arr);
        return answer;
    }
}