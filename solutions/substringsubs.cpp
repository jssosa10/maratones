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
char s[5005],t[5005];
int a[5005][5005],j;
#define mod 1000000007
int main(){
	scanf("%s",s);
	scanf("%s",t);
	for(int i=0; s[i]; i++)
		for( j=0; t[j]; j++)
			a[i+1][j+1]=(a[i+1][j]+(t[j]==s[i])*(a[i][j]+1))%mod;
	int ans = 0;
	for(int i = 0; s[i]; i++)
		ans = (ans+a[i+1][j])%mod;
	printf("%d\n",ans);
	return 0;
}

