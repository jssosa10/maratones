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
int t,n,m,x,k;
char s[1000005];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&x,&k);
		scanf("%s",s);
		int e = 0,o = 0;
		for(int i = 0; s[i]; i++){
			if(s[i]=='E')
				e++;
			else
				o++;
		}
		for(int i = 1; i<=m; i++){
			if(i%2==0){
				n-=min(e,x);
				e-=min(e,x);
			}
			else{
				n-=min(o,x);
				o-=min(o,x);
			}
		}
		if(n<=0){
			printf("yes\n");
		}
		else
			printf("no\n");
	}
	return 0;
}

