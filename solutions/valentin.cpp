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
int n;
set<char> is, nots;
int main(){
	scanf("%d",&n);
	int res=0;
	bool ad = false;
	for(char i ='a'; i<='z'; i++)
		is.insert(i);
	while(n--){
		char s[100005],c[200];
		scanf("%s %s",c,s);
		//printf("%c\n",c[0]);
		if(c[0]=='.'){
			for(int i = 0; s[i]; i++){
				nots.insert(s[i]);
				if(is.find(s[i])!=is.end())
					is.erase(is.find(s[i]));
			}
			//printf("%ld\n",is.size());
		}
		else if(c[0]=='!'&& is.size()>0){
			set<char>s2;
			for(int i = 0; s[i]; i++){
				if(is.find(s[i])!=is.end())
					s2.insert(s[i]);
			}
			is = s2;
			//printf("%ld\n",is.size());
		}
		else if(c[0]=='!'&&is.size()==0){
			for(int i = 0; s[i]; i++){
				is.insert(s[i]);
			}

		}
		else if(n!=0&&c[0]=='?'&&is.find(s[0])!=is.end()){
			is.erase(is.find(s[0]));
		}
		else if(!ad&&n==0)
			res = 0;
		if(ad&&(c[0]=='?'||c[0]=='!')&&n!=0)res++;
		if(is.size()==1&&!ad){
			ad = true;
		}
	}
	printf("%d\n",res);
	return 0;
}

