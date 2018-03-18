#include <bits/stdc++.h>
using namespace std;
int n,res;
int main()
{
    while(scanf("%d",&n)==1&&n!=0){

        res = 0;

        for (int a = 1; a <= n; a++)
        {
            for (int b = a; b <= n; b++)
            {
                for (int c = b; c <= n; c++)
                {
                    if ((a*a)+(b*b) == c*c && c <= n)
                    {
                        res++;
                    }
                }
            }
        }
        printf("%d\n",res);
    }
    
}