#include "car.h"

void Car::selectEngine(Engine engine)
{
    engine_ = engine;
    if (engine != BROKEN)
        printf("%s 엔진을 선택하셨습니다.\n", engineTypeStr.at(engine).c_str());
}

void Car::selectBrakeSystem(BrakeSystem brakeSystem)
{
    brakeSystem_ = brakeSystem;
    printf("%s 제동장치를 선택하셨습니다.\n", brakeTypeStr.at(brakeSystem).c_str());
}

void Car::selectSteeringSystem(SteeringSystem steeringSystem)
{
    steeringSystem_ = steeringSystem;
    printf("%s 조향장치를 선택하셨습니다.\n", steeringTypeStr.at(steeringSystem).c_str());
}

bool Car::runProducedCar()
{
    if (testProducedCar(false) == false)
    {
        printf("자동차가 동작되지 않습니다\n");
        return false;
    }

    if (getEngine() == BROKEN)
    {
        printf("엔진이 고장나있습니다.\n");
        printf("자동차가 움직이지 않습니다.\n");
        return false;
    }

    printf("Car Type : %s\n", getTypeName().c_str());
    printf("Engine : %s\n", engineTypeStr.at(getEngine()).c_str());
    printf("Brake System : %s\n", brakeTypeStr.at(getBrakeSystem()).c_str());
    printf("SteeringSystem : %s\n", steeringTypeStr.at(getSterringSystem()).c_str());

    printf("자동차가 동작됩니다.\n");

    return true;
}

Engine Car::getEngine() const
{
	return engine_;
}

BrakeSystem Car::getBrakeSystem() const
{
	return brakeSystem_;
}

SteeringSystem Car::getSterringSystem() const
{
	return steeringSystem_;
}

bool Car::isInvalidBoschCompatible() const
{
    return (getBrakeSystem() == BOSCH_B && getSterringSystem() != BOSCH_S);
}
