#include <bits/stdc++.h>
using namespace std;
const int M = 2000005;
int T,n;
long long A[M];
long long tree[4*M];
long long lazy[4*M];
void init(){
	memset(tree,0,sizeof(tree));
	memset(lazy,0,sizeof(lazy));
}
void updateRange(int node, int start, int end, int l, int r, int val){
   //relax(node,start,end);
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
       tree[node]+=(end-start+1)*val;
       lazy[node]+=val;
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2]+tree[node*2+1]+lazy[node]*(end-start+1);        // Updating root with max value 
}

long long queryRange(int node, int start, int end, int l, int r,long long p = 0 ){
    if(start > r or end < l)
        return 0;     // Out of range
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node]+(end-start+1)*p;
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r,p+lazy[node]);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r,p+lazy[node]); // Query right child
    return p1+p2;
}
int main(){
	scanf("%d",&T);
	for(int i  = 1; i<=T; i++){
		int n,q;
		//memset(lazy,0,sizeof(lazy))
		scanf("%d%d",&n,&q);
		//for(int u = 0; u<n; u++){
		//	A[u]=0;
		//}
		init();
		printf("Scenario #%d:\n",i);
		//build(1,0,n-1);
		while(q--){
			char t[50];
			int l,r;
			scanf("%s %d %d",t,&l,&r);
			l--,r--;
			if(t[0]=='a'){
				printf("%lld\n", queryRange(1,0,n-1,l,r));
			}
			else{
				printf("OK\n");
				updateRange(1,0,n-1,l,r,1);
			}
		}
	}
	return 0;

}