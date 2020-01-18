#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"

typedef long long ll;
typedef pair<int,int> pii;

vector<pii>v;

int main()
{
    FastRead

    ll n,ans;

    cin>>n;

    ans = n*n;

    for(ll i=0;i<n;i++)
    {
        ll l;

        cin>>l;
        vector<int>s(l);


        for(ll i=0;i<l;i++)
            cin>>s[i];

        reverse(s.begin(),s.end());

        if(is_sorted(s.begin(),s.end()))
            v.push_back({s.front(),s.back()});
    }

    sort(v.begin(),v.end());

    for(ll i=0;i<v.size();i++)
        ans-=v.end()-lower_bound(v.begin(),v.end(),make_pair(v[i].second,-1));

    cout<<ans<<endl;
}
