/// Vì đây có 2 dữ liệu thống kê nên ta sẽ sort theo 1 đầu để triệt tiêu 1 dữ
/// liệu. TÌm dãy số lượng thằng không thể nằm chung 1 nhóm được nhiều nhất.
/// Lưu ý : Các số có a[i].fi = nhau thì sẽ sort lại đầu b theo giảm dần.



#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define db double
#define LT "mdolls"
#define endl "\n"
#define maxn 20005
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define fi first
#define se second
#define mp make_pair

typedef pair<int,int> pii;

int i , j , n , m , k;
pii a[maxn];

int f[maxn];
int g[maxn] , mx = 0 , vc = 1e9 + 5;

bool ss ( pii a , pii b )
{
    return a.fi < b.fi || ( a.fi == b.fi && a.se > b.se );
}

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i].fi >> a[i].se;
    sort( a + 1 , a + n + 1 , ss );
}

int chat( int l , int r , int gt )
{
    while( l <= r )
    {
        int mid = (l + r) >> 1;
        if( g[mid] >= gt ) l = mid + 1;
        else r = mid - 1;
    }

    return l - 1;
}

void xuli()
{
    mx = 0 , g[0] = vc;
    For( i , 1 , n )
    {
        int gt = a[i].se;
        int tam = chat( 0 , mx , gt );
        f[i] = tam + 1;
        if( mx < f[i] ) mx = f[i] , g[mx] = a[i].se;
        else g[f[i]] = max( g[f[i]] , a[i].se );
    }

    cout << *max_element( f + 1 , f + n + 1 ) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);

    int t; cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}
