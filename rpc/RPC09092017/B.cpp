#include <bits/stdc++.h>
using namespace std;
int T,n,res, vals[1005], dp1[1005], dp2[1005];
int main()
{
    scanf("%d",&T);
    while(T--){
        
        scanf("%d",&n);
        res = 0;
        for(int i = 0; i<n; i++){
            int act;
            scanf("%d",&act);
            vals[i]=act;
            dp1[i]=dp2[i]=0;
        }
        dp1[0]=dp2[n-1]=1;
        int res = 0;
        for(int i  =1; i<n; i++){
            int maxx = 0;
            for (int j = 0;j<i;j++){
                if(vals[i]>vals[j]){
                    maxx = max(maxx,dp1[j]);
                }
                
            }
            dp1[i]=maxx+1;
        }
        for(int i  =n-2; i>=0; i--){
            int maxy = 0;
            for (int j = i+1;j<n;j++){
                if(vals[i]>vals[j]){
                    maxy = max(maxy,dp2[j]);
                }
                
            }
            dp2[i]=maxy+1;
        }
        for (int i = 0; i < n; ++i)

        {
           // printf("%d %d %d\n",i,dp1[i],dp2[i]);
            res = max(res,dp1[i]+dp2[i]-1);
        }

        printf("%d\n",res);
    }
    
}