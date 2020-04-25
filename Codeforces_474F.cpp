#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define pi              acos(-1)
#define MAX             100005
#define MOD             1000000007

typedef long long ll;

struct node
{
    int gcd;
    int mi;
};

vector<int>v(MAX);
vector<node>segtree(3*MAX);

int GCD(int a,int b)
{
    if(b>a)
        swap(a,b);
    while(b)
    {
        int r = a%b;
        a = b;
        b = r;
    }

    return a;
}

void init(int point,int l,int r)
{
    if(l==r)
    {
        segtree[point].gcd = v[l];
        segtree[point].mi = v[l];
        return;
    }

    int left = point<<1;
    int right = left|1;
    int mid = (l+r)>>1;

    init(left,l,mid);
    init(right,mid+1,r);

    segtree[point].gcd = GCD(segtree[left].gcd,segtree[right].gcd);
    segtree[point].mi = min(segtree[left].mi,segtree[right].mi);
}

pair<long long,long long> query(int point,int l,int r,int i, int j)
{
    if(i>r or j<l)
        return {0,INT_MAX};
    if(l>=i and r<=j)
        return {segtree[point].gcd,segtree[point].mi};

    int left = point<<1;
    int right = left|1;
    int mid = (l+r)>>1;

    int gcd = GCD(query(left,l,mid,i,j).first,query(right,mid+1,r,i,j).first);
    int mi = min(query(left,l,mid,i,j).second,query(right,mid+1,r,i,j).second);

    return {gcd,mi};
}

int main()
{
    FastRead

    int n,q;
    map<int,vector<int>>mp;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        mp[v[i]].push_back(i);
    }

    init(1,1,n);

    cin>>q;

    while(q--)
    {
        pair<int,int>x;
        int l,r;

        cin>>l>>r;

        x = query(1,1,n,l,r);

        if(x.first!=x.second)
            cout<<r-l+1<<endl;
        else
        {
            int cnt = upper_bound(mp[x.first].begin(),mp[x.first].end(),r)-lower_bound(mp[x.first].begin(),mp[x.first].end(),l);
            cout<<r-l+1-cnt<<endl;
        }
    }


}
