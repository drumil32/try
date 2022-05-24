#include<bits/stdc++.h>
using namespace std;

// optimal
int main(){
    int len;
    cin>>len;
    vector< pair<int,int> > vect(len);
    for(auto &v : vect) cin>>v.first>>v.second;
    sort(vect.begin(),vect.end());
    // int ans = 0;
    vector< int > dp;
    for(int i=0 ; i<len ; i++){
        auto it = upper_bound(dp.begin(),dp.end(),vect[i].second);
        if( it==dp.end() )
            dp.push_back(vect[i].second);
        else
            *it = vect[i].second;
    }
    
    cout<<dp.size();
}

// brute force
#include<bits/stdc++.h>
using namespace std;


int main(){
    int len;
    cin>>len;
    vector< pair<int,int> > vect(len);
    for(auto &v : vect) cin>>v.first>>v.second;
    sort(vect.begin(),vect.end());
    // int ans = 0;
    vector< int > dp(len);
    for(int i=0 ; i<len ; i++){
        int mx = 0;
        for(int j=i-1 ; j>=0 ; j--){
            if( vect[i].second>=vect[j].second )
                mx = max(mx,dp[j]);
        }
        dp[i] = mx+1;
    }
    int ans = 0;
    for(auto val : dp)  ans = max(val,ans);
    cout<<ans;
}
