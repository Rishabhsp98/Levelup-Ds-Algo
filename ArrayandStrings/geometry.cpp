#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

double findarea(double a, double b, double c)
{
    if (a < 0 || b < 0 || c < 0 || (a + b <= c) || a + c <= b || b + c <= a)
    {
        cout << "Not a valid trianglen";
        exit(0);
    }
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
double Distance_between(double x1, double x2, double y1, double y2, double z1, double z2)
{
    double d = 0;
    d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2) * 1.0);
    return d;
}
int main()
{
    double h, a, b, c, d, va, vb, vc, vd;
    cin >> h >> a >> b >> c >> d >> va >> vb >> vc >> vd;
    char da, db, dc, dd;
    cin >> da >> db >> dc >> dd;
    if (da == 'D')
    {
        va = va * (-1);
    }
    if (db == 'D')
    {
        vb = vb * (-1);
    }
    if (dc == 'D')
    {
        vc = vc * (-1);
    }
    if (dd == 'D')
    {
        vd = vd * (-1);
    }
    double xa = 0, ya = h * (-1);
    double xb = h, yb = h * (-1);
    double xc = h, yc = 0;
    double xd = 0, yd = 0;
    double z[100][4];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            z[i][j] = 0;
        }
    }
    z[0][0] = a;
    z[0][1] = b;
    z[0][2] = c;
    z[0][3] = d;
    for (int i = 1; i < 100; i++)
    {
        z[i][0] = z[i - 1][0] + va;
        z[i][1] = z[i - 1][1] + vb;
        z[i][2] = z[i - 1][2] + vc;
        z[i][3] = z[i - 1][3] + vd;
        if (z[i][0] > h)
        {
            z[i][0] = h;
        }
        if (z[i][0] < 0)
        {
            z[i][0] = 0;
        }
        if (z[i][1] > h)
        {
            z[i][1] = h;
        }
        if (z[i][1] < 0)
        {
            z[i][1] = 0;
        }
        if (z[i][2] > h)
        {
            z[i][2] = h;
        }
        if (z[i][2] < 0)
        {
            z[i][2] = 0;
        }
        if (z[i][3] > h)
        {
            z[i][3] = h;
        }
        if (z[i][3] < 0)
        {
            z[i][3] = 0;
        }
    }
    double ab[100];
    for (int i = 0; i < 100; i++)
    {
        ab[i] = Distance_between(xa, xb, ya, yb, z[i][0], z[i][1]);
    }
    double bc[100];
    for (int i = 0; i < 100; i++)
    {
        bc[i] = Distance_between(xb, xc, yb, yc, z[i][1], z[i][2]);
    }
    double ac[100];
    for (int i = 0; i < 100; i++)
    {
        ac[i] = Distance_between(xa, xc, ya, yc, z[i][0], z[i][2]);
    }
    double ad[100];
    for (int i = 0; i < 100; i++)
    {
        ad[i] = Distance_between(xa, xd, ya, yd, z[i][0], z[i][3]);
    }
    double bd[100];
    for (int i = 0; i < 100; i++)
    {
        bd[i] = Distance_between(xb, xd, yb, yd, z[i][1], z[i][3]);
    }
    double cd[100];
    for (int i = 0; i < 100; i++)
    {
        cd[i] = Distance_between(xc, xd, yc, yd, z[i][2], z[i][3]);
    }

    double abc[100];
    for (int i = 0; i < 100; i++)
    {
        abc[i] = findarea(ab[i], bc[i], ac[i]);
    }
    double adc[100];
    for (int i = 0; i < 100; i++)
    {
        adc[i] = findarea(ad[i], cd[i], ac[i]);
    }
    double abd[100];
    for (int i = 0; i < 100; i++)
    {
        abd[i] = findarea(ab[i], ad[i], bd[i]);
    }
    double bcd[100];
    for (int i = 0; i < 100; i++)
    {
        bcd[i] = findarea(bc[i], cd[i], bd[i]);
    }

    double maxabc = abc[0];
    for (int i = 0; i < 100; i++)
    {
        if (maxabc < abc[i])
            maxabc = abc[i];
    }
    double minabc = abc[0];
    for (int i = 0; i < 100; i++)
    {
        if (minabc > abc[i])
            minabc = abc[i];
    }
    double maxadc = adc[0];
    for (int i = 0; i < 100; i++)
    {
        if (maxadc < adc[i])
            maxadc = adc[i];
    }
    double minadc = adc[0];
    for (int i = 0; i < 100; i++)
    {
        if (minadc > adc[i])
            minadc = adc[i];
    }
    cout << round(4 * pow((maxabc + maxadc), 2)) << " " << round(4 * pow((minabc + minadc), 2)) << endl;
    return 0;
}