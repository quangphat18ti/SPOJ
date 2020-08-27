#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define maxn 3505
#define pb push_back
#define endl "\n"
#define LT "pbcpoint"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m , k;
int add = 1001;
int kt[maxn][maxn];
int ans = 0;
int h[2][maxn] , c[2][maxn] , vc = 1e9;
queue <pii> st;
int mxx = 0 , mxy = 0;

void update( int u , int v )
{
    kt[u][v] = 1;  st.push( mp(u , v) );
    h[0][u] = min ( h[0][u] , v );
    c[0][v] = min ( c[0][v] , u );
    h[1][u] = max ( h[1][u] , v );
    c[1][v] = max ( c[1][v] , u );
}

void nhap()
{
    cin >> m; n = 0;
    For( i , 1 , 2010 ) h[0][i] = c[0][i] = vc ; /// 0 là minn
    For( i , 1 , m )
    {
        int x , y; cin >> x >> y;   x += add , y += add;

        if( kt[x][y] )  continue;

        update( x , y );
        mxx = max ( mxx , x );
        mxy = max ( mxy , y );
    }
}

void xuli()
{
    while( st.size() )
    {
        int u = st.front().fi , v = st.front().se;  st.pop();

        int R = h[1][u] - 1 , L = h[0][u] + 1;

        For( i , v + 1 , R )
        {
            if( kt[u][i] ) break;
            update( u , i );
        }

        FOr( i , v - 1 , L )
        {
            if( kt[u][i] ) break;
            update( u , i );
        }

        int D = c[1][v] - 1 , U = c[0][v] + 1;

        For( i , u + 1 , D )
        {
            if( kt[i][v] ) break;
            update( i , v );
        }

        FOr( i , u - 1 , U )
        {
            if( kt[i][v] ) break;
            update( i , v );
        }
    }

    For( i , 1 , mxx ) For( j , 1 , mxy ) ans += kt[i][j];
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp" , "r" , stdin);
//    freopen(LT".out" , "w" , stdout);
    nhap();
    xuli();
}
