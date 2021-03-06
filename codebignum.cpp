#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )
#define pb push_back

typedef vector<int> big;
int mod = 1e9;

int x , y;

big operator * ( big a , int b )
{
    big ans;
    ll carry = 0;

    For( i , 0 , a.size() - 1 )
    {
        carry += 1ll * a[i] * b;
        ans.pb(carry % mod);
        carry /= mod;
    }
    if( carry ) ans.pb(carry);
    return ans;
}

big operator + ( big a , big b )
{
    big ans;
    ll carry = 0;
    for( int i = 0 ; i < a.size() || i < b.size() ; i++ )
    {
        if( i < a.size() ) carry += a[i];
        if( i < b.size() ) carry += b[i];
        ans.pb( carry % mod );
        carry /= mod;
    }
    if( carry ) ans.pb(carry);
    return ans;
}

big operator * ( big a , big b )
{
    big ans ( a.size() + b.size() , 0 );
    For( i , 0 , a.size() - 1 )
    {
        ll carry = 0;
        For( j , 0 , b.size() - 1 )
        {
            carry += ans[i+j] + 1ll * a[i] * b[j];
            ans[i+j] = carry % mod;
            carry /= mod;
        }
        if(carry)  ans[ i + b.size() ] = carry;
    }
    while( ans.size() > 1 && ans.back() == 0 ) ans.pop_back();
    return ans;
}

big operator - ( big a , big b )
{
    big ans;
    ll carry = 0;
    For( i , 0 , a.size() - 1 )
    {
        carry += a[i];
        if( i < b.size() ) carry -= b[i];
        if( carry < 0 )
        {
            carry += mod;
            a[i+1] -= 1;
        }
        ans.pb( carry % mod );
        carry = carry / mod;
    }
    return ans;
}

void print( big a )
{
    int tam = a.size() - 1;
    printf("%d",a[tam]);
    FOr( i , tam-1 , 0 ) printf("%09d",a[i]);
    printf("\n");
}

int main()
{
    cin >> x >> y;
    big A; A.push_back(x);
    big B; B.push_back(y);
    A = A * B;
    print(A);;
}


