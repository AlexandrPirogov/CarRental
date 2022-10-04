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
}
