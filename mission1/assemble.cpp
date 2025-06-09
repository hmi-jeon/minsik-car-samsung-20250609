#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <string>

#define CLEAR_SCREEN "\033[H\033[2J"

void selectCarType(int answer);
void selectEngine(int answer);
void selectBrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
bool testProducedCar(bool print);
void delay(int ms);
void printSelectScreen(int step);
bool isValidSelectRange(int step, int answer);
int runStep(int step, int answer);

struct CarInfo {
    int carType;
    int engine;
    int brakeSystem;
    int steeringSystem;
};

CarInfo carinfo;

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA,
    BROKEN,
};

enum BrakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

const std::map<int, std::string> carTypeStr =
{
    {SEDAN, "SEDAN"},
    {SUV, "SUV"},
    {TRUCK, "TRUCK"}
};

const std::map<int, std::string> engineTypeStr =
{
    {GM, "GM"},
    {TOYOTA, "TOYOTA"},
    {WIA, "WIA"}
};

const std::map<int, std::string> brakeTypeStr =
{
    {MANDO, "MANDO"},
    {CONTINENTAL, "CONTINENTAL"},
    {BOSCH_B, "BOSCH"}
};

const std::map<int, std::string> steeringTypeStr =
{
    {BOSCH_S, "BOSCH"},
    {MOBIS, "MOBIS"}
};

void delay(int ms)
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

bool convertNumber(const char* buf, int& answer)
{
    char* checkNumber;
    answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

    // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
    if (*checkNumber != '\0')
        return false;
    return true;
}

bool isSelectBackStep(int answer)
{
    return answer == 0;
}

int calcBackStep(int step)
{
    if (step == Run_Test)
        step = CarType_Q;
    else if (step >= 1)
        step -= 1;
    return step;
}

int main()
{
    char buf[100];
    int step = CarType_Q;
    int answer = 0;

    while (1)
    {
        printSelectScreen(step);

        fgets(buf, sizeof(buf), stdin);

        // ���� ���๮�� ����
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("���̹���\n");
            break;
        }

        if (!convertNumber(buf, answer))
        {
            printf("ERROR :: ���ڸ� �Է� ����\n");
            delay(800);
            continue;
        }

        if (!isValidSelectRange(step, answer))  continue;

        if (isSelectBackStep(answer))
        {
            step = calcBackStep(step);
            continue;
        }

        step = runStep(step, answer);
    }
}

void pinrtCarType()
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

void printEngine()
{
    printf("� ������ ž���ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. ���峭 ����\n");
}

void printBrakeSystem()
{
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void printSteeringSsystem()
{
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void printRunTest()
{
    printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
    printf("� ������ �ұ��?\n");
    printf("0. ó�� ȭ������ ���ư���\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

void printSelectScreen(int step)
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

bool isValidSelectRange(int step, int answer)
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

void selectCarType(int car_type)
{
    carinfo.carType = car_type;
    printf("���� Ÿ������ %s�� �����ϼ̽��ϴ�.\n", carTypeStr.at(car_type).c_str());
}

void selectEngine(int engine)
{
    carinfo.engine = engine;
    if (engine != BROKEN)
        printf("%s ������ �����ϼ̽��ϴ�.\n", engineTypeStr.at(engine).c_str());
}

void selectBrakeSystem(int brake_system)
{
    carinfo.brakeSystem = brake_system;
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", brakeTypeStr.at(brake_system).c_str());
}

void selectSteeringSystem(int steering_system)
{
    carinfo.steeringSystem = steering_system;
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", steeringTypeStr.at(steering_system).c_str());
}

bool testProducedCar(bool print)
{
    if (carinfo.carType == SEDAN && carinfo.brakeSystem == CONTINENTAL)
    {
        if (print) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        }
        return false;
    }
    else if (carinfo.carType == SUV && carinfo.engine == TOYOTA)
    {
        if (print) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        }
        return false;
    }
    else if (carinfo.carType == TRUCK && carinfo.engine == WIA)
    {
        if (print) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
        }
        return false;
    }
    else if (carinfo.carType == TRUCK && carinfo.brakeSystem == MANDO)
    {
        if (print) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
        }
        return false;
    }
    else if (carinfo.brakeSystem == BOSCH_B && carinfo.steeringSystem != BOSCH_S)
    {
        if (print) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        return false;
    }

    if (print)
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");

    return true;
}

void runProducedCar()
{
    if (testProducedCar(false) == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        return;
    }

    if (carinfo.engine == BROKEN)
    {
        printf("������ ���峪�ֽ��ϴ�.\n");
        printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        return;
    }

    printf("Car Type : %s\n", carTypeStr.at(carinfo.carType).c_str());
    printf("Engine : %s\n", engineTypeStr.at(carinfo.engine).c_str());
    printf("Brake System : %s\n", brakeTypeStr.at(carinfo.brakeSystem).c_str());
    printf("SteeringSystem : %s\n", steeringTypeStr.at(carinfo.steeringSystem).c_str());

    printf("�ڵ����� ���۵˴ϴ�.\n");
}

int runStep(int step, int answer)
{
    switch (step)
    {
    case CarType_Q:
        selectCarType(answer);
        delay(800);
        step = Engine_Q;
        break;

    case Engine_Q:
        selectEngine(answer);
        delay(800);
        step = BrakeSystem_Q;
        break;

    case BrakeSystem_Q:
        selectBrakeSystem(answer);
        delay(800);
        step = SteeringSystem_Q;
        break;

    case SteeringSystem_Q:
        selectSteeringSystem(answer);
        delay(800);
        step = Run_Test;
        break;

    case Run_Test:
        if (answer == 1) {
            runProducedCar();
            delay(2000);
        }
        else if (answer == 2) {
            printf("Test...\n");
            delay(1500);
            testProducedCar(true);
            delay(2000);
        }
        break;
    }

    return step;
}