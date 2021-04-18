struct point3d
{
	point3d() = default;
	point3d(double xx, double yy, double zz);
	double x;
	double y;
	double z;
};

struct triangle
{
	triangle(const point3d& p1,
		const point3d& p2,
		const point3d& p3);

	point3d normal;
	point3d v1;
	point3d v2;
	point3d v3;
	point3d closest_point(point3d inputpt);
};
