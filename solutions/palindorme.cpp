#include <bits/stdc++.h>
using namespace std;
const int maxL = 1001;
const int maxN = 100001;
int arr[maxL];
int LPS[maxL][maxL];
int comp[maxN];
vector<int> graph[maxN];
void dfs(int s, int cc)
{
    comp[s] = cc;
    for(vector<int>::iterator it= graph[s].begin(); it!=graph[s].end(); ++it)
        if(!comp[*it])
            dfs(*it, cc);
}


int lps(int arr[], int L)
{
    int i, j, len;
    for(i=0; i<L; i++)
        LPS[i][i] = 1;

    for(len=2; len<=L; len++)
    {
        for(i=0; i<L+1-len; i++)
        {
            j = i + len - 1;
            if(comp[arr[i]] == comp[arr[j]])
            {
                if(len == 2)
                    LPS[i][j] = 2;
                else
                    LPS[i][j] = LPS[i+1][j-1] + 2;
            }
            else
                LPS[i][j] = max(LPS[i][j-1], LPS[i+1][j]);
        }
    }
    return LPS[0][L-1];
}
int main() {
    int N, K, L;
    scanf("%d %d %d", &N, &K, &L);
    for(int i=0; i<K; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int cc = 1;
    for(int i=1; i<=N; ++i)
        if(!comp[i])
        {
            dfs(i, cc);
            cc++;
        }
    for(int i=0; i<L; i++)
        scanf("%d", &arr[i]);
    printf("%3f\n", lps(arr, L));
    return 0;
}