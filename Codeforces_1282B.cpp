#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
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
        ll n,p,k,ans=0;

        cin>>n>>p>>k;

        vector<int> a(n+1,0),sum(n+1,0);
        vector<int>::iterator it;

        for(ll i=1; i<=n; i++)
            cin>>a[i];

        sort(a.begin(),a.end());

        for(ll i=1; i<k; i++)
            sum[i] = sum[i-1]+a[i];

        for(ll i=k; i<=n; i++)
            sum[i] = sum[i-k]+a[i];

        for(ll i=1; i<=n; i++)
        {
            //cout<<sum[i]<<" ";
            if(sum[i]<=p)
                ans=i;
        }
        cout<<ans<<endl;
    }

}
