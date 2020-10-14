#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define maxn 100005
#define LT "qbdivseq"

typedef vector<int> vi;

int i , j , n , m , k;
int a[maxn];
int g[maxn] , vc = 1e9 + 5;

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i] , a[i] = -a[i];
}

int chat ( int l , int r , int s )
{
    while( l <= r )
    {
        int mid = (l + r) >> 1;
        if( s > g[mid] ) l = mid + 1;
        else r = mid - 1;
    }

    return l - 1;
}

vi LIS( int a[] , int n )
{
    vi f( n + 1 , 0 );

    int mx = 0; g[0] = -vc;
    For( i , 1 , n )
    {
        int tam = chat( 0 , mx , a[i] );
        f[i] = tam + 1;
        if( f[i] > mx ) mx = f[i] , g[mx] = a[i];
        else g[f[i]] = min( g[f[i]] , a[i] );
    }

    return f;
}

void xuli()
{
    vi u = LIS( a , n );
    int ans = 0;
    For( i , 1 , n ) ans = max ( ans , u[i] );
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
