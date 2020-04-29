#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define pi              acos(-1)
#define ordered_set     tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define MAX             2005
#define MOD             1000000007

typedef long long ll;

int main()
{
    ll k,ans;

    cin>>k;

    queue<ll>q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    while(k--)
    {
        ll x = q.front();

        q.pop();

        ll rem = x%10;

        if(x%10!=0)
            q.push((10*x)+rem-1);

        q.push((10*x)+rem);

        if(x%10!=9)
            q.push((10*x)+rem+1);

        ans = x;
    }

    cout<<ans;

}
