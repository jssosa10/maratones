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
int n,m,a[105],b[105];
bool us[105];
int main(){
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d",&a[i],&b[i]);	
	}
	int minn = a[0];
	int maxx = b[0];
	for(int i  =1; i<n;i++){

		//printf("%d %d",minn,maxx);
		if(a[i]==minn&&b[i]>=maxx){
			//printf("Entro\n");
			maxx=b[i];
		}
		else if(a[i]<=maxx&&b[i]>=maxx){
			maxx = b[i];
		}
	}
	if(maxx==m&&minn==0)printf("YES\n");
	else printf("NO\n");
	return 0;
}

