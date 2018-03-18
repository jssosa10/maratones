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
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

char a[5005];
int n;
long long dp[5005][5005];

int main()
{
    long long ans = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf(" %c", &a[i]);

    bool flag = 0;

    dp[0][0] = 1;
    dp[0][1] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int lvl = n; lvl >= 1; lvl--)
        {
            if(!flag)
            {
                dp[i][lvl] = dp[i - 1][lvl] + dp[i][lvl + 1];
                dp[i][lvl] %= MOD;
            }
            else
            {
                dp[i][lvl] = dp[i - 1][lvl - 1];
            }
        }
        if(a[i] == 'f')
            flag = 1;
        else
            flag = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        ans += dp[n][i];
        ans %= MOD;
    }
    printf("%lld\n",ans);
    return 0;
}
