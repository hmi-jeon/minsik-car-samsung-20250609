#include <string>
#include "suv.h"

std::string Suv::getTypeName()
{
	return "SUV";
}

bool Suv::testProducedCar(bool print)
{
    if (getEngine() == TOYOTA)
    {
        if (print) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
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
