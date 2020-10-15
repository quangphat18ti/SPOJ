#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define maxn 505
#define endl "\n"
#define LT "mcards"
#define fi first
#define se second
#define mp make_pair
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;


int i , j , n , m , k;
int c;

struct ii
{
    int loai , gt , vt;
};
ii a[maxn];

vii ds[5];

int st[maxn] , dd[maxn];
int ans = 1e9;
int g[maxn] , mx = 0 , vc = 1e9 + 5;

void nhap()
{
    cin >> c >> m;
    n = c * m;
    For( i , 1 , n ) cin >> a[i].loai >> a[i].gt , a[i].vt = i;
    For( i , 1 , n )
    {
        ds[a[i].loai].pb( mp( a[i].gt , a[i].vt ) );
    }

    For( i , 1 , c ) sort( ds[i].begin() , ds[i].end() );
}

int chat( int l , int r , int s )
{
    while( l <= r )
    {
        int mid = (l + r) >> 1;
        if( g[mid] < s ) l = mid + 1;
        else r = mid - 1;
    }
    return l - 1;
}

int LIS ( vi a )
{
    vi f ( n + 1 , 0 );
    mx = 0 , g[0] = -vc;
    For( i , 1 , n )
    {
        int tam = chat( 0 , mx , a[i] );
        f[i] = tam + 1;
        if ( mx < f[i] ) mx = f[i] , g[mx] = a[i];
        else g[f[i]] = min ( g[f[i]] , a[i] );
    }

    return mx;
}

int solve( int st[] , int k )
{
    vi f; f.pb(0);
    For( i , 1 , k )
    {
        int nhan = st[i];
        for( pii tam : ds[nhan] ) f.pb( tam.se );
    }

    return LIS(f);
}

void vet( int tam )
{
    if( tam == c + 1 )
    {
        ans = min ( ans , n - solve( st , c ) );
        return;
    }

    For( i , 1 , c )
    {
        if( dd[i] ) continue;
        st[tam] = i;
        dd[i] = 1;
        vet(tam + 1);
        dd[i] = 0;
    }
}

void xuli()
{
    vet(1);
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
