#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define endl            "\n"
#define NUM             100005

typedef long long ll;

int main()
{
    FastRead

    ll n,m,ans=0;
    map<ll,ll>mp;
    queue<ll>q;
    vector<ll>v;

    cin>>n>>m;

    ll a[n+5];

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=0;
        q.push(a[i]);
    }

    while(!q.empty())
    {
        if(v.size()==m)
            break;
        ll pos = q.front();
        q.pop();

        if(mp.count(pos-1)==0)
        {
            mp[pos-1] = mp[pos]+1;
            q.push(pos-1);
        }
        if(mp.count(pos+1)==0)
        {
            mp[pos+1] = mp[pos]+1;
            q.push(pos+1);
        }
        if(mp[pos]!=0)
        {
            ans+=mp[pos];
            v.push_back(pos);
        }
    }

    cout<<ans<<endl;
    for(ll i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}
