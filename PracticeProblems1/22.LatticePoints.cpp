#include<iostream>
using namespace std;

int latticePoints(int r)
{
    int x = 1, y = r;
    long long quadrantPoints = 0;
    while(y > 0)
    {
        if( 1ll * x * x + 1ll * y * y < 1ll * r * r)
        {
            quadrantPoints += y + 1;
            x++;
        }
        else
            y--;
    }
    return 4 * quadrantPoints + 1;

}
int main()
{
    int radius;
    cout << "Circle x^2 + y^2 = r^2 centered at (0,0)" << endl ;
    cout << "Enter radius: ";
    cin >> radius;
    cout << "Total Lattice points inside the circle is: " << latticePoints(radius) << endl;
    return 0;
}