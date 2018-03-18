/*
 * I won't be broken
 * I won't be tortured
 * I won't be beaten down
 * I have the answer
 * I can take the pressure
 * I will turn it all around
 * Lift me up above this
 * The flames and the ashes
 * Lift me up and help me to fly away
*/
#include <bits/stdc++.h>
using namespace std;
int n,m;
char mp[55][55],ins[105],mpp[24][24];
bool pruebe(int i, int x, int y){
	for(int j = 0; ins[j]; j++){
		int c = ins[j]-'0';
	       	if(mpp[i][c]=='D'){
			if(y+1<n&&(mp[y+1][x]=='E'||mp[y+1][x]=='.'||mp[y+1][x]=='S')){
				y = y+1;
			}
			else return false;

		}	
		if(mpp[i][c]=='U'){
			if(y-1>=0&&(mp[y-1][x]=='E'||mp[y-1][x]=='.'||mp[y-1][x]=='S')){
				y=y-1;
			}
			else return false;
		}
		if(mpp[i][c]=='L'){
			if(x-1>=0&&(mp[y][x-1]=='E'||mp[y][x-1]=='.'||mp[y][x-1]=='S')){
				x=x-1;
			}
			else return false;
		}
		if(mpp[i][c]=='R'){
			if(x+1<m&&(mp[y][x+1]=='E'||mp[y][x+1]=='.'||mp[y][x+1]=='S')){
				x=x+1;
			}
			else return false;
		}
		if(mp[y][x]=='E'){
			return true;
		}

	}
	return false;
}

int main(){
	int ans = 0;
	strcpy(mpp[0],"DLUR");
	strcpy(mpp[1],"DLRU");
	strcpy(mpp[2],"DULR");
	strcpy(mpp[3],"DURL");
	strcpy(mpp[4],"DRUL");
	strcpy(mpp[5],"DRLU");
	strcpy(mpp[6],"RLUD");
	strcpy(mpp[7],"RLDU");
	strcpy(mpp[8],"RULD");
	strcpy(mpp[9],"RUDL");
	strcpy(mpp[10],"RDUL");
	strcpy(mpp[11],"RDLU");
	strcpy(mpp[12],"ULDR");
	strcpy(mpp[13],"ULRD");
	strcpy(mpp[14],"UDLR");
	strcpy(mpp[15],"UDRL");
	strcpy(mpp[16],"URDL");
	strcpy(mpp[17],"URLD");
	strcpy(mpp[18],"LDUR");
	strcpy(mpp[19],"LDRU");
	strcpy(mpp[20],"LUDR");
	strcpy(mpp[21],"LURD");
	strcpy(mpp[22],"LRUD");
	strcpy(mpp[23],"LRDU");

	scanf("%d%d",&n,&m);
	for(int i = 0; i<n; i++)
		scanf(" %s",mp[i]);
	scanf("%s",ins);
	int x1,y1;
	for(int i = 0; i<n; i++)
		for(int  j = 0; j<m; j++)
			if(mp[i][j]=='S')
				x1=j,y1=i;
	for(int i  =0; i<24; i++){
		if(pruebe(i,x1,y1))
			ans++;
	}
	//pruebe(3,x1,y1);
	printf("%d\n",ans);
	return 0;
}
