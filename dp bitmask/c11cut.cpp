/// Cho 1 bảng 4 * 4. Tìm các cắt bảng này thành cách hcn 1 * x.
/// Tìm cách cắt sao cho tổng các số trên các hcn này có tổng lớn nhất,

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
#define LT "c11cut"
#define maxn 20

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn][maxn];
int f[maxn][maxn];
int kt[maxn][maxn];
int ans = 0;

void nhap()
{
    cin >> n >> m;
    For( i , 1 , n ) For( j , 1 , m ) cin >> a[i][j];
}

int get( int k ) { return 1 << k; }
bool get_bit( int s , int k ) { return ( s >> k ) & 1; }

void xet()
{
    For( i , 1 , n ) For( j , 1 , m ) kt[i][j] = 0;

    int res = 0;
    For( i , 1 , n )
    {
        For( j , 1 , m )
        {
            if( kt[i][j] ) continue;
            if( f[i][j] == 1 )
            {
                int tam = 0 , jres = j;
                while( jres <= m && f[i][jres] == 1 ) tam = tam * 10 + a[i][jres] , kt[i][jres] = 1 , jres++;
                res += tam;
            }
            else
            {
                int tam = 0 , ires = i;
                while( ires <= n && f[ires][j] == 0 ) tam = tam * 10 + a[ires][j] , kt[ires][j] = 1 , ires++;
                res += tam;
            }
        }
    }

    ans = max ( ans , res );
}

void vet( int tam )
{
    if( tam > n )
    {
        xet();
        return;
    }
    For( i , 0 , get(m) - 1 )
    {
        For( j , 1 , m ) f[tam][j] = get_bit( i , j - 1 );
        vet(tam + 1);
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
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}

