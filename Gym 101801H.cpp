#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define pi              acos(-1);
#define ordered_set     tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define MAX             100005

typedef long long ll;

vector<ll>graph[MAX];
vector<ll>parent(MAX),csize(MAX);


void dfs(ll node ,ll par)
{
    csize[node] = 1;

    for(ll i=0;i<graph[node].size();i++)
    {
        if(graph[node][i]!=par)
        {
            parent[graph[node][i]] = node;
            dfs(graph[node][i],node);
            csize[node] += csize[graph[node][i]];
        }
    }
}

int main()
{
    FastRead

    ll t;
    cin>>t;

    while(t--)
    {
        ll n,a,b,ans=0;

        cin>>n>>a>>b;

        for(ll i=0;i<=n;i++)
        {
            parent[i] = -1;
            csize[i] = 0;
            graph[i].clear();
        }

        for(ll i=0;i<n-1;i++)
        {
            ll u,v;

            cin>>u>>v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        parent[a] = a;

        dfs(a,a);

        /*for(ll i=1;i<=n;i++)
            cout<<csize[i]<<endl;*/

        ll pver = parent[b];
        ll child = b;

        while(pver!=a)
        {
            ans += (csize[pver]-csize[child])*(csize[a]-csize[pver]);
            child = pver;
            pver = parent[pver];
        }

        ans+= (csize[a]-csize[b])*csize[b];

        cout<<ans<<endl;

    }
}

