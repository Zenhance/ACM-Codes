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


int main()
{
    FastRead

    ll t;

    cin>>t;

    while(t--)
    {
        ll n,k,ans=0;

        cin>>n>>k;

        vector<ll>v(n);

        for(ll i=0;i<n;i++)
            cin>>v[i];

        sort(v.begin(),v.end());

        ll low = 0,high = v.back();

        while(low<high)
        {
            ll mid = low + (high-low+1)/2;

            ll index = 0;

            for(ll i=0;i<n;i++)
                index+=v[i]/mid;

            if(index>=k)
            {
                ans = mid;
                low = mid;
            }
            else
            {
                high = mid-1;
            }
            //cout<<low<<" "<<mid<<" "<<high<<endl;
        }

        cout<<ans<<endl;
    }
}
