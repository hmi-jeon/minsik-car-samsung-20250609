#include "car.h"

void Car::selectEngine(Engine engine)
{
    engine_ = engine;
    if (engine != BROKEN)
        printf("%s ������ �����ϼ̽��ϴ�.\n", engineTypeStr.at(engine).c_str());
}

void Car::selectBrakeSystem(BrakeSystem brakeSystem)
{
    brakeSystem_ = brakeSystem;
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", brakeTypeStr.at(brakeSystem).c_str());
}

void Car::selectSteeringSystem(SteeringSystem steeringSystem)
{
    steeringSystem_ = steeringSystem;
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", steeringTypeStr.at(steeringSystem).c_str());
}

bool Car::runProducedCar()
{
    if (testProducedCar(false) == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        return false;
    }

    if (getEngine() == BROKEN)
    {
        printf("������ ���峪�ֽ��ϴ�.\n");
        printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        return false;
    }

    printf("Car Type : %s\n", getTypeName().c_str());
    printf("Engine : %s\n", engineTypeStr.at(getEngine()).c_str());
    printf("Brake System : %s\n", brakeTypeStr.at(getBrakeSystem()).c_str());
    printf("SteeringSystem : %s\n", steeringTypeStr.at(getSterringSystem()).c_str());

    printf("�ڵ����� ���۵˴ϴ�.\n");

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
