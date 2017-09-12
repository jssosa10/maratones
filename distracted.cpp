#include <bits/stdc++.h>
using namespace std;
int T,act,nums[100005];
set<int> pos;
int main(){
    pos.clear();
    scanf("%d\n",&T);
    pos.insert(T);
    for(int i = 1;i<=T;i++){
        scanf("%d",&act);
        nums[i]=act;
    }
    bool puede[T+1];
    memset(puede,false,sizeof(puede));
    for(int i=T-1;i>=1;i--){
            if(i+1+nums[i]>T&&nums[i]==T-i){
                puede[i]=true;
                pos.insert(i-1);  
            }
            else if(puede[i+nums[i]+1]&&i+1+nums[i]<=T){
                puede[i]=true;
                pos.insert(i-1);
            }
            
    }
    for(set<int>::iterator it = pos.begin(); it!=pos.end(); ++it){
        if(*it!=0)
        printf("%d\n",*it);
    }
}