#pragma once

#include "head.hpp"

namespace geometry
{

double epsilon = 0.00001;
double LineLiesOnPlane = 0xBAABDAD;

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
        x = x - p1.x;
        y = y - p1.y;
        z = z - p1.z;
        return *this;
    }

    bool operator==(const Point& p1) const
    {
        if (fabs(p1.x - x) < epsilon && fabs(p1.y - y) < epsilon && fabs(p1.z - z) < epsilon)
        {
            return true;
        }
        return false;
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
            res.x = d / a;
        }
        else if (b != 0)
        {
            res.x = 0;
            res.z = 0;
            res.y = d / b;
        }
        else if (c != 0)
        {
            res.x = 0;
            res.y = 0;
            res.z = d / c;
        }
        else
        {
            std::cout << "error" << std::endl;
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
    bool is_triag_valid = tr.valid();
    pl.print_plane();
    if (is_plane_valid && is_triag_valid)
    {
        double dot1 = InvalidValue, dot2 = InvalidValue, dot3 = InvalidValue;
        Vect plane_normal(pl.a, pl.b, pl.c);
        Point point_on_plane = pl.generate_point_on_plane();
        Vect v1(point_on_plane, tr.p1);
        Vect v2(point_on_plane, tr.p2);
        Vect v3(point_on_plane, tr.p3);
        if (plane_normal.valid() &&
            v1.valid() &&
            v2.valid() &&
            v3.valid())
        {
            dot1 = Dot(plane_normal, v1);
            dot2 = Dot(plane_normal, v2);
            dot3 = Dot(plane_normal, v3);
            if (fabs(dot1) < epsilon) dot1 = 0;
            if (fabs(dot2) < epsilon) dot2 = 0;
            if (fabs(dot3) < epsilon) dot3 = 0;
            double d1d2, d1d3;
            d1d2 = dot1 * dot2;
            d1d3 = dot1 * dot3;
            if (d1d2 > 0.0 && d1d3 > 0.0) 
            {
                // all points above plane
                std::cout << "all points above plain" << std::endl;
                return false;
            } 
            else if (d1d2 < 0.0 && d1d3 < 0.0) 
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

bool LineIntersectTriangle(const Line& l, const Triangle& tr)
{
    Vect edge1(tr.p1, tr.p2);
    Vect edge2(tr.p1, tr.p3);

    Vect ray_cross_e2 = Cross(l.direction, edge2);
    double det = Dot(edge1, ray_cross_e2);

    if (det > -epsilon && det < epsilon)
        return false;    // This ray is parallel to this triangle.
    std::cout << "her";

    double inv_det = 1.0 / det;
    Vect s(tr.p1, l.origin);
    double u = inv_det * Dot(s, ray_cross_e2);

    if (u < 0 || u > 1)
        return false;
    std::cout << "no";
    Vect s_cross_e1 = Cross(s, edge1);
    double v = inv_det * Dot(l.direction, s_cross_e1);

    if (v < 0 || u + v > 1)
        return false;
    std::cout << "yes";
    double t = inv_det * Dot(edge2, s_cross_e1);
    const Vect vec = l.direction * t;
    std::cout << t << std::endl;
    if (t > epsilon) // ray intersection
    {
        return true;
    }
    else if (t < epsilon && t > -epsilon)
    {
        return true;
    }
     // This means that there is a line intersection but not a ray intersection.
    return false;
    //return true;
}

bool IsPointInsideTriangle(const Point& p, const Triangle& tr)
{
    Point p0(0, 0, 0);
    Vect v0(p0, p);
    Vect a(p0, tr.p1);
    Vect b(p0, tr.p2);
    Vect c(p0, tr.p3);

    // Move the triangle so that the point becomes the 
    // triangles origin
    a = a - v0;
    b = b - v0;
    c = c - v0;

    // Compute the normal vectors for triangles:
    // u = normal of PBC
    // v = normal of PCA
    // w = normal of PAB

    Vect u = Cross(b, c);
    Vect v = Cross(c, a);
    Vect w = Cross(a, b);

    // Test to see if the normals are facing 
    // the same direction, return false if not
    if (Dot(u, v) < 0.0) {
        return false;
    }
    if (Dot(u, w) < 0.0) {
        return false;
    }

    // All normals facing the same way, return true
    return true;
}

bool TriangleIntersectTriangle(const Triangle& tr1, const Triangle& tr2)
{
    Plane pl(tr1.p1, tr1.p2, tr1.p3);
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
        else
        {
            return false;
        }
    }
    else if (line_intersec.valid())
    {
        //if line intersects triangle
        std::cout << "Line intersection" << std::endl;
        Point p1; // конец отрезка, по которому пересекается плоскость с треугольником
        p1 = line_intersec.origin + line_intersec.direction;
        Line l1(line_intersec.origin, line_intersec.direction);
        Line l2(p1, -line_intersec.direction);
        if (LineIntersectTriangle(l1, tr2) && LineIntersectTriangle(l2, tr2))
        {
            return true;
        } 
        else
        {
            return false;
        }
    }
    else if (intersec)
    {
        // TODO 2d intersection
        // если есть совпадающие точки и запустить дважды рей лайн интерсекшн
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
            Line l1(p1, v1);
            Line l2(p2, -v1);
            if (LineIntersectTriangle(l1, tr2) && LineIntersectTriangle(l2, tr2))
            {
                return true;
            }
            else
            {
                Vect v2(p2, p3);
                Line l3(p2, v2);
                Line l4(p3, -v2);
                if (LineIntersectTriangle(l3, tr2) && LineIntersectTriangle(l4, tr2))
                {
                    return true;
                }
                else
                {
                    Vect v3(p1, p3);
                    Line l5(p1, v3);
                    Line l6(p3, -v3);
                    if (LineIntersectTriangle(l5, tr2) && LineIntersectTriangle(l6, tr2))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            
        }
    }
    return false;
}


} /* namespace geometry */


// POINT IN TRIANGLE::
/*bool pointInTriangle (Point p, Point a, Point b, Point c)
{
  return ((p.classify (a, b) != LEFT) &&
        (p.classify(b, c) != LEFT) &&
        (p.classify(c, a) != LEFT));
}

enum {LEFT,  RIGHT,  BEYOND,  BEHIND, BETWEEN, ORIGIN, DESTINATION};
//    СЛЕВА, СПРАВА, ВПЕРЕДИ, ПОЗАДИ, МЕЖДУ, НАЧАЛО, КОНЕЦ

int Point::classify(Point &p0, Point &pl)
{
  Point p2 = *this;
  Point a = p1 - pO;
  Point b = p2 - pO;
  double sa = a. x * b.y - b.x * a.y;
  if (sa > 0.0)
    return LEFT;
  if (sa < 0.0)
    return RIGHT;
  if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0))
    return BEHIND;
  if (a.length() < b.length())
    return BEYOND;
  if (pO == p2)
    return ORIGIN;
  if (p1 == p2)
    return DESTINATION;
  return BETWEEN;
}*/