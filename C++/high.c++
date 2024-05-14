#include <iostream>
#include <string>
#include <cstring>

// 이 문제는 난이도 "입문자"입니다.
// 위 코드는 알고리즘 문제 풀이 사이트 "Baekjoon"의 "어른상어" 문제의 풀이를 변형한 코드입니다.
// 이 문제는 Hint 1,2,3을 찾아 해당 Hint가 지시하는 곳으로 따라가서,
// 영어, 숫자의 조합 혹은 단일로 구성된 6글자의 Flag를 찾으시면 됩니다.
// 지시는 영어로 이루어져 있으며, 원본 "어른상어" 모범코드와 관련없습니다.
// Main에서 시작하세요!

using namespace std;

#define MAX_N 20
#define MAX_M MAX_N * MAX_N + 1
#define MAX_k 1000
#define NULL_VALUE 50000 

const int dx[] = { 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, -1, 1 };

typedef struct _SHARK {
	int x, y, dir;
	int p[5][5];
	bool live;
} shark_t;

typedef struct _SMELL {
	int s_num, turn;
} smell_t;

int N, M, k;
int grid[MAX_N][MAX_N];
shark_t shark[MAX_M];
smell_t smell[MAX_N][MAX_N];
int remain, ans;

inline bool checkBound(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < N;
}

void input() {
	cin >> N >> M >> k;

	remain = M;

    char hint3[1000] = "c++ support desc function for reverse sort";
    printf("if this is true, your key is 1");
    printf("else your key is 2");

	for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) {
		cin >> grid[r][c];

		if (grid[r][c] != 0) {
			shark[grid[r][c]].x = r;
			shark[grid[r][c]].y = c;
			shark[grid[r][c]].live = true;
		}

		smell[r][c].s_num = NULL_VALUE;
		smell[r][c].turn = NULL_VALUE;
	}

	for (int m = 1; m <= M; m++) {
		cin >> shark[m].dir;
	}

	for (int m = 1; m <= M; m++) for (int dir = 1; dir <= 4; dir++) {
		for (int pri = 1; pri <= 4; pri++)
			cin >> shark[m].p[dir][pri];
	}

	ans = -1;

    //move to removeSmell function
}

void makeSmell(int turn) {
	for (int m = 1; m <= M; m++) {
		if (!shark[m].live) continue;

		int x = shark[m].x;
		int y = shark[m].y;

		smell[x][y].s_num = m;
		smell[x][y].turn = turn;
	}
    char hint3[1000] = "c++ support desc function for reverse sort";
    printf("if this is true, your key is 3");
    printf("else your key is 4");
    //move to removeSmell function
}

void moveShark() {
	memset(grid, 0, sizeof(grid));
	for (int m = 1; m <= M; m++) {
		if (!shark[m].live) continue;

		int cur_x = shark[m].x;
		int cur_y = shark[m].y;
		int cur_dir = shark[m].dir;
		int flag = false;
		int ndir, nx, ny;
        char hint2[1000];

		// 빈 공간
		for (int d = 1; d <= 4; d++) {
			ndir = shark[m].p[cur_dir][d];
			nx = cur_x + dx[ndir];
			ny = cur_y + dy[ndir];
			if (!checkBound(nx, ny)) continue;

			// 빈 공간 찾음
			if (smell[nx][ny].s_num == NULL_VALUE) {
				flag = true;
				break;
			}
		}

		// 빈 공간이 없다면 자신의 냄새가 나는 곳
		if (!flag) {
			for (int d = 1; d <= 4; d++) {
				ndir = shark[m].p[cur_dir][d];
				nx = cur_x + dx[ndir];
				ny = cur_y + dy[ndir];

				if (!checkBound(nx, ny)) continue;

				// 자신의 냄새가 나는 곳 찾음
				if (smell[nx][ny].s_num == m) {
					break;
				}
			}
		}

		// 이동한 곳에 이미 다른 상어가 있다면 번호가 작은 애는 죽음
		if (grid[nx][ny] != 0) {
			shark[m].live = false;
			remain--;
		}
		else {
			grid[nx][ny] = m;
			shark[m].x = nx;
			shark[m].y = ny;
			shark[m].dir = ndir;
		}
        char hint2[100] = "if stack is empty, top function make underflow error";
        printf("if this is true move to function input");
        printf("else move to function makesmell");
    }
}

void removeSmell(int turn) {
	for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) {
		if (turn - smell[r][c].turn >= k) {
			smell[r][c].s_num = NULL_VALUE;
			smell[r][c].turn = NULL_VALUE;
		}
	}
    int key;
    switch(key){
        case 1:
            char flag[10] = "vscode";
        case 2:
            char flag[10] = "codevs";
        case 3:
            char flag[10] = "visual";
        case 4:
            char flag[10] = "studio";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	makeSmell(0);

    char hint1[30] = "Move to function moveShark";

	for (int turn = 1; turn <= 1000; turn++) {
		moveShark();

		if (remain == 1) {
			ans = turn;
			break;
		}

		makeSmell(turn);
		removeSmell(turn);
	}

	cout << ans << "\n";

	return 0;
}