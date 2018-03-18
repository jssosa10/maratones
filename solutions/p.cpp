#include <bits/stdc++.h>
using namespace std;
struct data{
    int id,_1,_2,_3;
    bool operator < (const data& p)const{
        if(_1*3+_2*2+_3==p._1*3+p._2*2+p._3){
            if(_1==p._1){
                if(_2==p._2){
                    return id>p.id;
                }
                return _2<p._2;
            }
            return _1<p._1;
        }
        return _1*3+_2*2+_3<p._1*3+p._2*2+p._3;
    }
};
int n;
int main() {
    while(scanf("%d",&n)==1&&n){
        int i,d,sz=0;
        map<int,data>mp;
        for(i=1;i<=n;i++){
            scanf("%d",&d);
            int j;
            for(j=1; j<=d;j++){
                int p,q;
                scanf("%d",&p);
                mp[p].id=p;
                if(j==1)mp[p]._1++;
                else if(j==2)mp[p]._2++;
                else mp[p]._3++;
            }
        }
        vector<data>v;
        for(map<int,data>::iterator it=mp.begin(); it!=mp.end(); ++it){
            pair<int,data> m = *it;
            v.push_back(m.second);
        }
            
        sort(v.begin(),v.end());
        n=v.size();
        for(i =n-1;i>=0;i--){
            if(i==n-1){
                printf("%d",v[i].id);
                continue;
            }
            if(v[i]._1*3+v[i]._2*2+v[i]._3==v[n-1]._1*3+v[n-1]._2*2+v[n-1]._3){
                if(v[i]._1==v[n-1]._1&&v[i]._2==v[n-1]._2){
                    printf(" %d",v[i].id);
                }
            }
        }
        printf("\n");
    }
    return 0;
}