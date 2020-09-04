#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LT "znanstve"
#define maxn 1005
#define endl "\n"
#define pb push_back
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;

int i , j , n , m , k;
char a[maxn][maxn];
string s[maxn];
map <string,int> dd;

void nhap()
{
    cin >> n >> m;
    For( i , 1 , n ) For( j , 1 , m ) cin >> a[i][j];
}

bool check()
{
    For( i , 1 , m )
    {
        int tam = dd[s[i]];
        if( tam == 1 ) return 0;
        dd[s[i]] = 1;
    }
    return 1;
}

void xuli()
{
    FOr( i , n , 1 )
    {
        For( j , 1 , m ) s[j] = a[i][j] + s[j];
        if( check() )
        {
            cout << i - 1 << endl;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
