// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    long long kthSmallest(set<long long> s, int n, int k){
        
        set<long long>:: iterator it;
        // it = s.begin();
        priority_queue<int> maxh;
        for(it = s.begin(); it != s.end(); it++){
            maxh.push(*it);
            
            if(maxh.size()>k){
                maxh.pop();
            }
            
        }
        
        long long ans = maxh.top();
        return ans;
    }
    long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
    {
        set<long long> s;
        for(int i=0; i<n; i++){
            s.insert(a[i]);
        }
        int len = s.size();
        
         long long l ;
         
         if(k1>len){
             l = INT_MAX;
         }else{
             l = kthSmallest(s,len,k1);
         }
         
         
         kthSmallest(s,len,k1);
        
        long long r;
       if(k2>len){
             r=INT_MAX;
            
        }else{
             r = kthSmallest(s,len,k2);
        }
        
        //  cout<<l<<" "<<r<<endl;
        long long sum=0;
        if(l<r){
            for(int i=0; i<n ; i++){
                if(a[i]>l && a[i]<r){
                 sum+=a[i];
                }
            }
        
        }
        
        if(r<l){
            for(int i=0; i<n ; i++){
                if(a[i]>r && a[i]<l){
                 sum+=a[i];
                }
            }
        
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends
