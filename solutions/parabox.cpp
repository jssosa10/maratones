#include <bits/stdc++.h>
using namespace std;
//UVA12519
int n, m, g[105][105], x, y, v;
int main() {
	while(scanf("%d %d", &n, &m) == 2 && n+m) {
		memset(g, 0x3f, sizeof(g));
		while(m--) {
			scanf("%d %d %d", &x, &y, &v);
			g[x][y] = min(g[x][y], v);
			g[y][x] = min(g[y][x], -v);
		}
		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		int ret = 1;
		for(int i = 1; i <= n; i++)
			ret &= g[i][i] >= 0;
		puts(ret ? "N" : "Y");
	}
	return 0;
}