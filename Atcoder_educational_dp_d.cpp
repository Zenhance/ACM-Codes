#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(NULL);
#define endl            "\n"
#define NUM             100005
typedef long long ll;

long long n,w,weight[NUM],value[NUM],dp[105][NUM];

long long solve(long long i,long long m)
{
    ll profit1,profit2;

    if(i==n+1)
        return 0;

    if(dp[i][m]!=-1)
        return dp[i][m];

    if(m+weight[i]<=w)
        profit1 = value[i]+solve(i+1,m+weight[i]);
    else
        profit1=0;

    profit2 = solve(i+1,m);

    dp[i][m] = max(profit1,profit2);

    return dp[i][m];
}


int main()
{
    FastRead

    //long long n,w;

    memset(dp,-1,sizeof(dp));

    cin>>n>>w;

    for(ll i=0;i<n;i++)
    {
        cin>>weight[i]>>value[i];
    }

    cout<<solve(0,0);
}
