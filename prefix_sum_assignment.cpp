// Q1) Leetcode 724 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>nums={1,7,3,6,5,6};
    bool flag=false;
    int n=nums.size(),i,left,right;
    vector<int>pre(n);
    vector<int>suf(n);
    for(i=0;i<n;i++)
    {
        if(i==0) pre[i]=nums[i];
        else      pre[i]=nums[i]+pre[i-1];
    } 
    for(i=n-1;i>=0;i--){
        if(i==n-1) suf[i]=nums[i];
        else       suf[i]=nums[i]+suf[i+1];
    }
    for(i=0;i<n;i++)
    {
        if(i==0) left=0,right=suf[i+1];
        else if(i==n) left=pre[i-1],right=0;
        else          left=pre[i-1],right=suf[i+1];
        if(left==right){
            flag=true;
            break;
        }
    }
    if(flag==true) cout<<i;
    else           cout<<-1;
}



// Q2) Leetcode 2640
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    vector<int>v={2,3,7,5,10};
    int i, n=v.size(),k=INT_MIN;
    vector<int>ans(n);
    for(i=0;i<n;i++)
    {
        if(v[i]>k) k=v[i];
        ans[i]=v[i]+k;
    }
    for(i=1;i<n;i++)
    ans[i]+=ans[i-1];
    for(int ele:ans) cout<<ele<<" ";
}



// Q3) Leetcode 1109
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>>bookings = {{1,2,10},{2,3,20},{2,5,25}};
    int m=bookings.size(),i, n = 5;
    vector<int>ans(n);
    for(i=0;i<m;i++)
    {
        ans[bookings[i][0]-1]+=bookings[i][2];
        if(bookings[i][1]!=n) ans[bookings[i][1]]-=bookings[i][2];        
    }
    //prfix sum
    for(i=1;i<n;i++){
        ans[i]+=ans[i-1];
    }
    //print
    for(int ele: ans)
    cout<<ele<< " ";
}
