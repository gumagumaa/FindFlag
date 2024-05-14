#include<cstdio>
 
// 이 문제는 난이도 "하"입니다.
// 위 코드는 알고리즘 문제 풀이 사이트 "Baekjoon"의 "별찍기11" 문제의 풀이를 변형한 코드입니다.
// 영어, 숫자의 조합 혹은 단일로 구성된 6글자의 Flag를 찾으시면 됩니다.
// 원본 "별찍기 - 11" 모범코드와 Flag는 관련없으며, return은 정답이 아닙니다.

char DB[][6]=
{ "  *  ",
  " * * ",
  "*****" };
char MAP[3500][6500];
char hex_color[10] = "E89100";
void solve(int n, int y, int x)
{
    if (n == 1)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                MAP[y + i][x + j] = DB[i][j];
        return;
    }
    solve(n / 2, y, x + 3 * n / 2);
    solve(n / 2, y + 3 * n / 2, x);
    solve(n / 2, y + 3 * n / 2, x + 3 * n);
}
 
int main()
{
    int n;
    scanf("%d", &n);
    solve(n / 3, 0, 0);
    for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<2*n-1;j++)
            printf("%c", MAP[i][j] == '*' ? '*' : ' ');
    return 0;
}