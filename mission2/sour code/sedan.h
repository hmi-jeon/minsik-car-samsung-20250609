#pragma once
#include "car.h"

class Sedan : public Car
{
public:
	virtual std::string getTypeName() override;
	virtual bool testProducedCar(bool print) override;
};
