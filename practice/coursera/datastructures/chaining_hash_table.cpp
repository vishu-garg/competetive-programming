#include<bits/stdc++.h>
using namespace std;
#define ll long long

class chaining
{
private:
    string s;
    vector<vector<string> >v;
    int x=263;
    ll p=1e9+7;
    int m;
public:
    chaining(int buck_size)
    {
        m=buck_size;
        v=vector<vector<string> >(m);
    }
    int polyhash(string s)
    {
        ll result=0;
        for(int i=s.length();i>=0;i--)
        {
            result=((result*x)+((ll)(s[i])))%p;
        }
        result%=m;
        return result;
    }
    void add(string s)
    {
        int ind=polyhash(s);
        for(int i=0;i<(int)v[ind].size();i++)
        {
            if(v[ind][i]==s)
            return;
        }
        v[ind].push_back(s);
    }
    void check(int ind)
    {
        if(v[ind].size()!=0)
        {
            for(int i=(int)v[ind].size()-1;i>=0;i--)
            cout<<v[ind][i]<<" ";
        }
        cout<<endl;
    }
    void del(string s)
    {
        int ind=polyhash(s);
        for(int i=0;i<(int)v[ind].size();i++)
        {
            if(v[ind][i]==s)
            {
                v[ind].erase(v[ind].begin()+i);
            }
        }
    }
    void find(string s)
    {
        int ind=polyhash(s);
        for(int i=0;i<(int)v[ind].size();i++)
        {
            if(v[ind][i]==s)
            {
                cout<<"yes"<<endl;
                return;
            }
        }
        cout<<"no"<<endl;
    }
};

int main()
{
    int m;
    cin>>m;
    chaining obj(m);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(s=="check")
        {
            ll ind;
            cin>>ind;
            obj.check(ind);
        }
        else 
        {
            string s2;
            cin>>s2;
            if(s=="add")obj.add(s2);
            if(s=="del")obj.del(s2);
            if(s=="find")obj.find(s2);
        }
    }
}

