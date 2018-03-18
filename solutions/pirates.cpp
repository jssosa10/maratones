#include <bits/stdc++.h>
using namespace std;
const int M = 2000005;
int T,n;
int A[M];
int tree[4*M];
int lazy[4*M];
void init(){
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
}
void relax(int node, int start, int end){
	if(lazy[node]!=0){
		if(lazy[node]==1) tree[node] = (end-start+1);
		else if(lazy[node]==2) tree[node] = 0;
		else if(lazy[node]==-1) tree[node]=(end-start+1)-tree[node];
		if(end!=start){
			if(lazy[node]==-1){
				int mid = (end+start)/2;
				relax(node*2,start,mid);
				relax(node*2+1,mid+1,end);
			}
			lazy[node*2]=lazy[node];
			lazy[node*2+1]=lazy[node];
		}
		lazy[node]=0;
	}
	
}
void build(int node, int start, int end){
    if(start == end){
        // Leaf node will have a single element
        tree[node] = A[start];
        return;
    }
    else{
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node]+tree[2*node+1];
    }
}
void updateRange(int node, int start, int end, int l, int r, int val){
   relax(node,start,end);
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
       lazy[node]=val;
       relax(node,start,end);
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2]+tree[node*2+1];        // Updating root with max value 
}

int queryRange(int node, int start, int end, int l, int r){
	relax(node,start,end);
    if(start > r or end < l)
        return 0;     // Out of range
    relax(node,start,end);
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return p1+p2;
}
int main(){
	scanf("%d",&T);
	for(int i  = 1; i<=T; i++){
		int m;
		scanf("%d",&m);
		int k = 0;
		for(int u = 1; u<=m; u++){
			int t;
			scanf("%d",&t);
			char s[60];
			scanf("%s",s);
			int len  = strlen(s);
			for(int j = 1; j<=t; j++ ){
				for (int l = 0; l < len; l++){
					A[++k] = s[l]-'0';
				}
			}
		}
		init();
		printf("Case %d:\n", i);
		int Q;
		n = k;
		scanf("%d",&Q);
		build(1,1,n);
		int qq = 0;
		for(int j  =1 ; j<= Q; j++ ){
			char t[10];
			int l,r;
			scanf("%s %d %d", t, &l, &r);
			l++; r++;
			if(t[0]=='F'){
				updateRange(1,1,n,l,r,1);
			}
			else if(t[0]=='E'){
				updateRange(1,1,n,l,r,2);
			}
			else if(t[0]=='I'){
				updateRange(1,1,n,l,r,-1);
			}
			else{
				qq++;
				int ans = queryRange(1,1,n,l,r);
				printf("Q%d: %d\n",qq,ans);
			}
		}
	}
	return 0;

}