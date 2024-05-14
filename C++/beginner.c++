#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int n=0;
    cin >> n;
    printf("안녕하세요 스타트업 동아리 Just입니다.\n");
    printf("디미고를 들어오면 수업시간에 풀게될 초심자를 위한 난이도의 코드를 준비해봤습니다.\n");
    printf("코드가 이해되지 않아도 괜찮아요, 영어나 숫자 또는 혼합으로 이루어진 6글자의 Flag를 찾아보세요!");
    string str1 = "Dimigo hs kr";
    string str2 = "Just";
    for(int i=1 ; i<=n ; i++){
        for(int j=n-1 ; j>0 ; j--){
            cout << " ";
        }
        for(int j=2*i-1 ; j>0 ; j--){
            cout << "*";
        }
        cout << "\n";
    }
    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<i ; j++){
            cout << " ";
        }
        for(int j=2*(n-i)-1 ; j>0 ; j--){
            cout << "*";
        }
        cout << "\n";
    }
}