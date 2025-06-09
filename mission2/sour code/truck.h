#pragma once
#include "car.h"

class Truck : public Car
{
public:
	virtual std::string getTypeName() override;
	virtual bool testProducedCar(bool print) override;
};
