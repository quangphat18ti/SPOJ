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
#define LT "voroom"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int ke[maxn] , gt[maxn] , kt[maxn];

void nhap()
{
    cin >> n; n++;

    For( i , 1 , n )
    {
        ke[i] = i;
        gt[i] = 1;
        kt[i] = 0;
    }
}

int root( int u )
{
    if( u != ke[u] ) ke[u] = root(ke[u]);
    return ke[u];
}

void xuli()
{
    For( i , 1 , n - 1 )
    {
        int u , v; cin >> u >> v;
        u = root(u) , v = root(v);
        if( u == v )
        {
            if( kt[u] == 1 ) { cout << 0 << endl; return; }
            kt[u] = 1;
            continue;
        }

        if( gt[u] > gt[v] )
        {
            ke[v] = u;
            gt[u] += gt[v];
            kt[u] = max(kt[u] , kt[v]);
        }
        else
        {
            ke[u] = v;
            gt[v] += gt[u];
            kt[v] = max(kt[u] , kt[v]);
        }
    }

    vector<int> st;
    ll sum = 0;
    For( i , 1 , n )
    {
        if( i == ke[i] && kt[i] == 1 ) st.pb(gt[i]) , sum += gt[i];
    }

    ll ans = 0;
    for( int u : st )
    {
        ans += 1ll * u * (sum - u);
        ans += 1ll * u * (u - 1);
    }
    ans /= 2;
    ans += n;

    cout << 1ll * n * (n + 1) / 2 - ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}
