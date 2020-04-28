#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define pi              acos(-1)
#define ordered_set     tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define MAX             100005
#define MOD             1000000007

typedef long long ll;

char grid[1005][1005];
ll dp[1005][1005];

int main()
{
    ll h,w;

    cin>>h>>w;

    for(ll i=1; i<=h; i++)
        for(ll j=1; j<=w; j++)
            cin>>grid[i][j];

    dp[1][1] = 1;

    for(ll i=2; i<=h; i++)
        if(grid[i][1]!='#')
            dp[i][1] = dp[i-1][1];

    for(ll i=2; i<=w; i++)
        if(grid[1][i]!='#')
            dp[1][i] = dp[1][i-1];

    for(ll i=2; i<=h; i++)
    {
        for(ll j=2; j<=w; j++)
        {
            if(grid[i][j]=='#')
                dp[i][j] = 0;
            else
                dp[i][j] = ((dp[i-1][j]%MOD)+(dp[i][j-1]%MOD))%MOD;
        }
    }

    cout<<dp[h][w];
}
