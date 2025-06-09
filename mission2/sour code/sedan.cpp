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
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Sedan에는 Continental제동장치 사용 불가\n");
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
