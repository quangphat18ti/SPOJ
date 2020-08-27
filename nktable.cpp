#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define maxn 505
#define pb push_back
#define endl "\n"
#define LT "nktable"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m , k;
int kt[maxn][maxn];
int di[5] = { 0 , 0 , 1 , 0 };
char a[maxn][maxn];
string f[maxn][maxn];
vector <pii> ke[maxn * maxn];
int g[maxn][maxn];

struct ii
{
    int u , v;
    string s;
};
struct ss
{
    bool operator () ( ii a, ii b )
    {
        return (a.s.size() > b.s.size()) || ( a.s.size() == b.s.size() && a.s < b.s );
    }
};
priority_queue < ii , vector<ii> , ss > heapmax;

bool check( int x , int y )
{
    return ( x >= 1 && x <= n && y >= 1 && y <= m );
}

int chuyen( int u , int v )
{
    return ( u - 1 ) * m + v;
}

void process()
{
    g[n+1][m] = 1;
    FOr( i , n , 1 )
    {
        FOr( j , m , 1 )
        {
            if( a[i][j] == '2' ) g[i][j] = 0;
            else g[i][j] = max( g[i+1][j] , g[i][j+1] );
        }
    }
}

bool ss( pii A , pii B )
{
    return a[ A.fi ][ A.se ] > a[ B.fi ][ B.se ];
}

void nhap()
{
    cin >> n >> m ;
    For( i , 1 , n ) For( j , 1 , m ) cin >> a[i][j];
    process();

    For( i , 1 , n ) For( j , 1 , m )
    {
        int tam = chuyen( i , j );
        For( k , 1 , 2 )
        {
            int x = i + di[k] , y = j + di[k+1];
            if( check( x , y ) && a[x][y] != '2' && g[x][y] )
                ke[tam].pb( mp( x , y ) );
        }

        sort( ke[tam].begin() , ke[tam].end() );
    }
}

void loang( int u , int v )
{
    kt[u][v] = 1;
    f[u][v] = a[u][v];
    queue <pii> st; st.push( mp(u , v) );
    while( st.size() )
    {
        int sz = st.size();
        while( sz-- )
        {
            int u = st.front().fi , v = st.front().se; st.pop();
            for( pii tam : ke[ chuyen( u , v ) ] )
            {
                int u1 = tam.fi , v1 = tam.se;
                string res = f[u][v] + a[u1][v1];
                if( kt[u1][v1] )
                {
                    f[u1][v1] = max ( f[u1][v1] , res );
                    continue;
                }
                kt[u1][v1] = 1;
                f[u1][v1] = f[u][v] + a[u1][v1];
                st.push( mp( u1 , v1 ) );
            }
        }
    }
}

void xuli()
{
    loang( 1 , 1 );
    cout << f[n][m] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp" , "r" , stdin);
//    freopen(LT".out" , "w" , stdout);
    nhap();
    xuli();
}
