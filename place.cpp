#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define maxn 500005
#define pb push_back
#define endl "\n"
#define LT "place"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m , k;
int q;
vi ke[maxn];
ll gt[maxn] , IT[maxn*4];
int num[maxn] , fi[maxn] , cnt = 0;

void nhap()
{
    cin >> n >> q >> gt[1];
    For( v , 2 , n )
    {
        int u; cin >> gt[v] >> u;
        ke[u].pb(v);
    }
}

void dfs( int u , int p )
{
    num[u] = ++cnt;
    for( int v : ke[u] )
    {
        if( v == p ) continue;
        dfs( v , u );
    }
    fi[u] = cnt;
}

void pushid( int id )
{
    IT[id*2] += IT[id];
    IT[id*2+1] += IT[id];
    IT[id] = 0;
}

void update( int id , int l , int r , int u , int v , int gt )
{
    if( l > v || r < u ) return;
    if( l >= u && r <= v )
    {
        IT[id] += gt;
        return;
    }

    pushid(id);
    int mid = (l+r) >> 1;

    update( id*2 , l , mid , u , v , gt );
    update( id*2+1 , mid+1 , r , u , v , gt );
}

ll get( int id , int l , int r , int vt )
{
    if( l > vt || r < vt ) return 0;
    if( l == r ) return IT[id];
    pushid(id);
    int mid = (l+r) >> 1;
    return get( id*2 , l , mid , vt ) + get( id*2+1 , mid+1 , r , vt );
}

void solve1()
{
    int u , X; cin >> u >> X;
    int l = num[u] , r = fi[u];
    update( 1 , 1 , n , l+1 , r , X );
}

void solve2()
{
    int u; cin >> u;
    cout << get( 1 , 1 , n , num[u] ) + gt[u] << endl;
}

void xuli()
{
    dfs( 1 , 1 );
    while ( q-- )
    {
        char loai; cin >> loai;
        if( loai == 'p' ) solve1();
        else solve2();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
