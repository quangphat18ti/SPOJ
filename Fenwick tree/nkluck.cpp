/// Cho 1 mảng có n phần tử. Tìm số lượng đoạn con có trung vị là x
/// Tìm số lượng dãy có trung vị >= x
/// Tìm số lượng dãy có trung vị >= x + 1
/// xong lấy 1 - 2.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define For( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second
#define mp make_pair
#define LT "nkluck"
#define maxn 500005

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn];
int Fen[2][maxn * 2];
int them;

void nhap()
{
    cin >> n >> k;
    For( i , 1 , n ) cin >> a[i];
    them = n + 1;
}

void update( int i )
{
    Fen[0][i]++;
    while( i <= n + them )
    {
        Fen[1][i]++;
        i += i & -i;
    }
}

int get( int i )
{
    int ans = 0;
    while( i > 0 )
    {
        ans += Fen[1][i];
        i -= i & -i;
    }
    return ans;
}

ll Count( int gt , int a[] , int n )
{
    For( i , -n , n ) Fen[0][i + them] = Fen[1][i + them] = 0;
    vi f( n + 1 , 0 );
    For( i , 1 , n )
    {
        f[i] = f[i - 1];
        if( a[i] >= gt ) f[i]++;
        else f[i]--;
    }

    ll ans = 0;
    update( 0 + them );
    For( i , 1 , n )
    {
        int tam = f[i] + them;
        ans += get(tam);
        update( tam );
    }

    return ans;

}

void xuli()
{
    ll tam = Count( k , a , n );
    ll tam1 = Count( k + 1 , a , n );
    ll tong = 1ll * n * (n + 1) / 2;
    db ans = 1.0 * ( tam - tam1 ) / tong;
    printf("%0.7f",ans);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}

