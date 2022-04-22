#include <gtest/gtest.h>
#include "Ray.hpp"

TEST(RayTest, LerpZero) {
  Ray r1{Vec3{1, 0, 0}, Vec3{1, 0, 0}};
  EXPECT_TRUE(r1.lerp(0).approxEquals(Vec3(1, 0, 0)));
}

TEST(RayTest, LerpOne) {
  Ray r1{Vec3{1, 0, 0}, Vec3{1, 0, 0}};
  EXPECT_TRUE(r1.lerp(1).approxEquals(Vec3(2, 0, 0)));
}

TEST(RayTest, LerpHalfway) {
  Ray r1{Vec3{1, 0, 0}, Vec3{1, 0, 0}};
  EXPECT_TRUE(r1.lerp(0.5).approxEquals(Vec3(1.5, 0, 0)));
}

TEST(RayTest, LerpBelowZero) {
  Ray r1{Vec3{1, 0, 0}, Vec3{1, 0, 0}};
  EXPECT_TRUE(r1.lerp(-0.5).approxEquals(Vec3(0.5, 0, 0)));
}

TEST(RayTest, LerpAboveOne) {
  Ray r1{Vec3{1, 0, 0}, Vec3{1, 0, 0}};
  EXPECT_TRUE(r1.lerp(1.5).approxEquals(Vec3(2.5, 0, 0)));
}