///

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
#define LT "vosnet"
#define maxn 3005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int kc[maxn][maxn];
int f[maxn][maxn];
vi ke[maxn];
int dem[maxn];

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m )
    {
        int u , v; cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
}

vi loang( int s )
{
    vi f(n + 1 , 0);
    f[s] = 1;
    queue<int> st; st.push(s);
    while( !st.empty() )
    {
        int u = st.front(); st.pop();
        for(int v : ke[u])
        {
            if( f[v] ) continue;
            f[v] = f[u] + 1;
            st.push(v);
        }
    }

    For( i , 1 , n ) f[i]--;
    return f;
}

void Build_kc()
{
    For( i , 1 , n )
    {
        vi u = loang(i);
        For( j , 1 , n ) kc[i][j] = u[j];
    }
}

int Count( int kc )
{
    int tam = log2(kc);
    if( (1 << tam) < kc ) tam++;
    return tam;
}

void Build_f()
{
    For( i , 1 , n )
    {
        f[i][i] = 0;
        For( j , i + 1 , n )
        {
            f[i][j] = f[j][i] = Count( kc[i][j] );
        }
    }
}

void xuli()
{
    Build_kc();
    Build_f();

    int ans = 0;
    For( i , 1 , n )
    {
        For( j , i + 1 , n )
        {
            dem[f[i][j]]++;
            ans = max( ans , f[i][j] );
        }
    }
    ans++;
    For( i , 1 , ans ) cout << dem[i] << ' '; cout << endl;
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

