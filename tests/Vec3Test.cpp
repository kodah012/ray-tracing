#include <gtest/gtest.h>
#include "Vec3.hpp"

TEST(Vec3Test, Equality) {
  Vec3 v1{1, 2, 3};
  Vec3 v2{1, 2, 3};
  Vec3 v3{2, 2, 3};
  EXPECT_EQ(v1, v2);
  EXPECT_NE(v1, v3);
}