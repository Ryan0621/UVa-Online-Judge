#include <iostream>
#include <cstring>
using namespace std;

int R,C,M,N,W;
int grid[100][100];
int dr[] = {-1,1,-1,1};
int dc[] = {1,-1,-1,1};

bool visited[100][100];

void dfs(int i, int j) {
	if(visited[i][j]){
		return;
	}
	visited[i][j] = true;
	for (int k=0; k < 4; k++) {
		int a = i+dr[k]*M, b = j+dc[k]*N;
		if (a>=0 && a<R && b>=0 && b<C && grid[a][b]!=-1) {
			//grid[i][j]++; or
			grid[a][b]++;
			dfs(a,b);
		}
		a = i+dr[k]*N, b = j+dc[k]*M;
		if (a>=0 && a<R && b>=0 && b<C && grid[a][b]!=-1) {
			//grid[i][j]++; or
			grid[a][b]++;
			dfs(a,b);
		}
	}
}

int main() {
	int tc;
	cin>>tc;
	for (int t=0; t < tc; t++) {
		memset(grid, 0, sizeof(grid));
		memset(visited, false, sizeof(visited));
		int even = 0, odd = 0;
		cin>>R>>C>>M>>N;
		cin>>W;
		while (W--) {
			int x,y;
			cin>>x>>y;
			grid[x][y] = -1;
		}

		dfs(0,0);
		for(int i = 0 ; i < R; i++){
			for(int j = 0 ; j < C; j++){
				if(grid[i][j]!=-1){
					if(M==0 || N==0 || M==N){
						grid[i][j] /= 2;
					}
					if(grid[i][j] || (i==0 && j==0)){
						if(grid[i][j]%2 == 0)
							even++;
						else odd++;
					}
				}

			}

		}
		cout<<"Case "<<t+1<<": "<<even<<" "<<odd<<endl;

	}
	return 0;
}
