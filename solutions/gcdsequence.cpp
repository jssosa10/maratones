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
int m,s[1005];
int main(){
	scanf("%d",&m);
	int g = 0;
	for(int i = 0; i<m; i++){
		scanf("%d",&s[i]);
		g  = __gcd(g,s[i]);
	}
	sort(s,s+m);
	if(s[0]!=g)printf("-1\n");
	else if(m>1){
		printf("%d\n",m*2-1);
		printf("%d %d",s[0],g);
		for(int  i = 1;i<m-1; i++){
			printf(" %d %d",s[i],g);
		}
		printf(" %d\n",s[m-1]);
	}
	else{
		printf("1\n");
		printf("%d\n",s[0]);
	}
	return 0;
}

