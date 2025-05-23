#pragma once

#include "head.hpp"

namespace geometry
{

double epsilon = 0.00001;
double LineLiesOnPlane = 0xBAABDAD;
double LineValue = 0xBADBABE;

struct Vect;

struct Point
{
    double x = InvalidValue;
    double y = InvalidValue;
    double z = InvalidValue;
    Point() {}
    Point(const double& x_coord, const double& y_coord, const double& z_coord): \
            x(x_coord), y(y_coord), z(z_coord) {}
    Point (const Point& p): x(p.x), y(p.y), z(p.z) {}

    bool valid() const
    {
        if (x != InvalidValue && y != InvalidValue && z != InvalidValue)  return true;
        return false;
    }

    void print_Point() const
    {
        std::cout << "Point:" << std::endl;
        std::cout << x << " " << y << " " << z << std::endl;
    }

    Point operator=(Point p1)
    {
        x = p1.x;
        y = p1.y;
        z = p1.z;
        return *this;
    }

    friend Point operator+(Point p, Vect v);


    Point operator-(Point p1) 
    {

        //x = x - p1.x;
        //y = y - p1.y;
        //z = z - p1.z;
        return (Point(x - p1.x, y - p1.y, z - p1.z));
        //return *this;
    }
    
    double count_distance(const Point& p) const
    {
         return (fabs(p.x - x) + fabs(p.y - y) + fabs(p.z - z));
    }

    bool operator==(const Point& p1) const
    {
        if (fabs(p1.x - x) < epsilon && fabs(p1.y - y) < epsilon && fabs(p1.z - z) < epsilon)
        {
            return true;
        }
        return false;
    }

    bool operator<(const Point & p) const 
    {
		return ((fabs(x-p.x) < epsilon) && (fabs(y - p.y) < epsilon));
	}
    
};  /* struct Point */

struct Vect
{
    double a = InvalidValue;
    double b = InvalidValue;
    double c = InvalidValue;
    Vect() {}
    Vect(const double& v1, const double& v2, const double& v3): a(v1), b(v2), c(v3) {}
    Vect(const Point& p1, const Point& p2)
    {
        a = p2.x - p1.x;
        b = p2.y - p1.y;
        c = p2.z - p1.z;
    }

    bool valid() const
    {
        if (a != InvalidValue && b != InvalidValue && c != InvalidValue)  return true;
        return false;
    }

    Vect operator=(Vect v1)
    {
        a = v1.a;
        b = v1.b;
        c = v1.c;
        return *this;
    }

    Vect operator*(double param)
    {
        a = a * param;
        b = b * param;
        c = c * param;
        return *this;
    }

    Vect operator-(Vect v) 
    {
        a = a - v.a;
        b = b - v.b;
        c = c - v.c;
        return *this;
    }

    Vect operator-()
    {
        a = -a;
        b = -b;
        c = -c;
        return *this;
    }

    void Vect_Print() const
    {
        std::cout << "vector:" << std::endl;
        std::cout << a << " " << b << " " << c << std::endl;
    }

    const Vect operator*(double param) const 
    {
        double x = a * param;
        double y = b * param;
        double z = c * param;
        return Vect(x, y, z);
    }

    friend Point operator+(Vect v, Point p);

};  /* struct Vect */

Point operator+(Point p, Vect v)
{
    p.x = p.x + v.a;
    p.y = p.y + v.b;
    p.z = p.z + v.c;
    return (Point(p.x, p.y, p.z));
}

double Dot(Vect v1, Vect v2);

struct Line
{
    Point origin;
    Vect direction;
    Line () {}
    Line(const Point& orig, const Vect& dir)
    {
        origin = orig;
        direction = dir;
    }
    Line(const Point& p1, const Point& p2)
    {
        origin.x = p1.x;
        origin.y = p1.y;
        origin.z = p1.z;
        direction.a = p2.x - p1.x;
        direction.b = p2.y - p1.y;
        direction.c = p2.z - p1.z;
    }

    bool valid() const
    {
        //Point p2(direction.a + origin.x, direction.b + origin.y, direction.c + origin.z);
        //p2.print_Point();
        if (origin.valid() && direction.valid())
        {
            if (fabs(direction.a) > epsilon || 
                fabs(direction.b) > epsilon || 
                fabs(direction.c) > epsilon)
            {
                return true;
            }
        }
        return false;
    }

    // Line operator-()
    // {
    //     direction = -direction;
    //     return *this;
    // }

    void print_Line() const
    {
        std::cout << "////////////////////////" << std::endl;
        std::cout << "Line:" << std::endl;
        std::cout << "origin:" << std::endl;
        std::cout << origin.x << " " << origin.y << " " << origin.z << std::endl;
        std::cout << "direction:" << std::endl;
        std::cout << direction.a << " " << direction.b << " " << direction.c << std::endl;
        std::cout << "end Line" << std::endl;
        std::cout << "////////////////////////" << std::endl;
    }

};  /* struct Line */


struct Triangle 
{
    Point p1;
    Point p2;
    Point p3;

    Triangle(const Point& point1, const Point& point2, const Point& point3)
    {
        p1 = point1;
        p2 = point2;
        p3 = point3;
    }

    bool valid() const
    {
        if ((fabs((p3.x - p1.x) * (p2.y - p1.y) - (p3.y - p1.y) * (p2.x - p1.x)) < epsilon)  &&
            (fabs((p3.x - p1.x) * (p2.z - p1.z) - (p3.z - p1.z) * (p2.x - p1.x)) < epsilon))
        {
            std::cout << "it a line GUYS or a point" << std::endl;
            return false;
        }
        return true;
    }

    void print_Triangle() const
    {
        std::cout << "////////////////////////" << std::endl;
        std::cout << "Triangle:" << std::endl;
        p1.print_Point();
        p2.print_Point();
        p3.print_Point();
        std::cout << "end Triangle" << std::endl;
        std::cout << "////////////////////////" << std::endl;
    }
    
    Triangle operator=(Triangle tr)
    {
        p1 = tr.p1;
        p2 = tr.p2;
        p3 = tr.p3;
        return *this;
    }
}; /* struct Triangle */

struct Plane
{
    double a = InvalidValue;
    double b = InvalidValue;
    double c = InvalidValue;
    double d = InvalidValue;
    Plane(const double& a_, const double& b_, const double& c_, const double& d_) 
    {
        a = a_;
        b = b_;
        c = c_;
        d = d_;
    }
    Plane(const Point& p1, const Point& p2, const Point& p3)
    {
        a = p1.y * (p2.z - p3.z) + p2.y * (p3.z - p1.z) + p3.y * (p1.z - p2.z);
        b = p1.z * (p2.x - p3.x) + p2.z * (p3.x - p1.x) + p3.z * (p1.x - p2.x);
        c = p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
       // a = p1.y * ()
        if (fabs(a) < epsilon && fabs(b) < epsilon && fabs(c) < epsilon)
        {
            std::cout << "It's not a plane, it's a line" << std::endl;
            d = LineValue;
        }
        else
        {
            d =-(p1.x * (p2.y * p3.z - p3.y * p2.z) + p2.x * (p3.y * p1.z - p1.y * p3.z) \
             + p3.x * (p1.y * p2.z - p2.y * p1.z));
        }
    }

    bool valid() const
    {
        if (a != InvalidValue && b != InvalidValue && c != InvalidValue && d != InvalidValue)
        {
            return true;
        }
        if (a >= epsilon || b >= epsilon || c >= epsilon)
        {
            return true;
        }  
        return false;
    }
    bool operator==(Plane p1)
    {
        if (fabs(p1.a - a) < epsilon && fabs(p1.b - b) < epsilon && fabs(p1.c - c) < epsilon && fabs(p1.d - d) < epsilon)
        {
            return true;
        }
        return false;
    }
    void print_plane() const
    {
        std::cout << "plane: "  << std::endl;
        std::cout << a << " " << b << " " << c << " " << d << std::endl;
    }
    Point generate_point_on_plane() const
    {
        Point res;
        
        if (a != 0)
        {
            res.y = 0;
            res.z = 0;
            res.x = -d / a;
        }
        else if (b != 0)
        {
            res.x = 0;
            res.z = 0;
            res.y = -d / b;
        }
        else if (c != 0)
        {
            res.x = 0;
            res.y = 0;
            res.z = -d / c;
        }
        else
        {
            std::cout << "error with generating points" << std::endl;
        }
        return res;
    }
};  /* struct Plane */


double Dot(Vect v1, Vect v2)
{
    double res = v1.a * v2.a + v1.b * v2.b + v1.c * v2.c;
    return res;
}


Vect Cross(Vect v1, Vect v2)
{
    double a = v1.c * v2.b - v1.b * v2.c;
    double b = v1.a * v2.c - v1.c * v2.a;
    double c = v1.b * v1.a - v1.a * v2.b;
    return (Vect(a, b, c));
}

bool LineIntersectPlane(const Line& l, const Plane& pl, Point& intersection) // TODO сделать константными!!!!
{
    double res = InvalidValue;
    bool is_line_valid = l.valid();
    bool is_plane_valid = pl.valid();
    double param = InvalidValue;
    intersection.x = InvalidValue; 
    intersection.y = InvalidValue;
    intersection.z = InvalidValue;
    if (is_line_valid && is_plane_valid)
    {
        Vect plane_normal(pl.a, pl.b, pl.c);
        if (plane_normal.valid())
        {
            res = Dot(l.direction, plane_normal);
        }
        else
        {
            std::cout << "plane_normal is invalid" << std::endl;
        }
    }
    else
    {
        std::cout << "smth is invalid" << std::endl;
        return false;
    }
    if (fabs(res) < epsilon)
    {
        // Check if line lies in the plane or not.
        // We do this, somewhat arbitrarily, by checking if
        // the origin of the line is in the plane. If it is,
        // set the parameter of the intersection to be 0. An
        // application may wish to handle this case differently...
        if (fabs(l.origin.x * pl.a + l.origin.y * pl.b +
                l.origin.z * pl.c + pl.d) < epsilon) 
        {
            param = 0;
            intersection.x = LineLiesOnPlane;
            intersection.y = LineLiesOnPlane;
            intersection.z = LineLiesOnPlane;
            return true;
        } 
        else 
        {
            return false;
        }
    }
    /* computing intersection */
    param = -(pl.a * l.origin.x + pl.b * l.origin.y + pl.c * l.origin.z + pl.d);
    param = param / res;
    intersection = l.origin + l.direction * param;
    return true;
} /* LineIntersectPlane */


bool IntersectionOfTriangleAndPlane(const Plane& pl, const Triangle& tr, Point& point_intersec, Line& line_intersec)
{
    bool is_plane_valid = pl.valid();
    pl.print_plane();
    if (is_plane_valid)
    {
        double dot1 = InvalidValue, dot2 = InvalidValue, dot3 = InvalidValue;
        Vect plane_normal(pl.a, pl.b, pl.c);
        Point point_on_plane = pl.generate_point_on_plane();
        tr.p1.print_Point();
        tr.p2.print_Point();
        tr.p3.print_Point();
        Vect v1(point_on_plane, tr.p1);
        Vect v2(point_on_plane, tr.p2);
        Vect v3(point_on_plane, tr.p3);
        if (plane_normal.valid() &&
            v1.valid() &&
            v2.valid() &&
            v3.valid())
        {
            v1.Vect_Print();
            v2.Vect_Print();
            v3.Vect_Print();
            dot1 = Dot(plane_normal, v1);
            dot2 = Dot(plane_normal, v2);
            dot3 = Dot(plane_normal, v3);
            std::cout << dot1 << " " << dot2 << " " << dot3 << std::endl;
            if (fabs(dot1) < epsilon) dot1 = 0;
            if (fabs(dot2) < epsilon) dot2 = 0;
            if (fabs(dot3) < epsilon) dot3 = 0;
            double d1d2, d1d3, d2d3;
            d1d2 = dot1 * dot2;
            d1d3 = dot1 * dot3;
            d2d3 = dot2 * dot3;
            if (d1d2 > 0.0 && d1d3 > 0.0 && d2d3 > 0.0) 
            {
                // all points above plane
                std::cout << "all points above plain" << std::endl;
                return false;
            } 
            else if (d1d2 < 0.0 && d1d3 < 0.0 && d2d3 < 0.0) 
            {
                // all points below plane
                std::cout << "all points below plain" << std::endl;
                return false;
            }
            if (fabs(dot1) + fabs(dot2) + fabs(dot3) == 0) 
            {
                // coplanar case
                std::cout << "no need for this func" << std::endl;
                return true;
            }
            // Most common intersection
            if ((dot1 > 0 && dot2 > 0 && dot3 < 0) ||
                (dot1 < 0 && dot2 < 0 && dot3 > 0)) 
            {
                //isect.type = line;
                Line l1(tr.p1, tr.p3);
                Line l2(tr.p2, tr.p3);
                Point point1, point2;
                LineIntersectPlane(l1, pl, point1);
                LineIntersectPlane(l2, pl, point2);
                //isect.line.d = point2 - point1;
                //isect.line.p = point1;
                Vect v(point1, point2);
                line_intersec.origin = point1;
                line_intersec.direction = v;
                return true;
            }

            if ((dot2 > 0 && dot3 > 0 && dot1 < 0) ||
                (dot2 < 0 && dot3 < 0 && dot1 > 0)) 
            {
                //isect.type = line;
                Line l1(tr.p2, tr.p1);
                Line l2(tr.p3, tr.p1);
                Point point1, point2;
                LineIntersectPlane(l1, pl, point1);
                LineIntersectPlane(l2, pl, point2);
                //isect.line.d = point2 - point1;
                //isect.line.p = point1;
                Vect v(point1, point2);
                line_intersec.origin = point1;
                line_intersec.direction = v;
                return true;
            }

            if ((dot1 > 0 && dot3 > 0 && dot2 < 0) ||
                (dot1 < 0 && dot3 < 0 && dot2 > 0)) 
            {
                //isect.type = line;
                Line l1(tr.p1, tr.p2);
                Line l2(tr.p3, tr.p2);
                Point point1, point2;
                LineIntersectPlane(l1, pl,point1);
                LineIntersectPlane(l2, pl, point2);
                //isect.line.d = point2 - point1;
                //isect.line.p = point1;
                Vect v(point1, point2);
                line_intersec.origin = point1;
                line_intersec.direction = v;
                return true;
            }

            // Case b
            if (dot1 == 0 && ((dot2 > 0 && dot3 > 0) || (dot2 < 0 && dot3 < 0))) 
            {
                //isect.point = tri.p1;
                point_intersec = tr.p1;
                return true;
            }
            if (dot2 == 0 && ((dot1 > 0 && dot3 > 0) || (dot1 < 0 && dot3 < 0))) 
            {
                //isect.type = point;
                //isect.point = tri.p2;
                point_intersec = tr.p2;
                return true;
            }
            if (dot3 == 0 && ((dot2 > 0 && dot1 > 0) || (dot2 < 0 && dot1 < 0))) 
            {
                //isect.type = point;
                //isect.point = tri.p3;
                point_intersec = tr.p3;
                return true;
            }
            // Case c
            if (dot1 == 0 && ((dot2 > 0 && dot3 < 0) || (dot2 < 0 && dot3 > 0))) 
            {
                //isect.type = line;
                Line l1(tr.p3, tr.p2);
                Point point1;
                LineIntersectPlane(l1, pl, point1);
                //isect.line.d = point1 - tri.p1;
                //isect.line.p = tri.p1;
                Vect v(tr.p1, point1);
                line_intersec.origin = tr.p1;
                line_intersec.direction = v;
                return true;
            }
            if (dot2 == 0 && ((dot1 > 0 && dot3 < 0) || (dot1 < 0 && dot3 > 0))) 
            {
                //isect.type = line;
                Line l1(tr.p1, tr.p3);
                Point point1;
                LineIntersectPlane(l1, pl, point1);
                //isect.line.d = point1 - tri.p2;
                //isect.line.p = tri.p2;
                Vect v(tr.p2, point1);
                line_intersec.origin = tr.p2;
                line_intersec.direction = v;
                return true;
            }
            if (dot3 == 0 && ((dot1 > 0 && dot2 < 0) || (dot1 < 0 && dot2 > 0))) 
            {
                //isect.type = line;
                Line l1(tr.p1, tr.p2);
                Point point1;
                LineIntersectPlane(l1, pl, point1);
                //isect.line.d = point1 - tri.p3;
                //isect.line.p = tri.p3;
                Vect v(tr.p3, point1);
                line_intersec.origin = tr.p3;
                line_intersec.direction = v;
                return true;
            }

            // Case d
            if (dot1 == 0 && dot2 == 0) 
            {
                //isect.type = line;
                //isect.line.d = tri.p2 - tri.p1;
                //isect.line.p = tri.p1;
                Vect v(tr.p1, tr.p2);
                line_intersec.origin = tr.p1;
                line_intersec.direction = v;
                return true;
            }
            if (dot2 == 0 && dot3 == 0) 
            {
                //isect.type = line;
                //isect.line.d = tri.p3 - tri.p2;
                //isect.line.p = tri.p2;
                Vect v(tr.p2, tr.p3);
                line_intersec.origin = tr.p2;
                line_intersec.direction = v;
                return true;
            }
            if (dot1 == 0 && dot3 == 0) 
            {
                //isect.type = line;
                //isect.line.d = tri.p3 - tri.p1;
                //isect.line.p = tri.p1;
                // TODO it can be mistake here
                Vect v(tr.p1, tr.p3);
                line_intersec.origin = tr.p1;
                line_intersec.direction = v;
                return true;
            }
            std::cout << "we are here";
            return false;
        }
        else
        {
            std::cout << "cheto is invalid" << std::endl;
        }
 
    }
    else
    {
        std::cout << "plane or one of triangles invalid" << std::endl;
    }
    return false;
} 

/* Check whether P and Q lie on the same side of line AB */
double Side(const Point& p, const Point& q, const Point& a, const Point& b)
{
    double z1 = (b.x - a.x) * (p.y - a.y) - (p.x - a.x) * (b.y - a.y);
    double z2 = (b.x - a.x) * (q.y - a.y) - (q.x - a.x) * (b.y - a.y);
    return z1 * z2;
}

bool LineSegmentIntersectTriangle(const Point& p0, const Point& p1, const Triangle& tr)
{

/* Check whether segment P0P1 intersects with triangle t0t1t2 */

    /* Check whether segment is outside one of the three half-planes
     * delimited by the triangle. */
    double f1 = Side(p0, tr.p3, tr.p1, tr.p2), f2 = Side(p1, tr.p3, tr.p1, tr.p2);
    double f3 = Side(p0, tr.p1, tr.p2, tr.p3), f4 = Side(p1, tr.p1, tr.p2, tr.p3);
    double f5 = Side(p0, tr.p2, tr.p3, tr.p1), f6 = Side(p1, tr.p2, tr.p3, tr.p1);
    /* Check whether triangle is totally inside one of the two half-planes
     * delimited by the segment. */
    double f7 = Side(tr.p1, tr.p2, p0, p1);
    double f8 = Side(tr.p2, tr.p3, p0, p1);
    tr.print_Triangle();
    printf("we are here but why\n");
    std::cout << f1 << " " << f2  << " " << f3 << " " << f4 << " " << f5 << " " << f6  << " " << f7 << " " << f8 << std::endl;
      /* If segment is strictly outside triangle, or triangle is strictly
     * apart from the line, we're not intersecting */
    if ((f1 < 0 && f2 < 0) || (f3 < 0 && f4 < 0) || (f5 < 0 && f6 < 0)
          || (f7 > 0 && f8 > 0))
        return false;
    printf("here\n");
    /* If segment is aligned with one of the edges, we're overlapping */
    if ((f1 == 0 && f2 == 0) || (f3 == 0 && f4 == 0) || (f5 == 0 && f6 == 0))
        return false;
    printf(" orrr here\n");
    /* If segment is outside but not strictly, or triangle is apart but
     * not strictly, we're touching */
    if ((f1 <= 0 && f2 <= 0) || (f3 <= 0 && f4 <= 0) || (f5 <= 0 && f6 <= 0)
          || (f7 >= 0 && f8 >= 0))
        return true;
    printf("matbe\n");
    /* If both segment points are strictly inside the triangle, we
     * are not intersecting either */
    // if (f1 > 0 && f2 > 0 && f3 > 0 && f4 > 0 && f5 > 0 && f6 > 0)
    //     return false;

    /* Otherwise we're intersecting with at least one edge */
    return true;

}

Point Coords3dTo2d(const Point& p, const Vect& normal)
{
    double L = std::sqrt(pow(normal.a, 2) + pow(normal.b, 2) + pow(normal.c, 2)); // length of a normal vector
    std::cout << " L is " << L << std::endl;
    std::cout << " L2 is " << (pow(L, 2) * sqrt(1 - normal.c * normal.c / L / L)) << std::endl;
    if (fabs((pow(L, 2) * sqrt(1 - normal.c * normal.c / L / L))) < epsilon)
    {
        return Point(p.x, p.y, p.z);
    }
    double x, y, z;
    x = p.x * (normal.a * normal.c) / (pow(L, 2) * sqrt(1 - normal.c * normal.c / L / L)) + 
        p.y * (normal.b * normal.c) / (pow(L, 2) * sqrt(1 - normal.c * normal.c / L / L)) -
        p.z * (sqrt(1 - normal.c * normal.c / L / L));
    y = -p.x * (normal.b / (L * sqrt(1 - normal.c * normal.c / L / L))) +
        p.y * (normal.a / (L * sqrt(1 - normal.c * normal.c / L / L)));
    z = p.x * normal.a / L + p.y * normal.b / L + p.z * normal.c / L;
    std::cout << "z is " << z << std::endl;
    Point res(x, y, z);
    return res;
}
// }
// bool LineIntersectTriangle(const Line& l, const Triangle& tr)
// {
//     Vect edge1(tr.p1, tr.p2);
//     Vect edge2(tr.p1, tr.p3);

//     Vect ray_cross_e2 = Cross(l.direction, edge2);
//     double det = Dot(edge1, ray_cross_e2);

//     if (det > -epsilon && det < epsilon)
//         return false;    // This ray is parallel to this triangle.
//     std::cout << "her";

//     double inv_det = 1.0 / det;
//     Vect s(tr.p1, l.origin);
//     double u = inv_det * Dot(s, ray_cross_e2);

//     if (u < 0 || u > 1)
//         return false;
//     std::cout << "no";
//     Vect s_cross_e1 = Cross(s, edge1);
//     double v = inv_det * Dot(l.direction, s_cross_e1);

//     if (v < 0 || u + v > 1)
//         return false;
//     std::cout << "yes";
//     double t = inv_det * Dot(edge2, s_cross_e1);
//     const Vect vec = l.direction * t;
//     std::cout << t << std::endl;
//     if (t > epsilon) // ray intersection
//     {
//         return true;
//     }
//     else if (t < epsilon && t > -epsilon)
//     {
//         return true;
//     }
//      // This means that there is a line intersection but not a ray intersection.
//     return false;
//     //return true;
// }


struct line2d 
{
    double a, b, c;

	line2d() {}
	line2d(Point p, Point q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = - a * p.x - b * p.y;
		norm();
	}
 
	void norm() {
		double z = sqrt (a*a + b*b);
		if (abs(z) > epsilon)
			a /= z,  b /= z,  c /= z;
	}
 
	double dist(Point p) const {
		return a * p.x + b * p.y + c;
	}
};
 
double det(double a, double b,double c, double d)  
{
    return (a * d - b * c);
} 

inline bool betw(double l, double r, double x) {
	return std::min(l,r) <= x + epsilon && x <= std::max(l,r) + epsilon;
}
 
inline bool intersect_1d(double a, double b, double c, double d) {
	if (a > b)  std::swap(a, b);
	if (c > d)  std::swap(c, d);
	return std::max(a, c) <= std::min(b, d) + epsilon;
}
 
bool intersect (Point a, Point b, Point c, Point d) {
	if (! intersect_1d (a.x, b.x, c.x, d.x) || ! intersect_1d (a.y, b.y, c.y, d.y))
		return false;
	line2d m(a, b);
	line2d n(c, d);
	double zn = det(m.a, m.b, n.a, n.b);
    Point left, right;
	if (abs (zn) < epsilon) {
		if (abs (m.dist (c)) > epsilon || abs (n.dist (a)) > epsilon)
			return false;
		if (b < a)  std::swap(a, b);
		if (d < c)  std::swap(c, d);
		left = std::max(a, c);
		right = std::min(b, d);
		return true;
	}
	else {
		left.x = right.x = - det (m.c, m.b, n.c, n.b) / zn;
		left.y = right.y = - det (m.a, m.c, n.a, n.c) / zn;
		return betw (a.x, b.x, left.x)
			&& betw (a.y, b.y, left.y)
			&& betw (c.x, d.x, left.x)
			&& betw (c.y, d.y, left.y);
	}
}

bool RecursiveComparison(const double& a, const double& b, const double& c, const double& d)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return true;
            }
            else if (c == d)
            {
                return true;
            }
        }
        else if (b == c && c == d)
        {
            return true;
        }
    }
    return false;
}

bool IsPlanesTheSame(const Plane& pl1, const Plane& pl2)
{
    if (pl1.a == 0 && pl2.a == 0|| pl1.b == 0 && pl2.b == 0|| pl1.c == 0 && pl2.c == 0|| pl1.d == 0 && pl2.d == 0)
    {
        double a = 0, b = 0, c = 0, d = 0;
        
        if (pl1.a != 0)
        {
            a = pl2.a / pl1.a;
        }
        if (pl1.b != 0)
        {
            b = pl2.b / pl1.b;
        }
        if (pl1.c != 0)
        {
            c = pl2.c / pl1.c;
        }
        if (pl1.d != 0)
        {
            d = pl2.d / pl1.d;
        }
        std::cout << a << b << c << d;
        if (RecursiveComparison(a, b, c, d))
        {
            return true;
        }
        else
        {
            std::swap(a, b);
            if (RecursiveComparison(a, b, c, d))
            {
                return true;
            }
            else
            {
                std::swap(a, c);
                if (RecursiveComparison(a, b, c, d))
                {
                    return true;
                }
                else
                {
                    std::swap(a, d);
                    if (RecursiveComparison(a, b, c, d))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool InternalIsDegenerateTriangleIntersectsDegenerateTriangle(
    const Point& p1, 
    const Point& p2, 
    const Point& p3, 
    const Point& p4)
{
    Plane pl1(p1, p2, p3);
    Plane pl2(p1, p2, p4);
    printf("suda");
    pl1.print_plane();
    pl2.print_plane();
    
    if (IsPlanesTheSame(pl1, pl2))
    {
        printf("not the same\n");
        // std::cout << p1.count_distance(p3) << " " << p1.count_distance(p4) << std::endl;
        // // TODO assert if distance < 0
        // if (p1.count_distance(p3) > 0 || p1.count_distance(p4) > 0)
        // {
        //     return true;
        // }
        Point p1_new2d, p2_new2d, p3_new2d, p4_new2d;
        Vect plane_normal(pl1.a, pl1.b, pl1.c);
        p1_new2d = Coords3dTo2d(p1, plane_normal);
        p2_new2d = Coords3dTo2d(p2, plane_normal);
        p3_new2d = Coords3dTo2d(p3, plane_normal);
        p4_new2d = Coords3dTo2d(p4, plane_normal);
        if (intersect(p1_new2d, p2_new2d, p3_new2d, p4_new2d))
        {
            return true;
        }
    }
    return false;
}

// two lines
bool IsDegenerateTriangleIntersectsDegenerateTriangle(const Triangle& tr1, const Triangle& tr2)
{
    // FIXME write a method pof tr.class
    double L112 = fabs(tr1.p1.x - tr1.p2.x) + fabs(tr1.p1.y - tr1.p2.y) + fabs(tr1.p1.z - tr1.p2.z);
    double L123 = fabs(tr1.p3.x - tr1.p2.x) + fabs(tr1.p3.y - tr1.p2.y) + fabs(tr1.p3.z - tr1.p2.z);
    double L113 = fabs(tr1.p1.x - tr1.p3.x) + fabs(tr1.p1.y - tr1.p3.y) + fabs(tr1.p1.z - tr1.p3.z);
    double L212 = fabs(tr2.p1.x - tr2.p2.x) + fabs(tr2.p1.y - tr2.p2.y) + fabs(tr2.p1.z - tr2.p2.z);
    double L223 = fabs(tr2.p3.x - tr2.p2.x) + fabs(tr2.p3.y - tr2.p2.y) + fabs(tr2.p3.z - tr2.p2.z);
    double L213 = fabs(tr2.p1.x - tr2.p3.x) + fabs(tr2.p1.y - tr2.p3.y) + fabs(tr2.p1.z - tr2.p3.z);
    if (L112 >= L123 && L112 >= L113)
    {   
        if (L212 >= L123 && L212 >= L213)
        {
            if (InternalIsDegenerateTriangleIntersectsDegenerateTriangle(tr1.p1, tr1.p2, tr2.p1, tr2.p2))
            {
                return true;
            }
        }
        else if (L223 > L212 && L223 >= L213)
        {
            if (InternalIsDegenerateTriangleIntersectsDegenerateTriangle(tr1.p1, tr1.p2, tr2.p2, tr2.p3))
            {
                return true;
            }
        }
        else
        {
            if (InternalIsDegenerateTriangleIntersectsDegenerateTriangle(tr1.p1, tr1.p2, tr2.p1, tr2.p3))
            {
                return true;
            }
        }
    }
    else if (L123 > L112 && L123 >= L113)
    {
        if (L212 >= L123 && L212 >= L213)
        {
            if (InternalIsDegenerateTriangleIntersectsDegenerateTriangle(tr1.p2, tr1.p3, tr2.p1, tr2.p2))
            {
                return true;
            }
        }
        else if (L223 > L212 && L223 >= L213)
        {
            if (InternalIsDegenerateTriangleIntersectsDegenerateTriangle(tr1.p2, tr1.p3, tr2.p2, tr2.p3))
            {
                return true;
            }
        }
        else
        {
            if (InternalIsDegenerateTriangleIntersectsDegenerateTriangle(tr1.p2, tr1.p3, tr2.p1, tr2.p3))
            {
                return true;
            }
        }
    }
    else
    {
        if (L212 >= L123 && L212 >= L213)
        {
            if (InternalIsDegenerateTriangleIntersectsDegenerateTriangle(tr1.p1, tr1.p3, tr2.p1, tr2.p2))
            {
                return true;
            }
        }
        else if (L223 > L212 && L223 >= L213)
        {
            if (InternalIsDegenerateTriangleIntersectsDegenerateTriangle(tr1.p1, tr1.p3, tr2.p2, tr2.p3))
            {
                return true;
            }
        }
        else
        {
            if (InternalIsDegenerateTriangleIntersectsDegenerateTriangle(tr1.p1, tr1.p3, tr2.p1, tr2.p3))
            {
                return true;
            }
        }
    }
    return false;
}


// one line and one triangle
bool IsDegenerateTriangleIntersectsTriangle(const Triangle& tr1, const Triangle& tr2, const Vect& plane_normal)
{
    double L12 = fabs(tr1.p1.x - tr1.p2.x) + fabs(tr1.p1.y - tr1.p2.y) + fabs(tr1.p1.z - tr1.p2.z);
    double L23 = fabs(tr1.p3.x - tr1.p2.x) + fabs(tr1.p3.y - tr1.p2.y) + fabs(tr1.p3.z - tr1.p2.z);
    double L13 = fabs(tr1.p1.x - tr1.p3.x) + fabs(tr1.p1.y - tr1.p3.y) + fabs(tr1.p1.z - tr1.p3.z);
    Point tr2p1_new2d, tr2p2_new2d, tr2p3_new2d;
    tr2p1_new2d = Coords3dTo2d(tr2.p1, plane_normal);
    tr2p2_new2d = Coords3dTo2d(tr2.p2, plane_normal);
    tr2p3_new2d = Coords3dTo2d(tr2.p3, plane_normal);
    Triangle tr3(tr2p1_new2d, tr2p2_new2d, tr2p3_new2d);
    if (L12 >= L23 && L12 >= L13)
    {
        // точки 1 и 2 самые удаленные 
        Point p1, p2;
        p1 = Coords3dTo2d(tr1.p1, plane_normal);
        p2 = Coords3dTo2d(tr1.p2, plane_normal);
        if (LineSegmentIntersectTriangle(p1, p2, tr3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (L23 > L12 && L23 >= L13)
    {
        // точки 3 и 2 самые удаленные
        Point p3, p2;
        p2 = Coords3dTo2d(tr1.p2, plane_normal);
        p3 = Coords3dTo2d(tr1.p3, plane_normal); 
        if (LineSegmentIntersectTriangle(p3, p2, tr3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        // точки 1 и 3 самые удаленные 
        Point p1, p3;
        p1 = Coords3dTo2d(tr1.p1, plane_normal);
        p3 = Coords3dTo2d(tr1.p3, plane_normal);
        if (LineSegmentIntersectTriangle(p1, p3, tr3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


bool IsPointInsideTriangle(const Point& p, const Triangle& tr)
{
    
        // Vect v5(tr.p1, tr.p2);
        // Vect v6(tr.p2, tr.p3);
        // Vect v7;
        //v7 = Cross(v5, v6);
        // 
        // if (volume_of_tetrahedrom == volume_of_triangle)
        // {
        //     return true;
        // }        
    
    /* if the volume of tetrahedrom based on 4 points != 0 && != volume of triangle tr */
    // return false;
    Point p0(0, 0, 0);
    Vect v0(p0, p);
    Vect a(p0, tr.p1);
    Vect b(p0, tr.p2);
    Vect c(p0, tr.p3);
    tr.print_Triangle();
    // // Move the triangle so that the point becomes the 
    // // triangles origin
    a = a - v0;
    b = b - v0;
    c = c - v0;
    a.Vect_Print();
    // Compute the normal vectors for triangles:
    // u = normal of PBC
    // v = normal of PCA
    // w = normal of PAB

    Vect u = Cross(b, c);
    Vect v = Cross(c, a);
    Vect w = Cross(a, b);

    // Test to see if the normals are facing 
    // the same direction, return false if not
    if (Dot(u, v) < 0.0) 
    {
        return false;
    }
    if (Dot(u, w) < 0.0) 
    {
        return false;
    }

    /* если проекция точки на треугольнике лежит на треугольнике*/
    Plane pl(tr.p1, tr.p2, tr.p3);
    if (fabs(pl.a * p.x + pl.b * p.y + pl.c * p.z + pl.d) < epsilon)
    {
        return true;
    }
    // else
    // {
    return false;
    // 
    // Vect v4;
    
    // v4 = Cross(v2, v3);
    // v4.Vect_Print();
    // v1.Vect_Print();
    // double volume_of_tetrahedrom = Dot(v1, v4);

    // Vect v5(tr.p2, tr.p1);
    // Vect v6(tr.p2, tr.p3);
    // double volume_of_triangle = 0.5 * sqrt(pow(v5.b * v6.c - v5.c * v6.b, 2) + pow(v5.c * v6.a - v5.a * v6.c, 2) + pow(v5.a * v6.b - v5.b * v6.a, 2));
    // std::cout << volume_of_triangle << " " << volume_of_tetrahedrom << std::endl;
    // if (volume_of_tetrahedrom != volume_of_triangle)
    // {
    //     return false;
    // }

    // return true;
    // // All normals facing the same way, return true
    // return true;
}

bool TriangleIntersectTriangle(const Triangle& tr1, const Triangle& tr2)
{
    Plane pl(tr1.p1, tr1.p2, tr1.p3);
    Vect plane_normal(pl.a, pl.b, pl.c);
    plane_normal.Vect_Print();
    Plane pl2(tr2.p1, tr2.p2, tr2.p3);
    Vect plane2_normal(pl2.a, pl2.b, pl2.c);
    plane2_normal.Vect_Print();
    if (tr1.p1 == tr1.p2 && tr1.p1 == tr1.p3)
    {
        if (tr2.p1 == tr1.p1 || tr2.p2 == tr1.p1 || tr2.p3 == tr1.p1 || IsPointInsideTriangle(tr1.p1, tr2))
        {
            return true;
        }
        if (tr2.p1 == tr2.p2)
        {
            Plane pl(tr1.p1, tr2.p1, tr2.p3);
            if (pl.d == LineValue)
            {
                return true;
            }
        }
        else if (tr2.p1 == tr2.p3)
        {
            Plane pl(tr1.p1, tr2.p2, tr2.p3);
            if (pl.d == LineValue)
            {
                return true;
            }            
        }
        else if (tr2.p2 == tr2.p3)
        {
            Plane pl(tr1.p1, tr2.p1, tr2.p3);
            if (pl.d == LineValue)
            {
                return true;
            }            
        }
    }
    else if (tr2.p1 == tr2.p2 && tr2.p1 == tr2.p3)
    {
        if (!IsPointInsideTriangle(tr2.p1, tr1))
        {
            std::cout << "stm" ;
        }
        if (tr2.p1 == tr1.p1 || tr2.p1 == tr1.p2 || tr2.p1 == tr1.p3 || IsPointInsideTriangle(tr2.p1, tr1))
        {
            return true;
        }
        if (tr1.p1 == tr1.p2)
        {
            Plane pl(tr2.p1, tr1.p1, tr1.p3);
            if (pl.d == LineValue)
            {
                return true;
            }
        }
        else if (tr1.p1 == tr1.p3)
        {
            Plane pl(tr2.p1, tr1.p2, tr1.p3);
            if (pl.d == LineValue)
            {
                return true;
            }            
        }
        else if (tr1.p2 == tr1.p3)
        {
            Plane pl(tr2.p1, tr1.p1, tr1.p3);
            if (pl.d == LineValue)
            {
                return true;
            }            
        }
    }
    else if (pl.d == LineValue && pl2.d == LineValue)
    {
        if (IsDegenerateTriangleIntersectsDegenerateTriangle(tr1, tr2))
        {
            return true;
        }
    }
    else if (pl.d == LineValue)
    {
        if (IsDegenerateTriangleIntersectsTriangle(tr1, tr2, plane2_normal))
        {
            return true;
        }
    }
    else if (pl2.d == LineValue)
    {
        if (IsDegenerateTriangleIntersectsTriangle(tr2, tr1, plane_normal))
        {
            return true;
        }
    }
    else 
    {
        Point point_intersec;
        printf("ahahaha\n");
        Line line_intersec;
        bool intersec = IntersectionOfTriangleAndPlane(pl, tr2, point_intersec, line_intersec);
        if (point_intersec.valid())
        {
            std::cout << "Point intersection" << std::endl;
            if (IsPointInsideTriangle(point_intersec, tr1))
            {
                return true;
            }
        }
        else if (line_intersec.valid())
        {
            //if line intersects triangle
            std::cout << "Line intersection" << std::endl;
            line_intersec.print_Line();
            Point p1; // конец отрезка, по которому пересекается плоскость с треугольником
            p1 = line_intersec.origin + line_intersec.direction;
            line_intersec.origin = Coords3dTo2d(line_intersec.origin, plane_normal);
            line_intersec.origin.print_Point();
            p1 = Coords3dTo2d(p1, plane_normal);
            Point p2, p3, p4; // новые координаты треугольника в 2д координатах
            p2 = Coords3dTo2d(tr1.p1, plane_normal);
            p3 = Coords3dTo2d(tr1.p2, plane_normal);
            p4 = Coords3dTo2d(tr1.p3, plane_normal);
            Triangle tr3(p2, p3, p4);
            p1.print_Point();
            if (tr1.p1 == tr2.p1 || tr1.p1 == tr2.p2 || tr1.p1 == tr2.p3 ||
                tr1.p2 == tr2.p1 || tr1.p2 == tr2.p2 || tr1.p2 == tr2.p3 ||
                tr1.p3 == tr2.p1 || tr1.p3 == tr2.p2 || tr1.p3 == tr2.p3)
            {
                return true;
            }
            else if (LineSegmentIntersectTriangle(line_intersec.origin, p1, tr3))
            {
                return true;
            }
        }
        else if (intersec)
        {
            if (tr1.p1 == tr2.p1 || tr1.p1 == tr2.p2 || tr1.p1 == tr2.p3 ||
                tr1.p2 == tr2.p1 || tr1.p2 == tr2.p2 || tr1.p2 == tr2.p3 ||
                tr1.p3 == tr2.p1 || tr1.p3 == tr2.p2 || tr1.p3 == tr2.p3)
            {
                return true;
            }
            else
            {
                Point p1(tr1.p1);
                Point p2(tr1.p2);
                Point p3(tr1.p3);
                Vect v1(p1, p2);
                Point p1_new2d, p2_new2d, p3_new2d;
                Point tr2p1_new2d, tr2p2_new2d, tr2p3_new2d;
                p1_new2d = Coords3dTo2d(p1, plane_normal);
                p2_new2d = Coords3dTo2d(p2, plane_normal);
                p3_new2d = Coords3dTo2d(p3, plane_normal);
                tr2p1_new2d = Coords3dTo2d(tr2.p1, plane_normal);
                tr2p2_new2d = Coords3dTo2d(tr2.p2, plane_normal);
                tr2p3_new2d = Coords3dTo2d(tr2.p3, plane_normal);
                Triangle tr3(tr2p1_new2d, tr2p2_new2d, tr2p3_new2d);
                if (LineSegmentIntersectTriangle(p1_new2d, p2_new2d, tr3))
                {
                    return true;
                }
                else
                {
                    if (LineSegmentIntersectTriangle(p2_new2d, p3_new2d, tr3))
                    {
                        return true;
                    }
                    else
                    {
                        if (LineSegmentIntersectTriangle(p1_new2d, p3_new2d, tr3))
                        {
                            return true;
                        }
                    }
                }
            }    
        }
    }
    return false;
}


} /* namespace geometry */




