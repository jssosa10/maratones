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
int n,a[200005];
char s[200005];
int main(){
	scanf("%d",&n);
	for(int i = 1; i<=n; i++)
		scanf("%d",a+i);
	scanf("%s",s);
	int i  =1;
	while(i<=n-1){
		int ss = i;
		while(i<=n-1 && s[i-1]=='1')i++;
		i++;
		if(i>n+1)i=n+1;
		sort(a+ss,a+i);

	}
	for(int i = 1; i<=n; i++){
		if(a[i]!=i){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}

