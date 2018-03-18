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
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod=MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}
const int N = 50002;
int n, arr[N], next_[N], par[N], depth[N];
vector<int> adj[N];
int st, stack_[N], sz, trie[256*8][2], cnt[256*8];
int best_most_significant_eight[N][202], best_lower_significant_eight[N][258];
inline void insert(int val){
	int curr = 0;
	for(int i=7;i>=0;i--){
		int dir = (val >> i) & 1;
		if(trie[curr][dir] == -1)	trie[curr][dir] = ++sz;
		curr = trie[curr][dir];
		cnt[curr]++;
	}
}

inline void remove(int val){
	int curr = 0;
	for(int i=7;i>=0;i--){
		int dir = (val >> i) & 1;
		if(trie[curr][dir] == -1)	assert(0);
		curr = trie[curr][dir];
		cnt[curr]--;
	}
}


inline int query(int val){
	int curr = 0, ans = 0;
	for(int i=7;i>=0;i--){
		int dir = (val >> i) & 1;
		if(trie[curr][1^dir] != -1 && cnt[trie[curr][1^dir]] > 0){
			ans += (1<<i);
			curr = trie[curr][1^dir];
		}
		else{
			if(trie[curr][dir] == -1)	assert(0);
			curr = trie[curr][dir];
		}
	}
	return ans;
}


void dfs(int v, int par){

	::par[v] = par;
	stack_[++st] = v;
	depth[v] = st;
	next_[v] = stack_[max(0, st - 256)];

	for(int i=st;i>0&&i>st-256;i--){
		int node = stack_[i], val = arr[node];
		best_lower_significant_eight[v][val>>8] = max(best_lower_significant_eight[v][val>>8], (val & 255) ^ (st - i));
	}

	insert(arr[v] >> 8);
	if(next_[v] > 0)	remove(arr[next_[v]] >> 8);
	for(int i=0;i<=200;i++)
		best_most_significant_eight[v][i] = query(i);

	for(auto vv : adj[v])
		if(vv != par)
			dfs(vv, v);

	remove(arr[v] >> 8);
	if(next_[v] > 0)	insert(arr[next_[v]] >> 8);
	st--;
}



int solve(int u, int v){

	int most_sig_8 = 0, ans = 0;
	int vv = v;
	while(depth[v] - depth[u] >= 256){

		int temp = best_most_significant_eight[v][most_sig_8];
		int req = temp ^ most_sig_8;

		ans = max(ans, (temp << 8) + best_lower_significant_eight[v][req]);

		most_sig_8++;
		v = next_[v];
	}
	while(v != 0 && depth[v] >= depth[u]){
		ans = max(ans, arr[v] ^ (depth[vv] - depth[v]));
		v = par[v];
	}

	return ans;
}
int main(){
    int q;
    scanf("%d%d", &n, &q);
    for(int i=1;i<=n;i++)
    	scanf("%d", &arr[i]);
    int e = n-1;
    while(e--){
    	int a, b;
    	scanf("%d%d", &a, &b);
    	adj[a].pb(b);
    	adj[b].pb(a);
    }

    sz = 0;
    memset(trie, -1, sizeof(trie));
    dfs(1, -1);
    while(q--){
    	int u, v;
    	scanf("%d%d", &u, &v);
    	printf("%d\n", solve(u, v));
    }

    return 0;
}
