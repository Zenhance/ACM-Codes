#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(NULL);
#define endl            "\n"
#define NUM             1000005
typedef long long ll;

const ll MOD = 1e9+7;

int main()
{
    FastRead

    ll n,ans=0;

    cin>>n;

    vector<ll>v(n);

    for(ll i=0;i<n;i++)
        cin>>v[i];


    for(ll i=0;i<60;i++)
    {
        ll zero=0,one=0;
        for(ll j=0;j<n;j++)
        {
            if((v[j]>>i)&1)
                one++;
            else
                zero++;
        }

        ll temp = zero*one;

        temp%=MOD;

        for(ll j=0;j<i;j++)
            temp = (temp*2)%MOD;

        ans+=temp;
        ans%=MOD;
    }

    cout<<ans<<endl;
}
