#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(NULL);
#define endl            "\n"
#define NUM             100005
typedef long long ll;

int a[NUM][3],dp[NUM][3];

int main()
{
    FastRead

    int n;

    cin>>n;

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<3;j++)
            cin>>a[i][j];
    }

    for(ll i=0;i<n;i++)
    {

            dp[i+1][0] = max(dp[i][1]+a[i][1],dp[i][2]+a[i][2]);
            dp[i+1][1] = max(dp[i][0]+a[i][0],dp[i][2]+a[i][2]);
            dp[i+1][2] = max(dp[i][0]+a[i][0],dp[i][1]+a[i][1]);
    }

    /*for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<3;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    cout<<max({dp[n][0],dp[n][1],dp[n][2]});
}
