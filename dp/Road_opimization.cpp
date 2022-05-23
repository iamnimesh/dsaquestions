/*Road optimization->  https://codeforces.com/problemset/problem/1625/C */


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
ll dp[502][502];
ll val[1000],dist[501];
ll n,l;
ll func(ll pos,ll k){/*this function will give me the minimum cost to reaCH last CITY(index n) from index pos and we have to remove k boards between last city and pos*/
   if(pos>=n){//current index equal to destination index 
      return 0;
   }
if(dp[pos][k]!=-1)return dp[pos][k];
   ll ans=1e9;
  


  /*so basically i can remove any number of boards x where x from 0 to k in the just next child*/
   loop(x,0,k){

   if(pos+x>=n) {/*n-> destinaiton index, dist[n]-> destination cordinate .if index of xth board is index of destination then not allowed and break from there*/
       break;
   }

   /*new cordinate after remvoing x borads from index pos goes to index pos+x+1 and new cordinatre will be dist[pos+1+x]*/ 

   /*if i remove x boards from right here(indx pos) then cost to reach next board will be cost=(new cordinate-old cordniate)*sign */
      ll cost=(dist[pos+x+1]-dist[pos])*val[pos];


/*min cost to reach last city from pos+x+1 and having (k-x) boards remaining to remove i-> func(pos+x+1,k-x))*/
ll newcost=(cost+func(pos+x+1,k-x));
      ans=min(ans,newcost);
   }
   return dp[pos][k]=ans;
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
      memset(dp,-1,sizeof(dp));
    ll k;
      cin>>n>>l>>k;

      loop(i,0,n-1)cin>>dist[i];
      loop(i,0,n-1)cin>>val[i];      
      dist[n]=l;/*dist[n] will be cordinate of destination or index of destination is n*/
      cout<<func(0,k)<<endl;/*this function will give me the minimum cost to reaCH last CITY(index n) from index 0 and have k boards to remove*/
 }

  return 0;
}

