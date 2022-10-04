#pragma once
#include <map>
#include <string>

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

class CarStation
{
	
public:
	CarStation() = default;

	inline int avaibleCars() noexcept
	{
		return 0;
	};

	inline int totalCars() noexcept
	{
		return 0;
	};

	inline bool isWorking() noexcept
	{
		return false;
	};
};

