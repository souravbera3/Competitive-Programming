#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    ll t = 1;
    cin>>t;

    while (t--)
    {
        ll n,m,d;
        cin>>n>>m>>d;
        vector<string > vec(n);
        for(ll i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        vvl gridl(n,vl(m,0));
        vvl gridr(n,vl(m,0));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(vec[i][j]=='*')
                {
                    if(i!=0&&j!=0)
                    {
                        gridl[i][j]=1+gridl[i-1][j-1];
                    }
                    else{
                        gridl[i][j]=1;
                    }
                    if(i!=0&&j!=m-1)
                    {
                        gridr[i][j]=1+gridr[i-1][j+1];
                    }
                    else{
                        gridr[i][j]=1;
                    }
                }
                else{
                    gridl[i][j]=0;
                    gridr[i][j]=0;
                }
            }
        }
        vvl grid(n,vl(m,0));
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(vec[i][j]=='*')
                {
                    grid[i][j]=min(gridl[i][j],gridr[i][j]);
                }
            }
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(grid[i][j]<=d)
                {
                    grid[i][j]=0;
                }
            }
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ll temp=grid[i][j];
                for(ll k=0;k<temp;k++)
                {
                    grid[i-k][j+k]=1;
                    grid[i-k][j-k]=1;
                }
            }
        }
        ll can=1;
        for(ll i=0;i<n;i++)
        {
            
            for(ll j=0;j<m;j++)
            {
                if((grid[i][j]==1&&vec[i][j]=='*')||(grid[i][j]==0&&vec[i][j]=='.'))
                {
                    ;
                }
                else{
                    can=0;
                }
            }
        }
        if(can)
        {
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        
    }
    return 0;
}