#pragma once
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <memory>

class Car
{
	std::string title;
	int number;
public:
	Car() = delete;
	Car(const std::string& title, const int carNumber) : title(title), number(carNumber)
	{

	};

	inline std::string carTitle() noexcept
	{
		return title;
	};

	inline int carNumber() noexcept
	{
		return number;
	};
};

typedef std::map<std::string, std::map<int, std::unique_ptr<Car>>> stationCars;
typedef std::map<int, std::unique_ptr<Car>> carRecord;

class CarStation
{
	short add_status;
	stationCars cars;
public:
	const short ADD_STATUS_NIL = -1;
	const short ADD_STATUS_OK = 0;
	const short ADD_STATUS_DUPLICATE = 1;

	CarStation() : add_status(ADD_STATUS_NIL) { add_status = ADD_STATUS_NIL; };

	inline void addCar(std::unique_ptr<Car>& car)
	{
		std::string title = car->carTitle();
		if (cars[title].find(car->carNumber()) == cars[title].end())
		{
			add_status = ADD_STATUS_DUPLICATE;
			return;
		}

		cars[title].emplace(std::make_pair(car->carNumber(), std::move(car)));
		add_status = ADD_STATUS_OK;
	}

	inline int avaibleCars() noexcept
	{
		return 0;
	};

	inline int totalCars() noexcept
	{
		int total = 0;
		for (const auto& keyVale : cars)
		{
			total += cars.size();
		}
		return total;
	};

	inline bool isWorking() noexcept
	{
		return false;
	};

	inline const short addStatus() noexcept
	{
		return add_status;
	}
};

