#include <string>
#include "truck.h"

std::string Truck::getTypeName()
{
	return "TRUCK";
}

bool Truck::testProducedCar(bool print)
{
    if (getEngine() == WIA)
    {
        if (print) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
        }
        return false;
    }

    if (getBrakeSystem() == MANDO)
    {
        if (print) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
        }
        return false;
    }

    if (isInvalidBoschCompatible())
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
