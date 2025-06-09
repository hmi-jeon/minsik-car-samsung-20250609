#include <string>
#include "sedan.h"

std::string Sedan::getTypeName()
{
	return "SEDAN";
}

bool Sedan::testProducedCar(bool print)
{
    if (getBrakeSystem() == CONTINENTAL)
    {
        if (print) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
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
