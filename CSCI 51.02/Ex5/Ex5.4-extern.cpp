#include <iostream>
using namespace std;

struct Point3D {
    int x;
    int y;
    int z;
};

extern int getCoord( Point3D p );

extern int delta(Point3D p1, Point3D p2);

extern int main(void);