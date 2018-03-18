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
int n,months[26],m[12]={31,0,31,30,31,30,31,31,30,31,30,31};
int solv(){
	for(int i = 0;i<12;i++){
		bool logro =true;
		for(int j = 0; j<n; j++){
			if(months[j]!=m[(i+j)%12]){
				logro = false;
				break;
			}		
		}
		if(logro){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
int main(){
	scanf("%d",&n);
	int s = 0;
	for(int i = 0;i<n;i++){
		scanf("%d",&months[i]);
		if(months[i]==29)s++;
		if(months[i]==28||months[i]==29)
			months[i]=0;
	}
	if(s<2)
		solv();
	else
		printf("NO\n");
	return 0;
}

