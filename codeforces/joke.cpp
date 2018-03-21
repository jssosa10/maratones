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
int a[28]={0};
char s[505];
int main(){
	scanf("%s",s);
	for(int i = 0; s[i]; i++){
		a[s[i]-'A']++;
	}
	scanf("%s",s);
	for(int i = 0; s[i]; i++){
		a[s[i]-'A']++;
	}
	scanf("%s",s);
	for(int  i= 0; s[i]; i++){
		if(a[s[i]-'A']<=0){
			printf("NO\n");
			return 0;
		}
		a[s[i]-'A']--;
	}
	for(int i = 0; i<28; i++){
		if(a[i]>0){
			printf("NO\n");
			return 0;
		}

	}
	printf("YES\n");
	return 0;
}

