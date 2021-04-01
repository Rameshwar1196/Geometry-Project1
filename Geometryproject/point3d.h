struct point3d
{
	double x;
	double y;
	double z;
};

struct triangle
{
	point3d normal;
	point3d v1;
	point3d v2;
	point3d v3;
	point3d closest_point(point3d inputpt);
};
