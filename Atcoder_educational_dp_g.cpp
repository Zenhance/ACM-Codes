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

vector<ll>graph[MAX],dp(MAX);
bool vis[MAX];

void dfs(ll node)
{
    vis[node] = true;

    for(ll i=0; i<graph[node].size(); i++)
    {
        if(!vis[graph[node][i]])
            dfs(graph[node][i]);

        dp[node] = max(dp[node],1+dp[graph[node][i]]);
    }
}

int main()
{
    ll n,m,ans=INT_MIN;

    cin>>n>>m;

    for(ll i=0; i<m; i++)
    {
        ll u,v;

        cin>>u>>v;

        graph[u].push_back(v);
    }

    for(ll i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);

    for(ll i=1; i<=n; i++)
        ans = max(ans,dp[i]);

    cout<<ans<<endl;
}
