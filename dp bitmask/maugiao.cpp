/// Cho 1 bảng n * n. TÌm n ô sao cho mỗi hàng chỉ có 1 ô. Mỗi cột chỉ có 1 ô.
/// Tổng của n ô này là lớn nhất

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
#define LT "maugiao"
#define maxn 25

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn][maxn];
ll f[1100000];
ll g[1100000];

int get( int k ) { return 1 << k; }
bool get_bit( int s , int k ) { return ( s >> k ) & 1; }

void nhap()
{
    cin >> n;
    For( i , 1 , n ) For( j , 1 , n ) cin >> a[i][j];
}

void xuli()
{
    f[0] = 0; g[0] = 1;
    For( i , 1 , get(n) - 1 )
    {
        f[i] = 0; g[i] = 0;

        int dem = 0;
        For( j , 1 , n ) if( get_bit( i , j - 1 ) ) dem++;

        For( j , 1 , n )
        {
            if( get_bit( i , j - 1 ) )
            {
                int bit_pre = i ^ get( j - 1 );
                if( f[i] < f[bit_pre] + a[dem][j] )
                {
                    f[i] = f[bit_pre] + a[dem][j];
                    g[i] = g[bit_pre];
                }
                else if( f[i] == f[bit_pre] + a[dem][j] ) g[i] += g[bit_pre];
            }
        }
    }

    cout << f[get(n) - 1] << ' ' << g[get(n) - 1] << endl;
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

