#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define pi              acos(-1)
#define ordered_set     tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define MAX             150005

typedef long long ll;

ll n,m;
vector<ll>v(MAX),segtree(3*MAX);

void init(ll node,ll l,ll r,ll level)
{
    if(l==r)
    {
        segtree[node] = v[l];
        return;
    }

    ll left = node*2;
    ll right = node*2+1;
    ll mid = (l+r)/2;

    init(left,l,mid,level-1);
    init(right,mid+1,r,level-1);

    if(level%2)
        segtree[node] = segtree[left]|segtree[right];
    else
        segtree[node] = segtree[left]^segtree[right];
}

void update(ll node, ll l,ll r,ll level,ll update_node,ll newvalue)
{
    if(update_node>r or update_node<l)
        return;
    if(l>=update_node and r<=update_node)
    {
        segtree[node] = newvalue;
        return;
    }

    ll left = node*2;
    ll right = node*2+1;
    ll mid = (l+r)/2;

    update(left,l,mid,level-1,update_node,newvalue);
    update(right,mid+1,r,level-1,update_node,newvalue);

    if(level%2)
        segtree[node] = segtree[left]|segtree[right];
    else
        segtree[node] = segtree[left]^segtree[right];
}

int main()
{
    FastRead

    ll N;

    cin>>n>>m;

    N = powl(2,n);

    for(ll i=1;i<=N;i++)
        cin>>v[i];

    init(1,1,N,n);

    while(m--)
    {
        ll pos,val;

        cin>>pos>>val;

        update(1,1,N,n,pos,val);

        cout<<segtree[1]<<endl;
    }

}
