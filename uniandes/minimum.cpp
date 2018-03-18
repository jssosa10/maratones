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
long long z[20]={0}, c[20]={0};
char nm[10];
long long n,x,i,j,tmp,sum=0;
int main(){
	scanf("%lld",&n);
	for( i = 0; i<n; i++){
		scanf(" %s",nm);
		int l  = strlen(nm);
	       for( j = l-1,x=1;j>=0; j-- ){
			tmp = nm[j]-'a';
			c[tmp]+=x;
			x*=10;
			if(j==0){
				z[tmp]=1;
			}
	       }	       
	}
	for( i = 0; i<10; i++){
		for(j =0, tmp = -1; j<10; j++){
			if(i==0){
				if(z[j]==0&&c[j]>tmp){
					tmp = c[j];
					x=j;
				}

			}
			else{
				if(c[j]>tmp){
					tmp=c[j];
					x=j;
				}
			}
		}
		sum+=(c[x]*i);
		c[x]=-1;
	}
	printf("%lld\n",sum);
	return 0;
}

