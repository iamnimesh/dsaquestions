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
bool isPrime(ll n)
{
      if (n <= 1)
        return false;
    for (ll i = 2; i <= sqrt(n); i++)/*prime number should not have any factor betwen 2 and its sqr root*/
        if (n % i == 0)
            return false;
 
    return true;
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

/* o-1 knapsack
input-> 
3 8 
3 30
4 50
5 60
*/
ll wt[105],val[105];

ll dp[105][100005];
ll func(ll ind,ll wt_left){

    if(wt_left==0){
        return 0;
    }
    if(ind<0)//items khtm ho gyi hai but space hai
        return 0;
    if(dp[ind][wt_left]!=-1){
        return dp[ind][wt_left];
    }
    //don't choose item at ind
    ll ans=func(ind-1,wt_left);
    //choose item ind
    if(wt_left-wt[ind]>=0)
   ans= max(ans,func(ind-1,wt_left-wt[ind])+val[ind]);

    return dp[ind][wt_left]= ans;
}
/*the time complexity of this logic is basicaly the number of times recursion calls which is eqaul to the state of dp
which is O(n*wt)==105*100005==1e7 */
void solve(){
    memset(dp,-1,sizeof(dp));
    ll n,w;
    cin>>n>>w;
    loop(i,0,n-1){
        cin>>wt[i]>>val[i];
    }
    cout<<func(n-1,w);
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
    t=1;
   //cin>>t;
    
    while(t--){
      solve();
    }

  return 0;
}
