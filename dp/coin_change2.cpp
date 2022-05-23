#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define endl "\n" //not to be use in iteractive problems
#define MOD 1000000007
#define loop(i,a,b)   for(ll i=a;i<=b;i++)
#define looprev(i,a,b)   for(ll i=a;i>=b;i--)
#define pb(a)       push_back(a)
#define pf(a)       push_front(a)/*used in deque*/
#define ff first
#define ss second
#define PI 3.1415926536
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
/******************************************functions**********************************/
ll add(ll x,ll y){ ll res=x+y; return(res>=MOD? res-MOD: res);}
ll sub(ll x,ll y){ ll res=x-y; return(res<0? res+MOD : res);}
ll mul(ll x,ll y){ ll res=x*y; return (res>=MOD ? res%MOD : res);}
//ll lcm(ll x,ll y){ ll res=(x*y)/__gcd(x,y); return res;}
ll power(ll x,ll y){ ll res=1;x%MOD;while(y){ if(y&1) res=mul(res,x);y>>=1;x=mul(x,x);} return res;}
ll mod_inv(ll x){
   return power(x,MOD-2);
}
vll getUniqueprimefactors(ll n){
   vll primefactors;
   primefactors.clear();
   for(ll i=2;i*i<=n;i++){
      if(n%i==0){
         primefactors.push_back(i);
         while(n%i==0)
            n/=i;
      }
   }

   if(n!=1)/*for numbers which have there prime factors more than sqrt(n) then n will not become 1 at this postion 
   and the value of n at this place is that factor */
   primefactors.push_back(n);

   return primefactors;
}
ll computexor(ll n){ 
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
  // If n%4 gives remainder 3
  return 0;
}
ll power_(ll x,ll y){
   ll res=1;
   while(y){
      if(y&1){
         res *= x;
         y--;
      }
      x *= x;
      y>>=1;
   } 
   return res;
}
const ll inf=1e18;
/************************************Relevant code*********************************/
ll dp[10001][10001];


/*func(n,amount)->agr nth index tk ke coins ko use kre and amount rupee bnana ho to answer kya hoga tb answer hoga=func(n,amount)*/

ll func1(ll ind,ll amount, vector<ll>& coins){//will give us the all ways that combine to form amount by using different denominations

   if(amount==0)return 1;  //if amount is 0 then 1 way always
   if(ind<0)return 0;//

 if(dp[ind][amount]!=-1)
   return dp[ind][amount];

   ll ways=0;


   for(ll coin_amount=0;coin_amount<=amount;coin_amount+=coins[ind]){//agr amount-coin bna liya then coin bhi bna hi lenge
     
     ways += func1(ind-1,amount-coin_amount,coins);
   }
   return dp[ind][amount] = ways;
}

ll coinChange(vector<ll>& coins,ll amount) {
      memset(dp,-1,sizeof(dp));      
       ll ans=func1(coins.size()-1,amount,coins);
         return ans ;
}


int main(){
   fastio();
/*
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
*/
ll t;
//cin>>t;
t=1;
   while(t--){
      vll coins={2};
      cout<<coinChange(coins,2);
     }
  return 0;
}