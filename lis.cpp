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
#define LT "liq"

int i , j , n , m , k;
ll a[maxn];
ll f[maxn] , g[maxn] , mx = 0;
ll vc = 1e18;

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i];
}

int chat( int l , int r , ll s )
{
    while( l <= r )
    {
        int mid = (l + r) >> 1;
        if( g[mid] < s ) l = mid + 1;
        else r = mid - 1;
    }
    return l - 1;
}

void xuli()
{
    mx = 0;
    g[0] = -vc;
    For( i , 1 , n )
    {
        int tam = chat( 0 , mx , a[i] );
        f[i] = tam + 1;
        if( f[i] > mx ) mx = f[i] , g[mx] = a[i];
        else g[f[i]] = min( g[f[i]] , a[i] );
    }

    cout << *max_element( f + 1 , f + n + 1 ) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
