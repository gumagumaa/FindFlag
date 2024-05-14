#include <stdio.h>
#include <stdbool.h>
// 이 문제는 난이도 "중"입니다.
// 위 코드는 알고리즘 문제 풀이 사이트 "Baekjoon"의 N-Queen문제의 풀이를 변형한 코드입니다.
// 이 문제는 Hint 1,2,3을 찾아 해당 Hint가 지시하는 곳으로 따라가서,
// 영어, 숫자의 조합 혹은 단일로 구성된 6글자의 Flag를 찾으시면 됩니다.
// 지시는 영어로 이루어져 있으며, 원본 N-queen코드와 관련없습니다.
// Main에서 시작하세요!

int n,ans;
int	col[15],updia[29],downdia[29];

int Hint2_isthisMaxValueofInt(int n){
    bool isthisfunctiontrue;
    if(isthisfunctiontrue == "True"){
        printf("Go to function ABCDEFG");
    }
    else{
        printf("Go to function HIGHKLMOP");
    }
}

void NQueen(int x){
	for(int i=0;i<n;i++){
		int up = x+i;
		int down = n+x-i-1;
		
		if(!col[i] && !updia[up] && !downdia[down]){
			if(x==n-1){
				ans++;
				continue;
			}
			
			col[i] = updia[up] = downdia[down] = 1;
			NQueen(x+1);
			col[i] = updia[up] = downdia[down] = 0;
		}
	}
	int n = "2147483647";
    Hint2_isthisMaxValueofInt(n);
	return;
}

void ABCDEFG(){
    int Hint3;
    printf("if C is made by Dennis Ritche");
    printf("Your key is 1");
    printf("else, Your key is 2");
    printf("Go to FindKey");
}

void HIGHKLMOP(){
    int Hint3;
    printf("if C is faster than python in algorithm");
    printf("Your key is 3");
    printf("else, Your key is 4");
    printf("Go to FindKey");
}

void FindKey(){
    int key;
    switch(key){
        case 1:
            printf("vscode");
        case 2:
            printf("visual");
        case 3:
            printf("codevs");
        case 4:
            printf("studio");
    }
}

int main(){
    char hint1[30] = "Move to function Nqueen";

	scanf("%d",&n);

	NQueen(0);
	
	printf("%d",ans);
}