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
/*
f(n): ways of construct length of n, x!=1
g(n): ways of construct length of n, x==1
then, we have:
f(n) = g(n-1) + (k-2) * f(n-1)
g(n) = (k-1) * f(n-1)

explanation->
First realize that 1...1 is different from 1...(2-k), but 1...2, 1...3, ..., 1...k are all equvilant. So there are two functions f and g.

Second, 1...(n-2 dots)...x, x==1 has the pattern: 1...(n-3 dots)...y1, where y!=1. There are (k-1) such cases, i.e. 1...(n-3 dots)...y with y loops over 2 to k. So the relation: g(n) = (k-1) * f(n-1)

Third, 1...(n-2 dots)...x, x!=1 has two possible patterns: 1...(n-3 dots)...1x and 1...(n-3 dots)...yx, y!=x or 1. The first pattern gives g(n-1), the second gives (k-2)*f(n-1), since y can loop over 2 to k but not x.



*/
ll countArray(ll n,ll k,ll x){
   vll f(n+1,0);
   vll g(n+1,0);
   f[2]=1;
   g[2]=0;

   loop(i,3,n){
      f[i]=g[i-1]+(k-2)*f[i-1];
      g[i]=(k-1)*f[i-1];
      f[i]%=MOD;
      g[i]%=MOD;
   }
   return x==1?g[n]:f[n];
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
      ll n,k,x;
     
      cin>>n>>k>>x;

      ll ans=countArray(n,k,x);
      cout<<ans<<endl;
    }
  return 0;
}
/*
*/