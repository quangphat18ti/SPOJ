#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 10005
#define pb push_back
#define endl "\n"
#define LT "nttree"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m , k;
vector<pii> ke[maxn];
int f[maxn];
ll ans = 0;

void nhap()
{
    cin >> n;
    For ( i , 1 , n-1 )
    {
        int u , v , w; cin >> u >> v >> w;
        u++ , v++;
        ke[u].pb( mp( v , w ) );
        ke[v].pb( mp( u , w ) );
    }
}

void dfs( int u , int p )
{
    f[u] = 1;
    for( pii v : ke[u] )
    {
        if( v.fi == p ) continue;
        dfs( v.fi , u );
        f[u] += f[v.fi];
        ans = ans + 1ll * f[v.fi] * ( n - f[v.fi] ) * v.se;
    }
}

void xuli()
{
    dfs( 1 , - 1 );
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}

