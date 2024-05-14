#include <stdio.h>

int main() {
	int a, b;
    printf("안녕하세요 스타트업 동아리 Just입니다.\n");
    sleep(1);
    printf("초심자를 위한 난이도의 코드를 준비해봤습니다.\n");
    sleep(1);
    printf("코드가 이해되지 않아도 괜찮아요, 영어나 숫자 또는 혼합으로 이루어진 6글자의 Flag를 찾아보세요!");
	scanf("%d %d", &a, &b);
	printf("%.d\n", (int)a / b);
    int start = 0, end = 10;
    char str[10] = "Justkr";
    for(int i = 0; i < 9; i++) {
        if(i < 10/2){
            start = i, end--;	
        }
        else{
            start--, end++;	
        }
        for(int j = start; j > 0; j--){
            printf(" ");
        } 
        for(int j = start; j < end; j++){
            printf("*");
        }
        printf("\n");
    }
    for (int i=0 ; i<6 ; i++){
        printf("%c",str[i]);
    }
	return 0;
}