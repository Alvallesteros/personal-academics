#include <iostream>
using namespace std;

struct Point3D {
    int x;
    int y;
    int z;
};

int getCoord ( Point3D p ) {
    return p.x;
}

int delta ( Point3D p1, Point3D p2 ) {
    int a[2];
    a[0] = p1.x;
    a[1] = p2.x;
    return a[1];
}

int main ( void ) {
    Point3D p, q;
    p.x = 5;
    p.y = 7;
    p.z = -2;
    q.x = 1;
    q.y = 3;
    q.z = -6;
    cout << delta( p, q ) << endl;
    return 0;
}