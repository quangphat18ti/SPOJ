#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LT "ltpmseq"
#define maxn 100005
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
string s[maxn];

void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> s[i];
    sort( s+1 , s+n+1 );
}

void xuli()
{
    int i = 1;
    while( i <= n )
    {
        int j = i;
        while( s[j] == s[i] ) i++;
        if( (i - j) % 2 )
        {
            cout << s[j] << endl;
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
