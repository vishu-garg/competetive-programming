vector<int>Solution::searchRange(const vector<int> &A, int B){
    int sz=A.size();
    vector<int> ans(2);
    if(A[0]>B || A[sz-1]<B)
    {
        ans[0]=-1;
        ans[1]=-1;
        return ans;
    }

    int lo=0,hi=sz-1;
    while(lo<=hi)
    {
        int mid=(hi+lo)/2;
        if(A[mid]>=B)
        hi=mid-1;
        else 
        lo=mid+1;
    }
    if(A[lo]!=B)
    {
        ans[0]=-1;
        ans[1]=-1;
        return ans;
    }
    int lb=lo;
    lo=0,hi=sz-1;
    while(lo<=hi)
    {
        int mid=(hi+lo)/2;
        if(A[mid]<=B)
        lo=mid+1;
        else 
        hi=mid-1;
    }
    int ub=hi;
    ans[0]=lb;
    ans[1]=ub;
    return ans;
}