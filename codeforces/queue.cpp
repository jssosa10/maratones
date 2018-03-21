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
int n,t;
char s[100];
int main(){
	scanf("%d%d",&n,&t);
	scanf("%s",s);
	for(int i = 0; i<t; i++){
		for(int j = 0; j<n-1; j++){
			if(s[j]=='B'&&s[j+1]=='G'){
				s[j]='G';
				s[j+1] = 'B';
				j++;
			}
		}
	}
	printf("%s\n",s); 
	return 0;
}

