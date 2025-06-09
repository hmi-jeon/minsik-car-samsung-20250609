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
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 WIA엔진 사용 불가\n");
        }
        return false;
    }

    if (getBrakeSystem() == MANDO)
    {
        if (print) {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 Mando제동장치 사용 불가\n");
        }
        return false;
    }

    if (isInvalidBoschCompatible())
    {
        if (print) {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        return false;
    }

    if (print)
        printf("자동차 부품 조합 테스트 결과 : PASS\n");

    return true;
}
