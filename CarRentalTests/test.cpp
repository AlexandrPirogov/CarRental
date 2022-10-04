#include "pch.h"
#include <memory>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CarTests, CreateCar)
{
	std::unique_ptr<Car> car = std::make_unique<Car>();

}