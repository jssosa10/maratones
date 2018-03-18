#include <bits/stdc++.h>
using namespace std;
char s[1000066];
char q[1000055];
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int top = 0;
		stack<char> t;
		scanf("%s",s);
		int len = strlen(s);
		for (int i = 0; i < len; ++i){
			if(s[i]=='<'){
				if(top!=0){
					t.push(q[top-1]);
					top--;
				}
			}
			else if(s[i]=='>'){
				if(!t.empty()){
					q[top++]=t.top();
					t.pop();
				}
			}
			else if(s[i]=='-'){
				if(top!=0)top--;
			}
			else{
				q[top++]=s[i];
			}
		}
		while(!t.empty()){
			q[top++]=t.top();
			t.pop();
		}
		q[top]='\0';
		printf("%s\n", q);
	}
	return 0;
}
