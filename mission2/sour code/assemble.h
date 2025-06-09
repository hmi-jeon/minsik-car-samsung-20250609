#pragma once
#include "car.h"
#include "sedan.h"
#include "suv.h"
#include "truck.h"

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

class Assemble {
public:
    void printSelectScreen(int step) const;
    bool convertNumber(const char* buf, int& answer);
    bool isValidSelectRange(int step, int answer);
    bool isSelectBackStep(int answer) const;
    int calcBackStep(int step);
    int runStep(int step, int answer);
    void delay(int ms) const;

private:
    void pinrtCarType() const;
    void printEngine() const;
    void printBrakeSystem() const;
    void printSteeringSsystem() const;
    void printRunTest() const;
    void createCarObject(CarType carType);

private:
    Car* car_ = nullptr;
};
