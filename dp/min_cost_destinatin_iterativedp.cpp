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
/*this is the iterative solution for min cost destination 
INPUT->
3 3
4 3 2
1 8 3
1 1 8 

output->
14
*/

ll min_cost2(vector<vector<ll>>& input, ll m,ll n){
ll dp[m][n];
memset(dp,0,sizeof(dp));
dp[m-1][n-1]=input[m-1][n-1];
looprev(i,m-2,0)
dp[i][n-1] = dp[i+1][n-1]+input[i][n-1];

looprev(j,n-2,0)
dp[m-1][j]=dp[m-1][j+1]+input[m-1][j];

looprev(i,m-2,0){
   looprev(j,n-2,0){
      dp[i][j]=input[i][j]+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
   }
}
return dp[0][0];/*this stores the minimum cost to go from (0,0) to (m,n)*/
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
      ll m,n;cin>>m>>n;

vector<vll> input(m,vll(n,0));
       loop(i,0,m-1){
         loop(j,0,n-1){
            cin>>input[i][j];
         }
       }
cout<<min_cost2(input,3,3)<<endl;
    }

  return 0;
}