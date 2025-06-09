#include "gmock/gmock.h"
#include "carinfo.h"
#include "car.h"
#include "sedan.h"
#include "suv.h"
#include "truck.h"

#include <string>

using namespace testing;

TEST(GROUP, SedanTestName) {
	Car* car = new Sedan();
	EXPECT_EQ(car->getTypeName(), "SEDAN");
}

TEST(GROUP, SedanTestNormal) {
	Car* car = new Sedan();
	car->selectEngine(GM);
	car->selectBrakeSystem(MANDO);
	car->selectSteeringSystem(BOSCH_S);

	EXPECT_EQ(car->testProducedCar(false), true);
	EXPECT_EQ(car->testProducedCar(true), true);
}

TEST(GROUP, SedanTestContinental) {
	Car* car = new Sedan();
	car->selectEngine(GM);
	car->selectBrakeSystem(CONTINENTAL);
	car->selectSteeringSystem(BOSCH_S);

	EXPECT_EQ(car->testProducedCar(false), false);
	EXPECT_EQ(car->testProducedCar(true), false);
}

TEST(GROUP, SedanTestBosch) {
	Car* car = new Sedan();
	car->selectEngine(GM);
	car->selectBrakeSystem(BOSCH_B);
	car->selectSteeringSystem(MOBIS);

	EXPECT_EQ(car->testProducedCar(false), false);
	EXPECT_EQ(car->testProducedCar(true), false);
}

TEST(GROUP, SedanTestRunProducer) {
	Car* car = new Sedan();
	car->selectEngine(GM);
	car->selectBrakeSystem(MANDO);
	car->selectSteeringSystem(MOBIS);

	EXPECT_EQ(car->runProducedCar(), true);
}

TEST(GROUP, SedanTestRunProducerFail) {
	Car* car = new Sedan();
	car->selectEngine(GM);
	car->selectBrakeSystem(BOSCH_B);
	car->selectSteeringSystem(MOBIS);

	EXPECT_EQ(car->runProducedCar(), false);
}

TEST(GROUP, SedanTestBroken) {
	Car* car = new Sedan();
	car->selectEngine(BROKEN);
	car->selectBrakeSystem(MANDO);
	car->selectSteeringSystem(MOBIS);

	EXPECT_EQ(car->runProducedCar(), false);
}

TEST(GROUP, SuvTestName) {
	Car* car = new Suv();
	EXPECT_EQ(car->getTypeName(), "SUV");
}

TEST(GROUP, SuvTestNormal) {
	Car* car = new Suv();
	car->selectEngine(GM);
	car->selectBrakeSystem(MANDO);
	car->selectSteeringSystem(BOSCH_S);

	EXPECT_EQ(car->testProducedCar(false), true);
	EXPECT_EQ(car->testProducedCar(true), true);
}

TEST(GROUP, SuvTestTOYOTA) {
	Car* car = new Suv();
	car->selectEngine(TOYOTA);
	car->selectBrakeSystem(CONTINENTAL);
	car->selectSteeringSystem(BOSCH_S);

	EXPECT_EQ(car->testProducedCar(false), false);
	EXPECT_EQ(car->testProducedCar(true), false);
}

TEST(GROUP, SuvTestBosch) {
	Car* car = new Suv();
	car->selectEngine(GM);
	car->selectBrakeSystem(BOSCH_B);
	car->selectSteeringSystem(MOBIS);

	EXPECT_EQ(car->testProducedCar(false), false);
	EXPECT_EQ(car->testProducedCar(true), false);
}

TEST(GROUP, TruckTestName) {
	Car* car = new Truck();
	EXPECT_EQ(car->getTypeName(), "TRUCK");
}

TEST(GROUP, TruckTestNormal) {
	Car* car = new Truck();
	car->selectEngine(GM);
	car->selectBrakeSystem(CONTINENTAL);
	car->selectSteeringSystem(BOSCH_S);

	EXPECT_EQ(car->testProducedCar(false), true);
	EXPECT_EQ(car->testProducedCar(true), true);
}

TEST(GROUP, TruckTestWIA) {
	Car* car = new Truck();
	car->selectEngine(WIA);
	car->selectBrakeSystem(CONTINENTAL);
	car->selectSteeringSystem(BOSCH_S);

	EXPECT_EQ(car->testProducedCar(false), false);
	EXPECT_EQ(car->testProducedCar(true), false);
}

TEST(GROUP, TruckTestMANDO) {
	Car* car = new Truck();
	car->selectEngine(GM);
	car->selectBrakeSystem(MANDO);
	car->selectSteeringSystem(BOSCH_S);

	EXPECT_EQ(car->testProducedCar(false), false);
	EXPECT_EQ(car->testProducedCar(true), false);
}

TEST(GROUP, TruckTestBosch) {
	Car* car = new Truck();
	car->selectEngine(GM);
	car->selectBrakeSystem(BOSCH_B);
	car->selectSteeringSystem(MOBIS);

	EXPECT_EQ(car->testProducedCar(false), false);
	EXPECT_EQ(car->testProducedCar(true), false);
}
