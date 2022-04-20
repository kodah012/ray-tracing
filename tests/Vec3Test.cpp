#include <gtest/gtest.h>
#include "Vec3.hpp"

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