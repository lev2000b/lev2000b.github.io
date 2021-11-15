#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double p, q, sum = 0.00;
    int n;
    cin >> p >> q>>n;

    p = floor(p*100)/100;
    q = floor(q*100)/100;
    for (int i = 0; i < n; i++) {
        double v;
        cin >> v;
        double comi = v * (p / 100);
        if (comi > q)
            sum += v + comi;
        else
            sum += v+q;
    }
    sum *= 100;
    sum = floor(sum);
    sum /= 100;
    cout << sum;
}