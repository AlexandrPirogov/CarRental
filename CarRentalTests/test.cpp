#include "pch.h"
#include "./../CarRental/CarStation.h"
#include "./../CarRental/CarStation.cpp"
#include <memory>

namespace CarStationTests
{
	std::unique_ptr<Car> creatingCar(std::string title, int num)
	{
		std::string hondaTitle = std::string(title);
		int carNumber = 1;
		std::unique_ptr<Car> car = std::make_unique<Car>(hondaTitle, 1);
		return car;
	}

	TEST(CarTests, CreateCar)
	{
		std::string title = "Honda";
		std::unique_ptr<Car> car = creatingCar(title, 1);
		ASSERT_TRUE(car->carTitle() == title);
		ASSERT_TRUE(car->carNumber() == 1);
	}

	TEST(CarStationTests, CreateCarStation)
	{
		std::unique_ptr<CarStation> carStation = std::make_unique<CarStation>();
		ASSERT_TRUE(carStation->avaibleCars() == 0);
		ASSERT_TRUE(carStation->totalCars() == 0);
		ASSERT_FALSE(carStation->isWorking());
	}

	TEST(CarStationTests, AddingCarToStation)
	{
		std::string title = "Honda";
		std::unique_ptr<Car> car = creatingCar(title, 1);
		std::unique_ptr<CarStation> carStation = std::make_unique<CarStation>();
		carStation->addCar(car);
		ASSERT_TRUE(carStation->avaibleCars() == 0);
		ASSERT_TRUE(carStation->totalCars() == 1);
	}
}
