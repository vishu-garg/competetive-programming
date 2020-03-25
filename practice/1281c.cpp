#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m=1000000007;
int main()
{
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll x;
        cin>>x;
        string s;
        cin>>s;
        ll S;
        S=s.length();
        // ll t=1;
        // while(s.length()<x)
        // {
        //     string temp;
        //     for(ll i=t;i<s.length();i++)
        //     temp+=s[i];

        //     // cout<<s[t-1]-1<<endl;

        //     for(ll i=0;i<(s[t-1]-'0'-1);i++)
        //     s+=temp;

        //     // cout<<s<<endl;

        //     S=s.length();
        //     // cout<<S[t]<<endl;
        //     t++;
        // }
        // cout<<s<<endl;
        // for(ll i=0;i<t;i++)
        // cout<<S[i]<<endl;
        for(ll i=1;i<=x;i++){
        int v = s[i - 1] - '1';
        if (s.size() < x) {
            vector<char> sub(s.begin() + i, s.end());
            for (int it = 0; it < v; it++) s.insert(s.end(), sub.begin(), sub.end());
        }
        S=(S+((S-i)*(s[i-1]-'1')))%m;
        // cout<<S[i]<<endl;
        }

        cout<<((S%m)+m)%m<<endl;
    }
}