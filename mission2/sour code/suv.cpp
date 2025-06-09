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
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("SUV에는 TOYOTA엔진 사용 불가\n");
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
