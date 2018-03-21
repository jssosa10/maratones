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
set<char> ss;
char s[104];
int main(){
	scanf("%s",s);
	for(int i = 0; s[i]; i++)
		ss.insert(s[i]);
	if(ss.size()%2)
		printf("IGNORE HIM!\n");
	else
		printf("CHAT WITH HER!\n");
	return 0;
}

