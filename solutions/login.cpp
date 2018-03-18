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
char name[15], last[15];
int main(){
	scanf("%s %s",name,last);
	printf("%c",name[0]);
	for(int i =1; name[i]; i++){
		if(name[i]<last[0])
			printf("%c",name[i]);
		else
			break;	
	}
	printf("%c\n",last[0]);
	return 0;
}

