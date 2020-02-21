#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define NUM             100005

const int INF = 1e9+5;

typedef long long ll;

int a[NUM],dp[NUM];

long long solve(ll n, ll k)
{
    for(ll i=0;i<n;i++)
        dp[i] = INF;

    dp[0] = 0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<=i+k;j++)
        {
            if(j<n)
                dp[j] = min(dp[j],dp[i]+abs(a[i]-a[j]));
        }
        //cout<<dp[i]<<" ";
    }

    return dp[n-1];
}

int main()
{
    ll n,k;

    cin>>n>>k;

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<solve(n,k);
}
