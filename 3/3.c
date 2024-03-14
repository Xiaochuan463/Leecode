#include<stdio.h>

int lengthOfLongestSubstring(char* s) {
        char* start = s, *end = s;
        int max = 1;
        char arr[128];
        int i  = 0;
        char sin;
        if(*end == '\0'){
                return 0;
        }
        for(i = 0; i < 128; i++){
                arr[i] = 0;
        }
        sin = *end;
        arr[sin]++;
        do{
                if(arr[sin] < 2){
                        max = max > (end-start+1) ? max : (end-start+1);
                        end++;
                        sin = *end;
                        arr[sin]++;
                        
                }
                else{
                        arr[*start]--;
                        start++;
                }
        }while(*(end) != '\0');
        return max;
}
int main() {
    char s[] = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(s)); // 输出 3
    return 0;
}