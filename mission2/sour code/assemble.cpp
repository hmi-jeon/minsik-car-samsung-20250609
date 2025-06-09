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
    printf("� ���� Ÿ���� �����ұ��?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

void Assemble::printEngine() const
{
    printf("� ������ ž���ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. ���峭 ����\n");
}

void Assemble::printBrakeSystem() const
{
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void Assemble::printSteeringSsystem() const
{
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void Assemble::printRunTest() const
{
    printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
    printf("� ������ �ұ��?\n");
    printf("0. ó�� ȭ������ ���ư���\n");
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
    answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

    // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
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
            printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
            ret = false;
        }
        break;
    case Engine_Q:
        if (!(answer >= 0 && answer <= 4))
        {
            printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
            ret = false;
        }
        break;
    case BrakeSystem_Q:
        if (!(answer >= 0 && answer <= 3))
        {
            printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
            ret = false;
        }
        break;
    case SteeringSystem_Q:
        if (!(answer >= 0 && answer <= 2))
        {
            printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
            ret = false;
        }
        break;
    case Run_Test:
        if (!(answer >= 0 && answer <= 2))
        {
            printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
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

    printf("���� Ÿ������ %s�� �����ϼ̽��ϴ�.\n", car_->getTypeName().c_str());
}
