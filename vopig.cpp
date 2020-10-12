#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
#define pb push_back
#define db double
#define LT "vopig"
#define fi first
#define se second
#define mp make_pair
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )

typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , k;
ll a[maxn];
ll n , m;

ll get ( int k ) { return 1ll << k; }

void nhap()
{
    cin >> n >> m;
}

void solve3()
{
    For( i , 1 , n ) cin >> a[i] , a[i] &= m;
    sort( a + 1 , a + n + 1 );

    int f[maxn];

    f[0] = 0;
    For( i , 1 , n )
    {
        f[i] = 1;
        For( j , 1 , i - 1 )
        {
            if( (a[i] | a[j]) == a[i] )
            {
                f[i] = max( f[j] + 1 , f[i] );
            }
        }
    }

    cout << *max_element( f + 1 , f + n + 1 ) << endl;
}

void solve4()
{
    For( i , 1 , n ) cin >> a[i] , a[i] &= m;
//    sort( a + 1 , a + n + 1 );
//
//    int mx = 0;
//    int g[maxn] , f[maxn];
//
//    For( i , 1 , n )
//    {
//        int tam = Find( a[i] );
//        f[i] = tam + 1;
//        if( mx < f[i] ) mx = f[i] , g[mx] = a[i];
//        else g[f[i]] = min ( g[f[i]] , a[i] );
//    }

    int st[maxn] , top = 0;
    while( m > 0 )
    {
        st[++top] = m % 2;
        m /= 2;
    }

    FOr( i , top , 1 ) cout << st[i] << ' '; cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    nhap();
//    if( n <= 5000 ) solve3();
//    else if( n <= 100000 ) solve4();
    solve4();
}
