#include <gtest/gtest.h>
#include "Vec3.hpp"

TEST(Vec3Test, DotProduct) {
  Vec3 u{3, 5, 8};
  Vec3 v{2, 7, 1};
  double expected = 49;
  EXPECT_EQ(u.dot(v), expected);
  EXPECT_EQ(v.dot(u), expected);
}

TEST(Vec3Test, CrossProduct) {
  Vec3 u{1, 2, 3};
  Vec3 v{1, 5, 7};
  Vec3 expected{-1, -4, 3};
  EXPECT_EQ(u.cross(v), expected);
}

TEST(Vec3Test, EqualsOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 v2{1, 2, 3};
  Vec3 v3{2, 2, 3};
  EXPECT_TRUE(v1 == v2);
  EXPECT_FALSE(v1 == v3);
}

TEST(Vec3Test, NotEqualsOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 v2{1, 2, 3};
  Vec3 v3{2, 2, 3};
  EXPECT_TRUE(v1 != v3);
  EXPECT_FALSE(v1 != v2);
}

TEST(Vec3Test, NegationOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 v2{-1, -2, -3};
  EXPECT_EQ(-v1, v2);
  EXPECT_EQ(v1, -v2);
}

TEST(Vec3Test, AddOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 v2{1, 1, 1};
  Vec3 expected{2, 3, 4};
  EXPECT_EQ(v1 + v2, expected);
}

TEST(Vec3Test, SubtractOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 expected{0, 1, 2};
  EXPECT_EQ(v1 - Vec3(1, 1, 1), expected);
}

TEST(Vec3Test, MultiplyOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 expected{2, 4, 6};
  EXPECT_EQ(v1 * 2, expected);
  EXPECT_EQ(2 * v1, expected);
}

TEST(Vec3Test, DivideOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 expected{0.5, 1, 1.5};
  EXPECT_EQ(v1 / 2, expected);
}

TEST(Vec3Test, AddAssignmentOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 expected{2, 3, 4};
  v1 += Vec3{1, 1, 1};
  EXPECT_EQ(v1, expected);
}

TEST(Vec3Test, SubtractAssignmentOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 expected{0, 1, 2};
  v1 -= Vec3{1, 1, 1};
  EXPECT_EQ(v1, expected);
}

TEST(Vec3Test, MultiplyAssignmentOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 v2{2, 4, 6};
  v1 *= 2;
  EXPECT_EQ(v1, v2);

  v1 *= 0.5;
  v2 *= 0.5;
  EXPECT_EQ(v1, v2);
}

TEST(Vec3Test, DivideAssignmentOperator) {
  Vec3 v1{1, 2, 3};
  Vec3 v2{0.5, 1, 1.5};
  v1 /= 2;
  EXPECT_EQ(v1, v2);

  v1 /= 0.123;
  v2 /= 0.123;
  EXPECT_EQ(v1, v2);
}