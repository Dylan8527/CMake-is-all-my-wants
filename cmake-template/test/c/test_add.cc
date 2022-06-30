#include "gtest/gtest.h"
#include "math/add.h"

TEST(TestAddInt, test_add_int_1) {
  int res = add_int(10, 24);
  EXPECT_EQ(res, 34);
}
