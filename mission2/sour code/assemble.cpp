#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "assemble.h"

#define CLEAR_SCREEN "\033[H\033[2J"

void Assemble::delay(int ms) const
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

void Assemble::pinrtCarType() const
{
    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("어떤 차량 타입을 선택할까요?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

void Assemble::printEngine() const
{
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");
}

void Assemble::printBrakeSystem() const
{
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void Assemble::printSteeringSsystem() const
{
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void Assemble::printRunTest() const
{
    printf("멋진 차량이 완성되었습니다.\n");
    printf("어떤 동작을 할까요?\n");
    printf("0. 처음 화면으로 돌아가기\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

void Assemble::printSelectScreen(int step) const
{
    printf(CLEAR_SCREEN);

    switch (step)
    {
    case CarType_Q:
        pinrtCarType();
        break;
    case Engine_Q:
        printEngine();
        break;
    case BrakeSystem_Q:
        printBrakeSystem();
        break;
    case SteeringSystem_Q:
        printSteeringSsystem();
        break;
    case Run_Test:
        printRunTest();
        break;
    }

    printf("===============================\n");
    printf("INPUT > ");
}

bool Assemble::convertNumber(const char* buf, int& answer)
{
    char* checkNumber;
    answer = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환

    // 입력받은 문자가 숫자가 아니라면
    if (*checkNumber != '\0')
        return false;
    return true;
}


bool Assemble::isValidSelectRange(int step, int answer)
{
    bool ret = true;

    switch (step)
    {
    case CarType_Q:
        if (!(answer >= 1 && answer <= 3))
        {
            printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
            ret = false;
        }
        break;
    case Engine_Q:
        if (!(answer >= 0 && answer <= 4))
        {
            printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
            ret = false;
        }
        break;
    case BrakeSystem_Q:
        if (!(answer >= 0 && answer <= 3))
        {
            printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
            ret = false;
        }
        break;
    case SteeringSystem_Q:
        if (!(answer >= 0 && answer <= 2))
        {
            printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
            ret = false;
        }
        break;
    case Run_Test:
        if (!(answer >= 0 && answer <= 2))
        {
            printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
            ret = false;
        }
        break;
    }

    delay(800);

    return ret;
}

bool Assemble::isSelectBackStep(int answer) const
{
    return answer == 0;
}

int Assemble::calcBackStep(int step)
{
    if (step == Run_Test)
        step = CarType_Q;
    else if (step >= 1)
        step -= 1;
    return step;
}

int Assemble::runStep(int step, int answer)
{
    switch (step)
    {
    case CarType_Q:
        createCarObject(static_cast<CarType>(answer));
        delay(800);
        step = Engine_Q;
        break;

    case Engine_Q:
        car_->selectEngine(static_cast<Engine>(answer));
        delay(800);
        step = BrakeSystem_Q;
        break;

    case BrakeSystem_Q:
        car_->selectBrakeSystem(static_cast<BrakeSystem>(answer));
        delay(800);
        step = SteeringSystem_Q;
        break;

    case SteeringSystem_Q:
        car_->selectSteeringSystem(static_cast<SteeringSystem>(answer));
        delay(800);
        step = Run_Test;
        break;

    case Run_Test:
        if (answer == 1) {
            car_->runProducedCar();
            delay(2000);
        }
        else if (answer == 2) {
            printf("Test...\n");
            delay(1500);
            car_->testProducedCar(true);
            delay(2000);
        }
        break;
    }

    return step;
}

void Assemble::createCarObject(CarType carType)
{
    if (car_ != nullptr)
        delete car_;

    switch (carType)
    {
    case SEDAN:
        car_ = new Sedan();
        break;
    case SUV:
        car_ = new Suv();
        break;
    case TRUCK:
        car_ = new Truck();
        break;
    }

    printf("차량 타입으로 %s을 선택하셨습니다.\n", car_->getTypeName().c_str());
}
