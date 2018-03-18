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
#define ps pair<string,int>
ps v[1000001];
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		priority_queue<int,vector<int>,greater<int>> q;
		int cnt =1;
		int num;
		string s;
		for(int i = 0; i<n;i++){
			cin>>s;
			if(s[0]!='r')
				scanf("%d",&num);
			if(s[0]=='r'){
				if(q.empty()){
					v[cnt]={"insert",0};
					cnt++;
					q.push(0);
				}
				q.pop();
			}
			else if(s[0]=='g'){
				while(!q.empty()&&q.top()<num){
					q.pop();
					v[cnt++]={"removeMin",0};
				}
				if(q.empty()||q.top()!=num){
					v[cnt]={"insert",num};
					cnt++;
					q.push(num);
				}
			}
			if(s[0]!='r')
				v[cnt]={s,num};
			else
				v[cnt]={s,0};
			cnt++;
			if(s[0]=='i')
				q.push(num);
		}
		cnt--;
		printf("%d\n",cnt);
		int i;
		for(i =1; i<=cnt; i++){
			cout<<v[i].first<<' ';
			if(v[i].first[0]!='r')
				printf("%d\n",v[i].second);
			else
				putchar('\n');

		}
	}
	return 0;
}

