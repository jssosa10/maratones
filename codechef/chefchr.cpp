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
int t;
char s[500005];
bool is(int i){
	vector<char> v;
	for(int x = i; x<i+4&&s[x]; x++ )
		v.push_back(s[x]);	
	sort(v.begin(),v.end());
	string p = "cefh";
//	printf("%c%c%c%c\n",v[0],v[1],v[2],v[3]);
	for(int x= 0; x<4; x++)
	//	printf("%c %c\n",p[i],v[i]);
		if(p[x]!=v[x])
			return false;
	return true;
}
int main(){
	scanf("%d",&t);
	while(t--){
		cin>>s;
		int res = 0;
		unsigned long int i  =0;
		for(i= 0; s[i];i++){
			if((s[i]=='c'||s[i]=='h'||s[i]=='e'||s[i]=='f')&&is(i))
				res++;
		}
		//printf("%c\n",s[i]);
		if(res > 0)
			printf("lovely %d\n",res);
		else
			printf("normal\n");
	}
	return 0;
}

