#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(NULL);
#define endl            "\n"
#define NUM             100005
typedef long long ll;

int main()
{
    FastRead
    ll t;
    cin>>t;

    while(t--)
    {
        ll n,x;
        bool flag = false;

        cin>>n>>x;

        ll a[n];

        for(ll i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);

        for(ll i=0; i<n; i++)
        {
            if(a[i]==x)
            {
                flag = true;
                break;
            }
        }

        if(flag)
            cout<<1<<endl;
        else
        {
            ll ans = x/a[n-1];
            if(x%a[n-1])
                ans++;
            cout<<max(2LL,ans)<<endl;
        }
    }
}
