#include <iostream>
#include<cmath>
using namespace std;

long long szamjegy(long long m)
{
    if (m == 0)
        return 0;
    else
        return 1 + szamjegy(m / 10);
}

long long countSteps(long long x)
{
    long long c = 0, last = x, digits, divisor, first, lastnumber, skipped;
 
    while (last) {
        digits = szamjegy(last);
        digits -= 1;
        divisor = pow(10, digits);
        first = last / divisor;
        lastnumber = first * divisor;
        skipped = (last - lastnumber) / first;
        skipped += 1;
        c += skipped;
        last = last - (first * skipped);
    }
 
    return c;
}
 
int main()
{
    long long n;
    cin >> n;
    if ( countSteps(n) % 2 ) cout << 1 << endl << n % 10;
    else cout << 2;
    return 0;
}