#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll s,i,e,l,ul;
        cin>>s>>i>>e;
        ul=e;
        ll tmp=i+e-s;
        l=tmp/2;
        if(l<=0 && tmp<0)l=0;
        else l++;
        if(l<=ul)
        cout<<ul-l+1<<endl;
        else 
        cout<<0<<endl;
    }
}