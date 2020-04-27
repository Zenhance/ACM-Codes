#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"

typedef long long ll;

int main()
{
    ll mx;
    string s,t,lcs;

    cin>>s>>t;

    ll ls = s.size();
    ll lt = t.size();

    ll memo [ls+1][lt+1];

    for(ll i=0;i<=ls;i++)
    {
        for(ll j=0;j<=lt;j++)
        {
            if(i==0 or j==0)
                memo[i][j] = 0;
            else if(s[i-1]==t[j-1])
                memo[i][j] = memo[i-1][j-1]+1;
            else
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
        }
    }


    for(ll i=ls,j=lt;i>0 and j>0;)
    {
        if(s[i-1]==t[j-1])
        {
            //cout<<memo[i][j]<<" ";
            lcs.push_back(s[i-1]);
            i--;
            j--;
        }
        else
        {
            if(memo[i-1][j]>memo[i][j-1])
                i--;
            else
                j--;
        }
    }

    reverse(lcs.begin(),lcs.end());

    cout<<lcs<<endl;
}
