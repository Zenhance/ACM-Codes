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
        ll a,b,p,add,pos=-1,sum=0,indi=-1;
        char ch;

        cin>>a>>b>>p;

        string s;
        vector<ll>v,ans;

        cin>>s;

        ch = s[0];
        if(ch=='A')
            add=a;
        if(ch=='B')
            add=b;
        v.push_back(add);
        for(ll i=1; i<s.size()-1; i++)
        {
            if(s[i]!=ch)
            {
                ch = s[i];
                if(ch=='A')
                    add=a;
                if(ch=='B')
                    add=b;
                v.push_back(add);
            }
            else
                v.push_back(0);
        }


        for(ll i=v.size()-1; i>=0; i--)
        {
            sum+=v[i];
            ans.push_back(sum);
        }
        for(ll i=0; i<ans.size(); i++)
        {

            if(ans[i]<=p and indi!=ans[i])
            {
                pos=i;
                indi = ans[i];
            }
        }
        cout<<s.size()-pos-1<<endl;
    }

}
