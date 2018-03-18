#include <bits/stdc++.h>
using namespace std;
const int m = 32;
char bd[m][m];
bool marcado[m][m] = {false};
char l[m];
int T,R,C,us,res;
void dfs(int x, int y){
 if(bd[x][y]=='0'&&!marcado[x][y]){
  res++;
  marcado[x][y]=true;
  if(x-1>=0&&!marcado[x-1][y]){
   dfs(x-1,y);
  }
  if(x+1<R&&!marcado[x+1][y]){
   dfs(x+1,y);
  }
  if(y-1>=0&&!marcado[x][y-1]){
   dfs(x,y-1);
  }
  if(y+1<C&&!marcado[x][y+1]){
   dfs(x,y+1);
  }
  
 }
}
int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d",&R);
		scanf("%d",&C);
		us = 0;
		for(int i = 0; i<R; i++){
			scanf("%s",l);
			for (int j = 0; j < C; j++)
			{
				bd[i][j]=l[j];
				marcado[i][j]=false;
			}
		}
		res = 0;
		for(int i = 0; i<R; i++){
		 dfs(i,0);
		 dfs(i,C-1);
		}
		for(int i = 0; i<C; i++){
		 dfs(0,i);
		 dfs(R-1,i);
		}
		printf("%d\n",res);
	}
	return 0;
}