#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "geometry.hpp"

TEST(triangle, intersection_2d_1) {
  geometry::Point t1p1 {0, 0, 0};
  geometry::Point t1p2 {0, 2, 0};
  geometry::Point t1p3 {0, 0, 0};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {2, 2, 0};
  geometry::Point t2p3 {2, 0, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_2d_2) {
  geometry::Point t1p1 {0, 0, 0};
  geometry::Point t1p2 {0, 2, 0};
  geometry::Point t1p3 {0, 0, 0};
  geometry::Point t2p1 {3, 0, 0};
  geometry::Point t2p2 {5, 2, 0};
  geometry::Point t2p3 {6, 0, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_2d_3) {
  geometry::Point t1p1 {0, 0, 0};
  geometry::Point t1p2 {0, 2, 0};
  geometry::Point t1p3 {0, 0, 0};
  geometry::Point t2p1 {-1, 0, 0};
  geometry::Point t2p2 {3, 2, 0};
  geometry::Point t2p3 {6, 2, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_2d_4) {
  geometry::Point t1p1 {0.4, -5, 0};
  geometry::Point t1p2 {1, 2, 0};
  geometry::Point t1p3 {5, 0, 0};
  geometry::Point t2p1 {-1, 0, 0};
  geometry::Point t2p2 {3, 2, 0};
  geometry::Point t2p3 {6, 2, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_2d_5) {
  geometry::Point t1p1 {1, 0, 1};
  geometry::Point t1p2 {1, 0, 5};
  geometry::Point t1p3 {5, 0, 4};
  geometry::Point t2p1 {5, 0, 2};
  geometry::Point t2p2 {2.1, 0, 8};
  geometry::Point t2p3 {1, 0, -1};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_point_1) {
  geometry::Point t1p1 {0, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0.5, 0.5};
  geometry::Point t2p2 {0, 0.5, 0.5};
  geometry::Point t2p3 {0, 0.5, 0.5};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_point_2) {
  geometry::Point t1p1 {0, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0.25, 0.33};
  geometry::Point t2p2 {0, 0.25, 0.33};
  geometry::Point t2p3 {0, 0.25, 0.33};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_point_3) {
  geometry::Point t1p1 {0, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0.1, 0.25, 0.33};
  geometry::Point t2p2 {0.1, 0.25, 0.33};
  geometry::Point t2p3 {0.1, 0.25, 0.33};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_point_4) {
  geometry::Point t1p1 {0, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {0, 0, 0};
  geometry::Point t2p3 {0, 0, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_point_5) {
  geometry::Point t1p1 {0, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {0, 0, 0};
  geometry::Point t2p3 {0, 0, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_point_6) {
  geometry::Point t1p1 {2, -2, -1};
  geometry::Point t1p2 {1, 1, -1};
  geometry::Point t1p3 {2, 2, 1};
  geometry::Point t2p1 {2, 0, 0};
  geometry::Point t2p2 {2, 0, 0};
  geometry::Point t2p3 {2, 0, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_line_segm_1) {
  geometry::Point t1p1 {1, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {0, 0, 0};
  geometry::Point t2p3 {1, 1, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_line_segm_2) {
  geometry::Point t1p1 {1, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {0, 0, 0};
  geometry::Point t2p3 {1, 1, 1};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_line_segm_3) {
  geometry::Point t1p1 {1, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {0, 0, 0};
  geometry::Point t2p3 {-1, 1, 1};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_line_segm_4) {
  geometry::Point t1p1 {1, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {0, 0, 0};
  geometry::Point t2p3 {0.25, 0.25, 0.25};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_line_segm_5) {
  geometry::Point t1p1 {5, 3, 2};
  geometry::Point t1p2 {1, 1, 0};
  geometry::Point t1p3 {-2, 3, 1};
  geometry::Point t2p1 {6, 3, 2};
  geometry::Point t2p2 {1, 3, 0};
  geometry::Point t2p3 {1, 3, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_line_segm_6) {
  geometry::Point t1p1 {5, 3, 2};
  geometry::Point t1p2 {1, 1, 0};
  geometry::Point t1p3 {-2, 3, 1};
  geometry::Point t2p1 {6, 2, 7};
  geometry::Point t2p2 {1, 3, 0};
  geometry::Point t2p3 {1, 3, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, triangle_intersection_with_line_segm_7) {
  geometry::Point t1p1 {2, 0, 0};
  geometry::Point t1p2 {0, 2, 0};
  geometry::Point t1p3 {0, 0, 0};
  geometry::Point t2p1 {0.5, 0.5, 0.5};
  geometry::Point t2p2 {0.5, 0.5, 1};
  geometry::Point t2p3 {0.5, 0.5, 1};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}


TEST(triangle, intersection_3d_1) {
  geometry::Point t1p1 {1, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {1, 1, 1};
  geometry::Point t2p3 {-2, 2, 2};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_2) {
  geometry::Point t1p1 {1, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {1, 1, 1};
  geometry::Point t2p3 {-2, 2, 20};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_3) {
  geometry::Point t1p1 {-1, 5, 4};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {1, 1, 1};
  geometry::Point t2p3 {-2, 2, 2};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_4) {
  geometry::Point t1p1 {-1, 5, 4};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {-1, -2, -1};
  geometry::Point t2p2 {-1, -1, -1};
  geometry::Point t2p3 {-2, 2, 2};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_5) {
  geometry::Point t1p1 {2, -3, 7};
  geometry::Point t1p2 {1, 4, 6};
  geometry::Point t1p3 {5, 3, -1};
  geometry::Point t2p1 {1, 1, 1};
  geometry::Point t2p2 {1, 0, 1};
  geometry::Point t2p3 {1, -1, 3};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_6) {
  geometry::Point t1p1 {2, -3, 4};
  geometry::Point t1p2 {1, 4, 6};
  geometry::Point t1p3 {5, 3, -1};
  geometry::Point t2p1 {-1, 5, 2};
  geometry::Point t2p2 {2, -1, 4};
  geometry::Point t2p3 {5, 0, 5};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_7) {
  geometry::Point t1p1 {2.5, 5.234, -4.234};
  geometry::Point t1p2 {1.31, 5.01, -1.14};
  geometry::Point t1p3 {-1.1, -2.4, 5};
  geometry::Point t2p1 {1.5, 2.1, 3.1};
  geometry::Point t2p2 {-1.5, -5.1, 2};
  geometry::Point t2p3 {4.1, 5, 3};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_8) {
  geometry::Point t1p1 {2.2, 5.3, -4.2};
  geometry::Point t1p2 {1, 1, -1};
  geometry::Point t1p3 {2, 2, 2};
  geometry::Point t2p1 {5, 5, 0};
  geometry::Point t2p2 {1, 1, 1};
  geometry::Point t2p3 {-3, 2, 2};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_9) {
  geometry::Point t1p1 {2.2, 5.3, -4.2};
  geometry::Point t1p2 {1, 1, -1};
  geometry::Point t1p3 {2, 2, 2};
  geometry::Point t2p1 {5, 5, 0};
  geometry::Point t2p2 {2, 2, 2};
  geometry::Point t2p3 {-3, 2, 2};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_10) {
  geometry::Point t1p1 {2.2, 5.3, -4.2};
  geometry::Point t1p2 {1, 1, -1};
  geometry::Point t1p3 {-2, -2, -2};
  geometry::Point t2p1 {5, 5, 0};
  geometry::Point t2p2 {1, 1, -1};
  geometry::Point t2p3 {-3, 2, 2};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_11) {
  geometry::Point t1p1 {18, 1, 20};
  geometry::Point t1p2 {9, 7, 1};
  geometry::Point t1p3 {3, 19, 6};
  geometry::Point t2p1 {3, 4, 9};
  geometry::Point t2p2 {9, 4, 16};
  geometry::Point t2p3 {16, 4, 6};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}


TEST(triangle, intersection_3d_12) {
  geometry::Point t1p1 {18, 1, 20};
  geometry::Point t1p2 {9, 7, 1};
  geometry::Point t1p3 {3, 19, 6};
  geometry::Point t2p1 {5, 16, 16};
  geometry::Point t2p2 {19, 3, 16};
  geometry::Point t2p3 {3, 2, 2};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_13) {
  geometry::Point t1p1 {18, 1, 20};
  geometry::Point t1p2 {9, 7, 1};
  geometry::Point t1p3 {3, 19, 6};
  geometry::Point t2p1 {2, 17, 18};
  geometry::Point t2p2 {9, 20, 3};
  geometry::Point t2p3 {14, 6, 14};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_15) {
  geometry::Point t1p1 {18, 1, 20};
  geometry::Point t1p2 {9, 7, 1};
  geometry::Point t1p3 {3, 19, 6};
  geometry::Point t2p1 {12, 7, 6};
  geometry::Point t2p2 {12, 16, 7};
  geometry::Point t2p3 {13, 15, 11};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_16) {
  geometry::Point t1p1 {18, 1, 20};
  geometry::Point t1p2 {9, 7, 1};
  geometry::Point t1p3 {3, 19, 6};
  geometry::Point t2p1 {12, 4, 10};
  geometry::Point t2p2 {17, 20, 13};
  geometry::Point t2p3 {18, 10, 6};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_17) {
  geometry::Point t1p1 {1, 0, 0};
  geometry::Point t1p2 {0, 1, 0};
  geometry::Point t1p3 {0, 0, 1};
  geometry::Point t2p1 {0, 0, 0};
  geometry::Point t2p2 {5, 5, 0};
  geometry::Point t2p3 {5, 5, 10};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_18) {
  geometry::Point t1p1 {0, 0, 0};
  geometry::Point t1p2 {5, 5, 0};
  geometry::Point t1p3 {5, 5, 10};
  geometry::Point t2p1 {0.5, 0, 0};
  geometry::Point t2p2 {0, 0, 0};
  geometry::Point t2p3 {0, 0, 0.5};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}


TEST(triangle, intersection_3d_line_intersection_1) {
  geometry::Point t1p1 {2.5, 5, 0};
  geometry::Point t1p2 {5, 10, 0};
  geometry::Point t1p3 {5, 10, 0};
  geometry::Point t2p1 {-2, 10, 0};
  geometry::Point t2p2 {20, -4, 0};
  geometry::Point t2p3 {20, -4, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_line_intersection_2) {
  geometry::Point t1p1 {2.5, 5, 0};
  geometry::Point t1p2 {5, 10, 0};
  geometry::Point t1p3 {5, 10, 0};
  geometry::Point t2p1 {-20, 10, 0};
  geometry::Point t2p2 {20, -4, 0};
  geometry::Point t2p3 {20, -4, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_line_intersection_3) {
  geometry::Point t1p1 {2.123, -2.52, 0};
  geometry::Point t1p2 {5.31, 141, 0};
  geometry::Point t1p3 {5.31, 141, 0};
  geometry::Point t2p1 {-20, 10, 0};
  geometry::Point t2p2 {20, -50, 0};
  geometry::Point t2p3 {20, -50, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(!geometry::TriangleIntersectTriangle(t1, t2));
}

TEST(triangle, intersection_3d_line_intersection_4) {
  geometry::Point t1p1 {2.123, -2.52, 0};
  geometry::Point t1p2 {5.31, 141, 0};
  geometry::Point t1p3 {5.31, 141, 0};
  geometry::Point t2p1 {-20, 10, 0};
  geometry::Point t2p2 {20, -3, 0};
  geometry::Point t2p3 {20, -3, 0};
  geometry::Triangle t1 {t1p1, t1p2, t1p3};
  geometry::Triangle t2 {t2p1, t2p2, t2p3};

  ASSERT_TRUE(geometry::TriangleIntersectTriangle(t1, t2));
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}