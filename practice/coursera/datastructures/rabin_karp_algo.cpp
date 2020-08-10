#include<bits/stdc++.h>
using namespace std;
#define ll long long
string pattern , text;
ll sz;
ll p=1e9+7;
ll x=263;
vector<ll>harr;
ll polyhash(string s)
{
    ll result=0;
    for(ll i=0;i<s.length();i++)
    {
        result=((result*x)+((ll)(s[i])))%p;
    }
    return result;
}
void hash_array(string text)
{
    ll h=1;
    ll pt=pattern.length();
    for(int i=0;i<pt-1;i++)
    h=(h*x)%p;

    harr[0]=polyhash(text.substr(0,pattern.length()));
    // cout<<harr[0]<<endl;
   for(int i=1;i<sz;i++)
    {
        ll tmp=((ll)(text[i-1])*(h))%p;
        tmp=(harr[i-1]-tmp)%p;
        if(tmp<0){tmp=(tmp+p)%p;}
        harr[i]=((tmp*x)%p+((ll)text[pt+i-1]))%p;
    }
}

int main()
{
    cin>>pattern;
    cin>>text;
    ll p_hash=polyhash(pattern);
    // cout<<p_hash<<endl;
    sz=text.length()-pattern.length()+1;
    harr=vector<ll>(sz);
    hash_array(text);
    // ll ans=0;
    for(ll i=0;i<sz;i++)
    {
        // cout<<harr[i]<<" , ";
        if(p_hash==harr[i])
        {
            ll fnd=0;
            for(ll j=0;j<pattern.size();j++)
            {
                if(text[i+j]!=pattern[j])
                {
                    fnd=1;
                    break;
                }
            }
            if(fnd==0)
            {
                cout<<i<<" ";
            }
        }
    }
    // cout<<ans<<endl;
}