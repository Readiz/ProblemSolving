#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("E_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for (ll i=m;i<=n;++i)
#define reb(i,m,n) for (ll i=m;i>=n;--i)
#define rv(i,vt) for (auto i:vt)
#define ii pair<ll,ll>
#define vi vector<int>
#define F first
#define S second
#define pb push_back
const ll N=1e6+5,mod=1e9+7;
ll n,a,b,c,d;
vector<ll> vt,vt2;
ll check (ll n, ll l, ll r){
    ll mi=(l+n-1)/n,ma=r/n;
    if (mi>ma) return -1;
    return mi*n;
}
void solve()
{
    cin>>a>>b>>c>>d;
    vt.clear();
    vt2.clear();
    rep(i,1,sqrt(a)) if (a%i==0){
        vt.pb(i);
        if (a/i!=i) vt.pb(a/i);
    }
    rep(i,1,sqrt(b)) if (b%i==0){
        vt2.pb(i);
        if (b/i!=i) vt2.pb(b/i);
    }
    ll g=a*b;
    rv(i,vt)
    rv(j,vt2){
        ll g1=i*j;
        ll g2=g/g1;
        if (check(g1,a+1,c)!=-1 && check(g2,b+1,d)!=-1){
            cout<<check(g1,a+1,c)<<" "<<check(g2,b+1,d)<<endl;
            return;
        }
        if (check(g1,b+1,d)!=-1 && check(g2,a+1,c)!=-1){
            cout<<check(g2,a+1,c)<<" "<<check(g1,b+1,d)<<endl;
            return;
        }
    }
    cout<<-1<<" "<<-1<<endl;
}
MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
