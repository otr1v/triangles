#include "geometry.hpp"


geometry::Triangle BuildTriangle()
{
    double x1, x2, x3, y1, y2, y3, z1, z2, z3;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
    geometry::Point p4(x1, y1, z1);
    geometry::Point p5(x2, y2, z2);
    geometry::Point p6(x3, y3, z3);
    geometry::Triangle tr(p4, p5, p6);
    return tr;
}

int main()
{
    geometry::Point p1(1, 1, 0);
    geometry::Point p2(1, -1 , 0);
    geometry::Point p3(2, 0, 1);
   // geometry::Vect v(2, 1, 3);
    geometry::Line line(p1, p2);
    geometry::Point p0(0, 0, 0);
    geometry::Point p(1, 1, 1);
    geometry::Vect v(-4, 0, 0);
    geometry::Line l1(p0, -v);
   // line.print_Line();
    geometry::Triangle tr(p1, p2, p3);
    geometry::Triangle tr2(p1, p2, p3);
    geometry::Triangle tr1(p1, p2, p3);
    geometry::Triangle tr3(p1, p2, p3);
    geometry::Triangle tr4(p1, p2, p3);
    geometry::Triangle tr5(p1, p2, p3);
    geometry::Triangle tr6(p1, p2, p3);
    //tr.print_Triangle();
    geometry::Plane pl(p1, p2, p3);
    geometry::Line l(p1, v);
   // geometry::LineIntersectPlane(l, pl, p2);
    //p2.print_Point();
    tr1 = BuildTriangle();
    //tr.print_Triangle();
    tr2 = BuildTriangle();
    //tr3 = BuildTriangle();
    // tr4 = BuildTriangle();
    // tr5 = BuildTriangle();
    // tr6 = BuildTriangle();
    std::list<geometry::Triangle> l0;
    l0.emplace_back(tr1);
    l0.emplace_back(tr2);
    //l0.emplace_back(tr3);
    // l0.emplace_back(tr4);
    // l0.emplace_back(tr5);
    // l0.emplace_back(tr6);
    // if (geometry::TriangleIntersectTriangle(tr1, tr2))
    // {
    //     std::cout << "AAAAAAAAAAAAAAAAA" << std::endl;
    // }
    int i = 0;
    for (auto it = l0.begin(); it != l0.end(); it++)
    {
        int j = 0;
        for (auto it1 = it; it1 != l0.end(); it1++)
        {
            if (!j)
            {
                j = 1;
            }
            else
            {
                if (geometry::TriangleIntersectTriangle(*it, *it1))
                {
                    std::cout << "INTERSECTS " << i + 1 << " with " << j  + 1<< std::endl;
                }
                //std::cout << "INTERSECTS " << i + 1 << " with " << j  + 1<< std::endl;
                j++;
            }
        }
        i++;
    }
    // if( geometry::LineIntersectTriangle(l1, tr))
    // {
    //     std::cout << "pobeda" << std::endl;
    // }
    // l1.print_Line();
    // pl.print_plane();
    // if (v.valid())
    // {
    //     tr.print_Triangle();
    //     v.Vect_Print();
    // }
    return 0;
}