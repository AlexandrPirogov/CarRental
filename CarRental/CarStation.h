#pragma once
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <numeric>
#include <memory>

class Car
{
	int number;
	bool isBusy;
	std::string title;
public:
	Car() = delete;
	Car(const std::string& title, const int carNumber) : title(title), number(carNumber), isBusy(false)
	{

	};

	inline void book() noexcept
	{
		isBusy = true;
	}

	inline void release() noexcept
	{
		isBusy = false;
	}

	inline std::string carTitle() noexcept
	{
		return title;
	};

	inline int carNumber() noexcept
	{
		return number;
	};

	inline int isBooked() noexcept
	{
		return isBusy;
	}
};


typedef std::map<std::string, std::map<int, std::shared_ptr<Car>>> stationCars;
typedef std::map<int, std::shared_ptr<Car>> carRecord;

class CarStation
{
	short add_status;
	short book_status;
	short release_status;

	stationCars cars;
	
public:
	const short ADD_STATUS_NIL = -1;
	const short ADD_STATUS_OK = 0;
	const short ADD_STATUS_DUPLICATE = 1;

	const short BOOK_STATUS_NIL = -1;
	const short BOOK_STATUS_OK = 0;
	const short BOOK_STATUS_ISBOOKED = 1;

	const short RELEASE_STATUS_NIL = -1;
	const short RELEASE_STATUS_OK = 0;
	const short RELEASE_STATUS_ERR = 1;

	CarStation() : add_status(ADD_STATUS_NIL) 
	{ 
		add_status = ADD_STATUS_NIL; 
		book_status = BOOK_STATUS_NIL; 
		release_status = RELEASE_STATUS_NIL; 
	};

	inline void addCar(std::shared_ptr<Car>& car)
	{
		std::string title = car->carTitle();
		if (cars[title].find(car->carNumber()) != cars[title].end())
		{
			add_status = ADD_STATUS_DUPLICATE;
			return;
		}

		cars[title].emplace(std::make_pair(car->carNumber(), std::move(car)));
		add_status = ADD_STATUS_OK;
	}

	inline void book(std::shared_ptr<Car>& car)
	{
		if (!car->isBooked())
		{
			car->book();
			book_status = BOOK_STATUS_OK;
			return;
		}
		book_status = BOOK_STATUS_ISBOOKED;
		
	}

	inline void release(std::shared_ptr<Car>& car)
	{
		if (car->isBooked())
		{
			car->release();
			release_status = RELEASE_STATUS_OK;
			return;
		}
		release_status = RELEASE_STATUS_ERR;
	}

	inline std::list<std::shared_ptr<Car>> avaibleCars() noexcept
	{
		std::list<std::shared_ptr<Car>> avaible;
		for (const auto& car : cars)
			for(const auto& numCar : car.second)
				if(!numCar.second->isBooked())
					avaible.push_back(numCar.second);
		return avaible;
	};

	inline int totalCars() noexcept
	{
		int total = 0;
		for (const auto& car : cars)
			total += car.second.size();
		
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

	inline const short releaseStatus() noexcept
	{
		return release_status;
	}

	inline const short bookStatus() noexcept
	{
		return book_status;
	}
};

