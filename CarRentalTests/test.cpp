#include "pch.h"
#include "./../CarRental/CarStation.h"
#include "./../CarRental/CarStation.cpp"
#include <memory>

namespace CarStationTests
{

	TEST(CarStationTests, CreateCarStation)
	{
		std::unique_ptr<CarStation> carStation = std::make_unique<CarStation>();
		ASSERT_TRUE(carStation->avaibleCars() == 0);
		ASSERT_TRUE(carStation->totalCars() == 0);
		ASSERT_FALSE(carStation->isWorking());
	}

	TEST(CarTests, CreateCar)
	{
		std::string hondaTitle = "Honda";
		int carNumber = 1;
		std::unique_ptr<Car> car = std::make_unique<Car>(hondaTitle, 1);
		ASSERT_TRUE(car->title() == hondaTitle);
		ASSERT_TRUE(car->carNumber() == 1);
	}
}
