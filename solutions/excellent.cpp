#include <bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int maxn = 1e5+5;
const int inf = 0x3f3f3f3f;
int T,n;
int tree[maxn<<2];
struct node{
	int a,b,c;
	bool operator<(const node &t)const{
		return a<t.a;
	}
}st[maxn];
void update(int loc,int num,int l, int r, int rt){
	if(l==r){
		tree[rt]=min(tree[rt],num);
		return;
	}
	int m =(l+r)>>1;
	if(loc<=m)update(loc,num,lson);
	else update(loc,num,rson);
	tree[rt]=min(tree[rt<<1],tree[(rt<<1)|1]);
	return;
}
int query(int L,int R, int l, int r, int rt){
	if(L<=l&&r<=R){
		return tree[rt];
	}
	int m = (l+r)>>1;
	int ans = inf;
	if(R>m)
		ans = min(ans,query(L,R,rson));
	if(L<=m)
		ans = min(ans,query(L,R,lson));
	return ans;	
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 0; i<n; i++){
			scanf("%d%d%d",&st[i].a,&st[i].b,&st[i].c);
		}
		sort(st,st+n);
		int cnt = 0;
		memset(tree,inf,sizeof(tree));
		for(int i = 0;i<n;i++){
			int tmp = query(1,st[i].b,1,n,1);
			if(tmp>st[i].c)cnt++;
			update(st[i].b,st[i].c,1,n,1);
		}
		printf("%d\n",cnt);
	}
	return 0;
}