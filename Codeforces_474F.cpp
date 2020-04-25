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
int gcd_query(int point,int l,int r,int i, int j)
{
    if(i>r or j<l)
        return 0;
    if(l>=i and r<=j)
        return segtree[point].gcd;

    int left = point<<1;
    int right = left|1;
    int mid = (l+r)>>1;

    return GCD(gcd_query(left,l,mid,i,j),gcd_query(right,mid+1,r,i,j));
}

int min_query(int point,int l,int r,int i, int j)
{
    if(i>r or j<l)
        return INT_MAX;
    if(l>=i and r<=j)
        return segtree[point].mi;

    int left = point<<1;
    int right = left|1;
    int mid = (l+r)>>1;

    return min(min_query(left,l,mid,i,j),min_query(right,mid+1,r,i,j));
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
        int l,r,gcd,mi;

        cin>>l>>r;

        gcd = gcd_query(1,1,n,l,r);
        mi = min_query(1,1,n,l,r);

        if(gcd!=mi)
            cout<<r-l+1<<endl;
        else
        {
            int cnt = upper_bound(mp[gcd].begin(),mp[gcd].end(),r)-lower_bound(mp[gcd].begin(),mp[gcd].end(),l);
            cout<<r-l+1-cnt<<endl;
        }
    }


}
