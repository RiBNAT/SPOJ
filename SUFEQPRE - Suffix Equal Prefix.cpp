
//Problem Link: https://www.spoj.com/problems/SUFEQPRE/


#include<bits/stdc++.h>
using namespace std;

#define     ll              long long int
#define     Pair            pair<ll,ll>
#define     F               first
#define     S               second
#define     all(v)          v.begin(),v.end()
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     Max             1000000000000000014
#define     Min             -1000000000000000014
#define     mod             1000000007
#define     range           100007
#define     pb              push_back
#define     Vector          vector<ll>
#define     mp              make_pair
#define     PI              3.14159265358979323846 // acos(-1)


 ll pc;void PrintCase(){printf("Case %lli: ",++pc);}
// ll GCD(ll a,ll b){if(a<0) a*=-1;if(b<0) b*=-1;if(a<b)swap(a,b);if(b==1) return 1;if(!b) return a;if(!(a%b)) return b;else return GCD(b,a%b);}
// ll LCM(ll a,ll b){ll x=GCD(a,b);return (a/x)*b;}
// ll bigmod(ll n,ll p){if(p==0) return 1;if(p==1)return (n+mod)%mod;if(p%2)return (bigmod(n,p-1)*n+mod)%mod;else{ll x=bigmod(n,p/2);return (x*x+mod)%mod;}}
// ll power(ll n,ll p){if(p==0) return 1;if(p==1)return n;if(p%2)return power(n,p-1)*n;else{ll x=power(n,p/2);return x*x;}}
// ll modinverse(ll n){return bigmod(n,mod-2)%mod;}
// ll Check(ll n,ll i){return (n&(1LL<<i));}
// ll Set(ll n,ll i){return (n|(1LL<<i));}
// ll status[(ll)range/64+5];Vector primes;void sieve(){for(ll i=3;i<=sqrt(range);i+=2){if(Check(status[i/64],i%64)==0){for(ll j=i*i;j<range;j+=2*i){status[j/64]=Set(status[j/64],j%64);}}}primes.pb(2);for(ll i=3;i<range;i+=2)if(Check(status[i/64],i%64)==0)primes.pb(i);}


/************* C0DiNG START FR0M HERE *****************/


vector<ll> z_algo(string str)
{
    ll len=str.size();
    ll l=0, r=0, i, j;
    vector<ll> z(len);
    for(i=1; i<len; i++){
        if(i>r){
            l=r=i;
            while(r<len and str[r]==str[r-l])
                r++;
            z[i]=r-l;
            r--;
        }
        else{
            ll idx=i-l;
            if(i+z[idx] <= r){
                z[i]=z[idx];
            }
            else{
                l=i;
                while(r<len and str[r]==str[r-l])
                    r++;
                z[i]=r-l;
                r--;
            }
        }
    }
    return z;
}


int main()
{
    ll t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        //s=s+"#"+s;
    
        Vector z=z_algo(s);
        ll ans=0;

        for(ll i=0; i<z.size(); i++)
            if(i+z[i]==s.size()) ans++;

        PrintCase();
        cout<<ans<<endl;

    }

}

