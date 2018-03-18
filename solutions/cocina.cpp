#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int Max = 100002;
vi Graph[Max];
map<string,int>noms;
int costs [Max];
int dp [Max];
int dfs(int ini){
    if(dp[ini]=-1){
        int maxim = 0;
        for(vector<int>::iterator it= Graph[ini].begin(); it!=Graph[ini].end(); ++it){
            maxim = max(maxim,dfs(*it));
        }

        return dp[ini]=maxim+costs[ini];
    } else
        dp[ini];

}
int main(){
    memset(dp,-1,Max-1);
    int I,Q;
    scanf("%d",&I);
    for (int i = 1; i <= I ; i++) {
        int cost, ni;
        char name[50];
        scanf("%d %d %s", &cost, &ni, name);
        noms[name]= i;
        costs[i]=cost;
        while(ni--) {
            char data[50];
            scanf("%s",data);

            Graph[i].push_back(noms[data]);
        }
    }
    scanf("%d",&Q);
    while(Q--){
        char q[50];
        scanf("%s",q);
        Graph[0].push_back(noms[q]);

    }
    printf("%d\n",dfs(0));

}