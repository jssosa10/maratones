#include <bits/stdc++.h>
using namespace std;
int m,n;
char x,y;
//a = 97, z= 122
int g[28][28];
char s1[51], s2[51];
bool verificar(char s1[],char s2[]){
	if(strlen(s1)==strlen(s2)){
		int l = strlen(s1);
		for(int i = 0;i<l;i++){
			char c1=s1[i],c2=s2[i];
			if(!g[((int)c1)-97][((int)c2)-97])
				return false;
		}
		return true;
	}
	return false;
	
}
int main(){
	while(scanf("%d %d",&m,&n)==2){
		memset(g,0,sizeof(g));
		for(int i = 0; i<27;i++)
			g[i][i]=1;
		while(m--){
			char sp;
			scanf("%c%c %c",&sp,&x,&y);
			g[((int)x)-97][((int)y)-97]=1;
		}
		for(int  k =0; k<27; k++){
			for(int i = 0; i<27;i++){
				for(int j = 0; j<27; j++){
					if(!g[i][j])
						g[i][j]=g[i][k]*g[k][j];
				}
			}
		}
		while(n--){
			scanf("%s %s",s1,s2);
			if(verificar(s1,s2))
				printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}