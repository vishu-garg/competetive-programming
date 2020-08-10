#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
vector<vector<ll>> segt1(34,vector<ll>(200005,0));
vector<vector<ll>> lazy1(34,vector<ll>(200005,0));
vector<ll>v;

void build_tree(vector<ll>&segt,vector<ll>&lazy,ll ind,ll l , ll r)
{
    if(l==r)
    {
        segt[ind]=v[l];
        lazy[ind]=0;
        return;
    }
    
    ll mid=(l+r)/2;
    
    build_tree(segt,lazy,2*ind+1,mid+1,r);
    build_tree(segt,lazy,2*ind,l,mid);
    
    segt[ind]=segt[2*ind]+segt[2*ind+1];
    lazy[ind]=0;
    return;
    
}

void update(vector<ll>&segt,vector<ll>&lazy,ll ind,ll l ,ll r,ll ind1,ll ind2)
{
    
    if(lazy[ind]!=0)
    {
        segt[ind]=((r-l+1)-segt[ind]);
        lazy[2*ind]^=1;
        lazy[2*ind+1]^=1;
        lazy[ind]=0;
    }
    
    if(l>ind2 || r<ind1)
        return;
    
    if(l>=ind1 && r<=ind2)
    {
        segt[ind]=((r-l+1)-segt[ind]);
        if(l!=r)
        {
            lazy[2*ind]^=1;
            lazy[2*ind+1]^=1;
        }
        return;
    }
    
    ll mid=(l+r)/2;
    update(segt,lazy,2*ind+1,mid+1,r,ind1,ind2);
    update(segt,lazy,2*ind,l,mid,ind1,ind2);
    
    segt[ind]=segt[2*ind]+segt[2*ind+1];
    
    return;
}

ll query(vector<ll>&segt,vector<ll>&lazy,ll ind ,ll l, ll r, ll ind1,ll ind2)
{
     if(lazy[ind]!=0)
    {
        segt[ind]=((r-l+1)-segt[ind]);
        lazy[2*ind]^=1;
        lazy[2*ind+1]^=1;
        lazy[ind]=0;
    }
    
    if(l>ind2 || r<ind1)
        return 0;

    
    if(l>=ind1 && r<=ind2)
        return segt[ind];
    
    ll mid=(l+r)/2;
    
    return query(segt,lazy,2*ind+1,mid+1,r,ind1,ind2)+query(segt,lazy,2*ind,l,mid,ind1,ind2);    
    
        
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    ll n;
    cin>>n;
    
    v=vector<ll>(n);
    vector<ll>v1(n);
        
    for(int i=0;i<n;i++)cin>>v1[i];


    for(int i=0;i<33;i++)
    {

        vector<ll>tmp2;
        for(int j=0;j<n;j++)
        {
            tmp2.push_back(v1[j]%2);
        }
        v=tmp2;
        build_tree(segt1[i],lazy1[i],1,0,n-1);
    }
    
    ll q;
    cin>>q;
    

    while(q--)
    {
        ll t,l,r,x;
        cin>>t;
        
        if(t==1)
        {
            cin>>l>>r>>x;
            
            l--;
            r--;
            
            for(int i=0;i<33;i++)
            {
                if(x%2!=0)
                {
                    x/=2;
                    continue;
                }
                x/=2;
                update(segt1[i],lazy1[i],1,0,n-1,l,r);
            }
        }
        else 
        {
            cin>>l>>r;
            l--;
            r--;
            ll ans=0;
            for(int i=0;i<33;i++)
            {
                ans+=(query(segt1[i],lazy1[i],1,0,n-1,l,r))*((ll)pow(2,i));
            }
            cout<<ans<<endl;
        }
        
    }
    
    
    return 0;
}