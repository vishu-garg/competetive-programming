#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>merge(int l , int r, int mid, vector<int>&v1, vector<int>&v2 , vector<int>&a)
{
    vector<int>sorted;
    vector<int>result(v1.size()+v2.size(),0);
    vector<pair<int,int> >tmp;
    int i=0,j=0;
    while(i<v1.size() && j<v2.size())
    {
        if(a[l+i]>a[mid+1+j])
        {
            sorted.push_back(a[mid+1+j]);
            tmp.push_back(make_pair(j,2));
            j++;
            result[i]+=1;
        }
        else 
        {
            sorted.push_back(a[l+i]);
            tmp.push_back(make_pair(i,1));
            i++;
        }
    }
    while(i<v1.size())
    {
        sorted.push_back(a[l+i]);
        tmp.push_back(make_pair(i,1));
        i++;
    }
    while(j<v2.size())
    {
        sorted.push_back(a[mid+1+j]);
        tmp.push_back(make_pair(j,2));
        j++;
    }

    // for(auto it:sorted)
    // cout<<it<<" ,";
    // cout<<endl;

    // for(auto it:tmp)
    // cout<<it.first<<" "<<it.second<<endl;

    for(int i=1;i<v1.size();i++)
    result[i]+=result[i-1];
    for(int i=0;i<v1.size();i++)
    result[i]+=v1[i];
    for(int j=v1.size();j<v1.size()+v2.size();j++)
    result[j]+=v2[j-v1.size()];
    vector<int>sorted_result;
    i=0;j=0;
    int k=0;
    while(k<tmp.size())
    {
        if(tmp[k].second==2)
        {
            sorted_result.push_back(result[v1.size()+j]);
            j++;
            k++;
        }
        else if(tmp[k].second==1)
        {
            sorted_result.push_back(result[i]);
            i++;
            k++;
        }
    }

    for(int i=l;i<=r;i++)
    {
        a[i]=sorted[i-l];
        // cout<<a[i]<<", "<<result[i]<<endl;
    }
    // cout<<endl;
    return sorted_result;
}

vector<int>func(vector<int>&a , int l, int r)
{
    if(r>l)
    {
        int mid=(l+r)/2;
        vector<int>v1=func(a,l,mid);
        vector<int>v2=func(a,mid+1,r);
        return merge(l,r,mid,v1,v2,a);
    }
    else 
    {
        vector<int>ans;
        ans.push_back(0);
        return ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>a(n);
    vector<pair<int,int>>tmp;
    
    for(int i=0;i<n;i++)
    {cin>>a[i];tmp.push_back(make_pair(a[i],i));}
    sort(tmp.begin(),tmp.end());

    vector<int>ans=func(a,0,n-1);
    vector<int>real_ans(n);
    for(int i=0;i<ans.size();i++)
    {
        real_ans[tmp[i].second]=ans[i];
    }
    for(auto it:real_ans)
    cout<<it<<" ";
}