#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define pi              acos(-1)
#define ordered_set     tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;

int main()
{
    FastRead

    ll n,m;

    cin>>n>>m;

    set<ll>s;
    vector<ll>ans(n+1,0);

    for(ll i=1;i<=n;i++)
        s.insert(i);

    for(ll i=0;i<m;i++)
    {
        ll l,r,x;

        cin>>l>>r>>x;

        auto it = s.lower_bound(l);

        while(s.size()!=1)
        {
            ll temp = *it;

            if(temp>r)
                break;
            if(temp!=x and ans[temp]==0)
            {
                it++;
                ans[temp] = x;
                s.erase(temp);
                continue;
            }
            it++;
        }
    }

    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}
