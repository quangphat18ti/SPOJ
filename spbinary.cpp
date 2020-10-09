#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 605
#define EL cout<<endl;
#define pb push_back
#define LT "spbinay"
#define fi first
#define se second
#define mp make_pair
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
typedef vector<int> vi;
typedef pair<int,int> pii;

int i , j , n , m , k;
vi f[maxn][2] , lt[maxn];
int mod = 1e9;

void nhap()
{
    cin >> n >> k;
}

void Push ( vi &a , int s )
{
    a.pb(s);
}

vi operator + ( vi a , vi b )
{
    vi ans;
    int n = a.size() - 1 , m = b.size() - 1;

    int carry = 0;
    For( i , 0 , max( n , m ) )
    {
        if( i <= n ) carry += a[i];
        if( i <= m ) carry += b[i];
        ans.pb( carry % mod );
        carry /= mod;
    }

    if( carry ) ans.pb( carry );
    return ans;
}

vi operator - ( vi a , vi b )
{
    vi ans;
    int n = a.size() - 1 , m = b.size() - 1;

    int carry = 0;
    For( i , 0 , max( n , m ) )
    {
        if( i <= n ) carry += a[i];
        if( i <= m ) carry -= b[i];
        if( carry < 0 ) carry += mod , a[i+1]--;
        ans.pb( carry % mod );
        carry /= mod;
    }

    return ans;
}

vi operator * ( vi a , vi b )
{
    int n = a.size() - 1 , m = b.size() - 1;

    vi ans ( n + m + 2 , 0 );

    For( i , 0 ,  n )
    {
        ll carry = 0;
        For( j , 0 , m )
        {
            carry += ans[i + j] + 1ll * a[i] * b[j];
            ans[i + j] = carry % mod;
            carry /= mod;
        }

        ans[ i + m + 1 ] = carry;
    }

    while( ans.size() && ans.back() == 0 ) ans.pop_back();
    return ans;
}

void xuat( vi a )
{
    printf("%d",a.back());
    FOr( i , a.size() - 2 , 0 ) printf("%0.9d" , a[i]);
    printf( "\n" );
}

void process()
{
    Push( lt[0] , 1 );
    For( i , 1 , k )
    {
        vi b; Push( b , 2 );
        lt[i] = lt[i-1] * b ;
    }
}

void xuli()
{
    process();

    Push ( f[0][0] , 1 );
    Push ( f[0][1] , 1 );

    For( i , 1 , n )
    {
        For( j , 0 , 1 )
        {
            if( i <= k ) f[i][j] = lt[i - 1];
            else
            {
                int tam = 1 - j;
                f[i][j] = (f[i-1][0] + f[i-1][1]) - f[i-k-1][tam];
            }
        }
    }

    xuat( f[n][0] + f[n][1] );
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
