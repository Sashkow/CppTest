//============================================================================
// Name        : CppTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <string>
#include <map>

#include "File.h"
#include "MapStringToConstructor.h"

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;


using namespace std;



class Car
{
public:
	enum FuelType
	    {
	        UNKNOWN_FUEL,
	        PETROLEUM_FUEL,
	        ELECTRICITY_FUEL,
	        HELLIUM_FUEL
	    };


    virtual ~Car();

    FuelType getFuelType() const { return m_fuelType; }
    std::string getFuelUnit(FuelType type) { return m_fuelUnits.at(type); }
    virtual float calculateFuelConsumption(float distance, float speed) const = 0;
    virtual void fill(FuelType fuelType) = 0;

private:
    FuelType m_fuelType;
    static std::map < FuelType, std::string> m_fuelUnits;
};

std::map < Car::FuelType, std::string> Car::m_fuelUnits
{
    { Car::UNKNOWN_FUEL, "unknown" },
    { Car::PETROLEUM_FUEL, "litres" },
    { Car::ELECTRICITY_FUEL, "Ah" },
    { Car::HELLIUM_FUEL, "cubic metres" }
};




class PetrolFueledCar : public Car
{
public:
    // ...
    float calculateFuelConsumption(float distance, float speed) const { return 0;    }
    void fill(FuelType fuelType)  {   }
};

class HelliumPoweredCar : public Car
{
public:
    // ...
    float calculateFuelConsumption(float distance, float speed) const { return 0; }
    void fill(FuelType fuelType)  {   }
};



class CarFactory
{
public:
    static unique_ptr<Car> newCar(Car::FuelType fuelType)
    {

        if (fuelType == Car::PETROLEUM_FUEL){
        	//return new PetrolFueledCar;
        	return std::unique_ptr<Car>(new PetrolFueledCar);;
        }


/*

        if (fuelType = Car::HELLIUM_FUEL)
            return new HelliumPoweredCar();
*/
        return NULL;

    }
};


class Interface{
public:
	virtual ~Interface(){}
	virtual void f()=0;

};

class Implementation:public Interface{
public:
	virtual ~Implementation(){}
	void f(){}
};


class Vehicle{
private:

	float tankCapacity;
	float fuelInTank;
	//FuelType requiredFuelType;
	//static std::map < FuelType, std::string> fuelUnitsMap;
	float amountToTake;



	//date arrivalDate; 					//not here

	ptime waitingForFuelTime;
	ptime waitingForUpdatedStatisticsTime;

	float cash;

public:


	virtual ptime evaluateFuelingTime() = 0;
	virtual void fill()=0;
	virtual ~Vehicle(){}


};


class PetrolCar: public Vehicle{
public:
	ptime evaluateFuelingTime(){
		ptime t=second_clock::local_time();
	    return t;
	}
	void fill(){}
	virtual ~PetrolCar(){}


};





int main() {
	Factory fac=Factory();
	Super child=*(fac.create("c1")).get();
	cout<<typeid(child).name()<<endl;

	child.f();






	//unique_ptr<PetrolFueledCar> ptr=carFactory.newCar(Car::PETROLEUM_FUEL);
	std::cout<<"works";
	return 0;

}

