#include <bits/stdc++.h>
using namespace std;
char data[100];
char pat[4];
int fill(char* s1, char* s2){
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	//printf("%d %d\n",l1,l2);
	int lookup[l1+1][l2+1] = { {0} };
	for(int i = 0; i<= l2; ++i)
		lookup[0][i]=0;
	for(int i = 0; i<= l1; ++i)
		lookup[i][0]=1;
	for(int i = 1; i<=l1; i++){
		for(int j = 1; j<=l2; j++){
			if(s1[i-1]==s2[j-1])
				lookup[i][j]=lookup[i-1][j-1]+lookup[i-1][j];
			else
				lookup[i][j]=lookup[i-1][j];
		}
	}
	return lookup[l1][l2];
}
int main(){
	scanf("%s",data);
	char pat [4];
	pat[0]='Q';
	pat[1]='A';
	pat[2]='Q';
	pat[3] = '\0';
	printf("%d\n",fill(data,pat));
	return 0;
}