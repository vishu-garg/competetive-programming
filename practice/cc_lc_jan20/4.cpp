#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,q;
    cin>>n>>q;
    ll a[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    ll inc[n],dec[n];
    inc[0]=0;
    dec[0]=0;
    if(a[1]<a[0]){
    inc[1]=0;
    dec[1]=1;}
    else if(a[1]>a[0]){
    dec[1]=0;
    inc[1]=1;}
    for(ll i=2;i<n;i++)
    {
        if(a[i]<a[i-1] && a[i-1]>a[i-2]){
        inc[i]=inc[i-1];
        dec[i]=dec[i-1]+1;}
        else if(a[i]<a[i-1]){
        inc[i]=inc[i-1];
        dec[i]=dec[i-1];}
        else if(a[i]>a[i-1] && a[i-1]<a[i-2]){
        dec[i]=dec[i-1];
        inc[i]=inc[i-1]+1;}
        else if(a[i]>a[i-1]){
        dec[i]=dec[i-1];
        inc[i]=inc[i-1];}
    }
    
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l=l-1;
        r=r-1;
        if(l==0)
        {
            if(inc[r]==dec[r])
            cout<<"YES";
            else 
            cout<<"NO";
        }
        else
        {
            if(a[l]>a[l-1]&& a[l]<a[l+1])
            {
                ll ans_inc=inc[r]-inc[l]+1;
                ll ans_dec=dec[r]-dec[l];
                if(ans_inc==ans_dec)
                cout<<"YES";
                else 
                cout<<"NO";
            }
            else if(a[l]>a[l-1] && a[l]>a[l+1])
            {
                ll ans_inc=inc[r]-inc[l];
                ll ans_dec=dec[r]-dec[l];
                if(ans_inc==ans_dec)
                cout<<"YES";
                else 
                cout<<"NO";
            }
            else if(a[l]<a[l-1] && a[l]>a[l+1])
            {
                ll ans_inc=inc[r]-inc[l];
                ll ans_dec=dec[r]-dec[l]+1;
                if(ans_inc==ans_dec)
                cout<<"YES";
                else 
                cout<<"NO";
            }
            else if(a[l]<a[l-1] && a[l]<a[l+1])
            {
                ll ans_inc=inc[r]-inc[l];
                ll ans_dec=dec[r]-dec[l];
                if(ans_inc==ans_dec)
                cout<<"YES";
                else 
                cout<<"NO";   
            }
            cout<<endl;
        }
    }
}