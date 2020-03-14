
#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define endl            "\n"
#define NUM             1000005

typedef long long ll;

ll n,q,cnt,sq=174;

ll frq[NUM],ans[200005],a[30005];

pair<pair<ll,ll>,ll>query[200005];

bool compare(pair<pair<ll,ll>,ll> a , pair<pair<ll,ll>,ll> b)
{
    if(a.first.first/sq==b.first.first/sq)
        return a.first.second<b.first.second;
    else
        return a.first.first/sq<b.first.first/sq;
}

void add(int index)
{
    frq[a[index]]++;
    if(frq[a[index]]==1)
        cnt++;
}

void remove(int index)
{
    frq[a[index]]--;
    if(frq[a[index]]==0)
        cnt--;
}

int main()
{

    FastRead

    ll left,right,mo_left=0,mo_right=0;

    cin>>n;

    for(ll i=0;i<n;i++)
        cin>>a[i];

    cin>>q;

    for(ll i=0;i<q;i++)
    {
        cin>>query[i].first.first>>query[i].first.second;
        query[i].first.first--;
        query[i].first.second--;
        query[i].second = i;
    }

    sort(query,query+q,compare);


    for(ll i=0;i<q;i++)
    {
        left = query[i].first.first;
        right = query[i].first.second;

        while(mo_right<=right)
        {
            add(mo_right);
            mo_right++;
        }

        while(mo_right>right+1)
        {
            remove(mo_right-1);
            mo_right--;
        }

        while(mo_left<left)
        {
            remove(mo_left);
            mo_left++;
        }

        while(mo_left>left)
        {
            add(mo_left-1);
            mo_left--;
        }

        ans[query[i].second] = cnt;
    }

    for(ll i=0;i<q;i++)
        cout<<ans[i]<<endl;
}
