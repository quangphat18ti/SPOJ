#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1505
#define pb push_back
#define endl "\n"
#define LT "labudovi"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m;
char a[maxn][maxn];
pii L[2]; int nL = 0;
int kt[3][maxn][maxn] , vc = 1e9 , T = 0;
int di[10] = { 0 , -1 , 0 , 1 , 0 , -1 };
vector <pii> U[3];

bool check( int u , int v )
{
    return ( u >= 1 && u <= n && v >= 1 && v <= m );
}

void nhap()
{
    cin >> n >> m; nL = -1;

    For( k , 0 , 2 ) For( i , 1 , n ) For( j , 1 , m ) kt[k][i][j] = vc;

    For( i , 1 , n ) For( j , 1 , m )
    {
        cin >> a[i][j];
        if( a[i][j] == 'L' )
        {
            L[++nL] = mp( i , j );

            kt[2][i][j] = 0;
            U[2].pb( L[nL] );

            kt[nL][i][j] = 0;
            U[nL].pb( L[nL] );
        }
        if( a[i][j] == '.' )
        {
            kt[2][i][j] = 0;
            U[2].pb( mp(i,j) );
        }
    }
}

vector<pii> loang( vector<pii> U , int sl )
{
    vector<pii> ans;

    if( sl == 2 )
    {
        For( i , 0 , U.size()-1 )
        {
            int u = U[i].fi , v = U[i].se;
            For( k , 1 , 4 )
            {
                int i = u + di[k] , j = v + di[k+1];
                if( !check(i,j) ) continue;
                if( kt[sl][i][j] != vc ) continue;
                if( sl <= 1 && kt[2][i][j] == vc ) continue;
                kt[sl][i][j] = T;
                ans.pb( mp(i , j) );
            }
        }
        return ans;
    }
    else
    {
        queue <pii> st;
        for( auto tam : U ) st.push(tam);
        while( st.size() )
        {
            int u = st.front().fi , v = st.front().se; st.pop();
            For( k , 1 , 4 )
            {
                int i = u + di[k] , j = v + di[k+1];
                if( !check(i,j) ) continue;
                if( kt[sl][i][j] != vc ) continue;
                if( kt[2][i][j] == vc ) continue;
                kt[sl][i][j] = T;
                ans.pb( mp(i , j) );
                st.push( mp(i , j) );
            }
        }
        if( ans.size() == 0 ) return U;
        return ans;
    }
}

bool KT()
{
    For( i , 0 , U[0].size()-1 )
    {
        int u = U[0][i].fi , v = U[0][i].se;
        if( kt[1][u][v] != vc ) return true;
    }

    For( i , 0 , U[1].size()-1 )
    {
        int u = U[1][i].fi , v = U[1][i].se;
        if( kt[0][u][v] != vc ) return true;
    }
    return false;
}

void xuli()
{
    For( i , 0 , 1 ) U[i] = loang( U[i] , i );

    if( KT() ) { cout << T << endl; return; }
    while( true )
    {
        T++;
        FOr( i , 2 , 0 ) U[i] = loang( U[i] , i );

        if( KT() ) { cout << T << endl; return; }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
