#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"

typedef long long ll;

int main()
{
    FastRead

    int n,k,sum=0;

    cin>>n>>k;

    vector<ll>v(n),b(n),cumi(n);

    vector<pair<ll,ll>>ans;

    for(ll i=0; i<n; i++)
        cin>>v[i];

    for(ll i=0; i<n; i++)
    {
        cin>>b[i];
        if(b[i]==0)
            sum+=v[i];
        cumi[i] = sum;
    }

    for(ll i=0; i<=n-k; i++)
    {
        ll x;
        if(i==0)
            x = cumi[i+k-1];
        else
            x = cumi[i+k-1]-cumi[i-1];
        //cout<<x<<endl;
        ans.push_back({x,i});
    }

    sort(ans.begin(),ans.end());

    /*for(ll i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;*/

    ll temp = ans.back().second;
    sum=0;
    for(ll i=temp; i<temp+k; i++)
        b[i] = 1;

    for(ll i=0; i<n; i++)
        if(b[i]==1)
            sum+=v[i];

    cout<<sum<<endl;
}
