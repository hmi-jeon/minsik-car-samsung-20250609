#pragma once
#include <string>
#include "carinfo.h"

class Car {
public:
	void selectEngine(Engine engine);
	void selectBrakeSystem(BrakeSystem brakeSystem);
	void selectSteeringSystem(SteeringSystem steeringSystem);
	bool runProducedCar();

	virtual std::string getTypeName() = 0;
	virtual bool testProducedCar(bool print) = 0;

protected:
	Engine getEngine() const;
	BrakeSystem getBrakeSystem() const;
	SteeringSystem getSterringSystem() const;
	bool isInvalidBoschCompatible() const;

private:
	Engine engine_;
	BrakeSystem brakeSystem_;
	SteeringSystem steeringSystem_;
};