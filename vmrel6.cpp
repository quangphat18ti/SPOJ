#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define maxn 85
#define pb push_back
#define endl "\n"
#define LT "vmrel6"
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m , k;
int a[maxn][maxn];
int kt[maxn] , T , Min[maxn];
vector <int> g;

void nhap()
{
    cin >> n;
    For( i , 1 , n ) For( j , 1 , n ) cin >> a[i][j];
    For( i , 1 , n ) a[i][i] = 0;
    For( i , 1 , n ) For( j , 1 , n )
    {
        if( a[i][j] == 0 || a[j][i] == 0 ) a[i][j] = a[j][i] = 0;
        if( a[i][j] == a[j][i] ) a[i][j] = a[j][i] = 0;
    }
    For( i , 1 , n ) Min[i] = 1;
}

void solve( int u )
{
    g.clear();
    For( i , 1 , n ) if( a[u][i] == 0 ) g.pb(i);

    int maxx = 0;
    for( int u : g ) maxx = max ( maxx , Min[u] );
    for( int u : g ) Min[u] = maxx;

    For( i  , 1 , n )
    {
        if( a[u][i] == 1 ) Min[i] = max( Min[i] , Min[u] + 1 );
        if( a[u][i] == 2 ) Min[i] = max( Min[i] , Min[u] );
    }
}

void dfs( int u )
{
    kt[u] = T;
    For( i , 1 , n )
    {
        if( i == u ) continue;
        if( a[u][i] > 0 ) continue;

        if( a[u][i] == 0 )
        {
            if( !kt[i] ) dfs(i);
            Min[u] = max( Min[u] , Min[i] );
        }

        if( a[u][i] == -1  )
        {
            if( !kt[i] ) dfs(i);
            Min[u] = max ( Min[u] , Min[i] + 1 );
        }

        if( a[u][i] == -2 )
        {
            if( !kt[i] ) dfs(i);
            Min[u] = max ( Min[u] , Min[i] );
        }
    }

    solve(u);
}

void xuli()
{
    For( i , 1 , n )
    {
        if( kt[i] ) continue;
        T++;
        dfs(i);
    }

    cout << *max_element( Min+1 , Min + n + 1 ) << endl;
    For( i , 1 , n ) cout << Min[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
