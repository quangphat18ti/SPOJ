#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define maxn 100005
#define pb push_back
#define endl "\n"
#define LT "mecung"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m , k;
vector<pii> ke[maxn];
int f[maxn] , vc = 1e9;
int kt[maxn];

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m )
    {
        int u , v , c;
        cin >> u >> v >> c;
        ke[u].pb( mp( c , v ) );
        ke[v].pb( mp( c , u ) );
    }
}

void truyvet( int u )
{
    vector <int> st1 , st2;
    st1.pb(u);
    int t = f[1];
    For( z , 1 , t )
    {
        st2.clear();
        int minn = vc;
        for( int u : st1 )
        {
            for( auto tam : ke[u] )
            {
                int v = tam.se;
                if( f[u] == f[v] + 1 )
                    minn = min ( minn , tam.fi );
            }
        }

        cout << minn << ' ';
        for( int u : st1 )
        {
            for( auto tam : ke[u] )
            {
                int v = tam.se;
                if( f[u] == f[v] + 1 && tam.fi == minn && kt[v] < z )
                {
                    kt[v] = z;
                    st2.pb( v );
                }
            }
        }
        st1 = st2;
    }
}

void xuli()
{
    For( i , 1 , n ) f[i] = vc;
    queue <int> st;
    st.push(n); f[n] = 0;
    while( st.size() )
    {
        int sz = st.size();
        while( sz-- )
        {
            int u = st.front(); st.pop();
            for( auto tam : ke[u] )
            {
                int v = tam.se;
                if( f[v] != vc ) continue;
                f[v] = f[u] + 1;
                st.push(v);
            }
        }
    }
    cout << f[1] << endl;
    truyvet(1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp" , "r" , stdin);
//    freopen(LT".out" , "w" , stdout);
    nhap();
    xuli();
}
