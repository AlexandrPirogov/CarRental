#include "pch.h"
#include "./../CarRental/CarStation.h"
#include "./../CarRental/CarStation.cpp"
#include <memory>

namespace CarStationTests
{
	std::shared_ptr<Car> creatingCar(std::string title, int num)
	{
		std::string hondaTitle = std::string(title);
		int carNumber = 1;
		std::shared_ptr<Car> car = std::make_unique<Car>(hondaTitle, num);
		return car;
	}

	std::unique_ptr<CarStation> createStationWithCars()
	{

		std::string hondaTitle = "Honda";
		std::string BMWtitle = "BMW";
		std::string Ladatitle = "Lada";

		std::shared_ptr<Car> carHonda = creatingCar(hondaTitle, 1);
		std::shared_ptr<Car> carHonda2 = creatingCar(hondaTitle, 2);
		std::shared_ptr<Car> carBwm = creatingCar(BMWtitle, 1);
		std::shared_ptr<Car> carLada = creatingCar(Ladatitle, 1);
		std::unique_ptr<CarStation> carStation = std::make_unique<CarStation>();
		carStation->addCar(carHonda);
		carStation->addCar(carHonda2);
		carStation->addCar(carBwm);
		carStation->addCar(carLada);
		return carStation;
	}

	TEST(CarTests, CreateCar)
	{
		std::string title = "Honda";
		std::shared_ptr<Car> car = creatingCar(title, 1);
		ASSERT_TRUE(car->carTitle() == title);
		ASSERT_TRUE(car->carNumber() == 1);
	}

	TEST(CarStationTests, CreateCarStation)
	{
		std::unique_ptr<CarStation> carStation = std::make_unique<CarStation>();
		
		ASSERT_TRUE(carStation->totalCars() == 0);
		ASSERT_FALSE(carStation->isWorking());
	}

	TEST(CarStationTests, AddingCarToStation)
	{
		std::string title = "Honda";
		std::shared_ptr<Car> car = creatingCar(title, 1);
		std::unique_ptr<CarStation> carStation = std::make_unique<CarStation>();
		carStation->addCar(car);
		
		ASSERT_TRUE(carStation->totalCars() == 1);
	}

	TEST(CarStationTests, AddingSameCarTwice)
	{
		std::string title = "Honda";
		std::shared_ptr<Car> car = creatingCar(title, 1);
		std::unique_ptr<CarStation> carStation = std::make_unique<CarStation>();
		carStation->addCar(car);

		std::shared_ptr<Car> car2 = creatingCar(title, 1);
		carStation->addCar(car2);
		
		ASSERT_TRUE(carStation->totalCars() == 1);
		ASSERT_TRUE(carStation->addStatus() == carStation->ADD_STATUS_DUPLICATE);
	}

	TEST(CarStationTests, AddingMultipleCars)
	{
		std::unique_ptr<CarStation> carStation = createStationWithCars();
		ASSERT_TRUE(carStation->totalCars() == 4);
		ASSERT_TRUE(carStation->addStatus() == carStation->ADD_STATUS_OK);
	}

	//RTC
	TEST(CarStationTests, BookingCarTests)
	{
		std::unique_ptr<CarStation> carStation = createStationWithCars();
		auto avaibleCars = carStation->avaibleCars();
		int beforeBook = avaibleCars.size();
		//Commit after this test
		ASSERT_TRUE(avaibleCars.size() > 0);
		

		std::shared_ptr<Car> carToBook = *avaibleCars.begin();
		carStation->book(carToBook);
		int afterBook = carStation->avaibleCars().size();
		//Commit after this test
		ASSERT_TRUE(beforeBook > afterBook);

	}

	TEST(CarStationTests, BookReleaseCarStatusesTest)
	{
		std::unique_ptr<CarStation> carStation = createStationWithCars();
		auto avaibleCars = carStation->avaibleCars();
		std::shared_ptr<Car> carToBook = *avaibleCars.begin();

		carStation->release(carToBook);
		//Commit after this test
		ASSERT_TRUE(carStation->releaseStatus() == carStation->RELEASE_STATUS_ERR);
		
		carStation->book(carToBook);
		//Commit after this test
		ASSERT_TRUE(carStation->bookStatus() == carStation->BOOK_STATUS_OK);

		carStation->book(carToBook);
		//Commit after this test
		ASSERT_TRUE(carStation->bookStatus() == carStation->BOOK_STATUS_ISBOOKED);

		carStation->release(carToBook);
		//Commit after this test
		ASSERT_TRUE(carStation->releaseStatus() == carStation->RELEASE_STATUS_OK);
	}
}
