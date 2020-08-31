#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define maxn 100005
#define pb push_back
#define endl "\n"
#define LT "vmtrip"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m , k;
vi ke[maxn] , U[maxn];
int Time[maxn] , S , T , vc = 1e9;
int p[maxn] , kt[maxn] , mx = 0 , check[maxn];
int lasttime[maxn];

void nhap()
{
    cin >> n >> m >> S >> T;
    For( i , 1 , m )
    {
        int u , v; cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
}

void loang()
{
    For( i , 1,  n ) Time[i] = vc;
    queue <int> st;
    st.push(S); Time[S] = 1;
    while( st.size() )
    {
        int u = st.front(); st.pop();
        for( int v : ke[u] )
        {
            if( Time[v] != vc ) continue;
            Time[v] = Time[u] + 1;
            st.push(v);
        }
    }
}

void dfs( int s , int gt )
{
    if( s == k && gt == 1 ) return;
    if( s == 1 && gt == -1 ) return;
    if( check[s + gt] ) return;

    mx++; int next = s + gt;
    vector <int> ans;
    for( int u : U[s] )
    {
        for( int v : ke[u] )
        {
            if( Time[v] == Time[u] + gt && kt[v] == lasttime[next] )
            {
                kt[v] = mx;
                ans.pb(v);
            }
        }
    }
    lasttime[next] = mx;

    if( ans.size() == U[s+gt].size() ) return;
    U[ next ] = ans;
    dfs( next , gt );
}

void solve( int s )
{
    mx++;

    int minn = *min_element( U[s].begin() , U[s].end() );
    U[s].clear(); U[s].pb(minn);

    kt[minn] = mx;
    lasttime[s] = mx;

    dfs( s , 1 );
    dfs( s , -1 );
    check[s] = 1;
}

void process()
{
    U[k].pb(T); kt[T] = 1;
    FOr( i , k - 1 , 1 )
    {
        for( int u : U[i+1] )
        {
            for( int v : ke[u] )
            {
                if( Time[v] + 1 == Time[u] && kt[v] == 0 )
                {
                    kt[v] = 1;
                    U[i].pb(v);
                }
            }
        }
    }

    For( i , 1 , k ) lasttime[i] = 1;
}

void xuli()
{
    loang();
    k = Time[T];
    For( i , 1 , k ) cin >> p[i];

    mx = 1;
    process();

    For( i , 1 , k ) solve( p[i] );

    For( i , 1 , k ) cout << U[i][0] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
