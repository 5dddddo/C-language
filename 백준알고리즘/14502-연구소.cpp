//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//queue <pair<int, int>> que;
//vector<pair<int, int>> v;
//int N, M, ans = -1;
//int map[8][8], origin[8][8];
//bool visited[8][8];
//int dir[4][2] = { {-1,0},{1 ,0 },{ 0, -1},{ 0,1 } };
//void printary();
//void bfs();
//void countSafe();
//void copyMap();
//void wall(int cnt);
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//			origin[i][j] = map[i][j];
//			if (map[i][j] == 2)
//				que.push({ i,j });
//		}
//	}
//	//�� �����
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (map[i][j]==0) {
//				copyMap();
//				map[i][j] = 1;
//				wall(1);
//				map[i][j] = 0;
//			}
//		}
//	}
////	cout << ans << endl;
//	return 0;
//}
//
//void bfs() {
//	while (!que.empty()) {
//		pair<int, int> tmp = que.front();
//		visited[tmp.first][tmp.second] = true;
//		que.pop();
//		for (int i = 0; i < 4; i++) {
//			int newX = tmp.first + dir[i][0];
//			int newY = tmp.second + dir[i][1];
//			if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
//				if (!visited[newX][newY] && !map[newX][newY]) {
//					map[newX][newY] = 2;
//					que.push({ newX,newY });
//				}
//			}
//		}
//	}
//	countSafe();
//}
//int copyMap() {
//	int tmp = 0;
//	memset(visited, 0, sizeof(visited));
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (map[i][j] == 0) tmp++;
//			map[i][j] = origin[i][j];
//		}
//	}
//	return tmp;
//}
//void wall(int x, int y, int d) {
//	map[x][y] = 1;
//	visited[x][y] = 1;
//	if (cnt == 3) {
//		bfs();
//		return;
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (map[i][j]==0) {
//				map[i][j] = 1;
//				wall(cnt + 1);
//				map[i][j] = 0;
//			}
//		}
//	}
//}

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX_SIZE 8
#define INF 0x7fffffff

using namespace std;
//input
int map[MAX_SIZE][MAX_SIZE];
int m, n;

//process
bool visit[MAX_SIZE][MAX_SIZE];
int max_value;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

vector<pair<int, int> > virus;

void input()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);

			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}
}

void copy_map(int(*a)[MAX_SIZE], int(*b)[MAX_SIZE])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

int recovery(int(*a)[MAX_SIZE], int(*b)[MAX_SIZE])
{
	int ret = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0) ret++;
			a[i][j] = b[i][j];
		}
	}
	return ret;
}

void bfs()
{
	queue<pair<int, int> > q;
	for (int i = 0; i < virus.size(); i++) q.push(virus[i]);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n || map[nx][ny] != 0) continue;

			map[nx][ny] = 2;
			q.push(make_pair(nx, ny));
		}
	}
}

void dfs(int x, int y, int d)
{
	map[x][y] = 1;
	visit[x][y] = 1;	

	if (d == 3)
	{
		//bfs
		int tmp[MAX_SIZE][MAX_SIZE];
		copy_map(tmp, map);

		bfs();
		max_value = max(max_value, recovery(map, tmp));

		visit[x][y] = 0;
		map[x][y] = 0;
		return;
	}

	for (int i = x; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] || map[i][j] != 0) continue;
			dfs(i, j, d + 1);
		}
	}

	map[x][y] = 0;
	visit[x][y] = 0;
}

void process()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] != 0) continue;
			dfs(i, j, 1);
		}
	}

	printf("%d\n", max_value);
}

int main()
{
	input();
	process();

	return 0;
}
