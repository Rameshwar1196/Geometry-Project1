#include "point3d.h"
point3d::point3d(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
}

triangle::triangle(
	const point3d& p1,
	const point3d& p2,
	const point3d& p3)
{
	v1 = p1;
	v2 = p2;
	v3 = p3;
}
point3d triangle::closest_point(point3d pointiputpt)
{
	return point3d();
}
