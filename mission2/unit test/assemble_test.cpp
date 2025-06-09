#include "gmock/gmock.h"
#include "assemble.h"

using namespace testing;

TEST(AssembleGROUP, AssemblePrintScreen) {
    Assemble assemble;

    assemble.printSelectScreen(CarType_Q);
    assemble.printSelectScreen(Engine_Q);
    assemble.printSelectScreen(BrakeSystem_Q);
    assemble.printSelectScreen(SteeringSystem_Q);
    assemble.printSelectScreen(Run_Test);
}

TEST(AssembleGROUP, isValidSelectRange) {
    Assemble assemble;

    EXPECT_EQ(assemble.isValidSelectRange(CarType_Q, 1), true);
    EXPECT_EQ(assemble.isValidSelectRange(Engine_Q, 1), true);
    EXPECT_EQ(assemble.isValidSelectRange(BrakeSystem_Q, 1), true);
    EXPECT_EQ(assemble.isValidSelectRange(SteeringSystem_Q, 1), true);
    EXPECT_EQ(assemble.isValidSelectRange(Run_Test, 1), true);
}

TEST(AssembleGROUP, isInvalidSelectRange) {
    Assemble assemble;

    EXPECT_EQ(assemble.isValidSelectRange(CarType_Q, 0), false);
    EXPECT_EQ(assemble.isValidSelectRange(Engine_Q, 5), false);
    EXPECT_EQ(assemble.isValidSelectRange(BrakeSystem_Q, 5), false);
    EXPECT_EQ(assemble.isValidSelectRange(SteeringSystem_Q, 3), false);
    EXPECT_EQ(assemble.isValidSelectRange(Run_Test, 3), false);
}

TEST(AssembleGROUP, isSelectBackStep) {
    Assemble assemble;

    EXPECT_EQ(assemble.isSelectBackStep(0), true);
}

TEST(AssembleGROUP, isNotSelectBackStep) {
    Assemble assemble;

    EXPECT_EQ(assemble.isSelectBackStep(1), false);
}

TEST(AssembleGROUP, calcBackStep1) {
    Assemble assemble;

    EXPECT_EQ(assemble.calcBackStep(Run_Test), CarType_Q);
}

TEST(AssembleGROUP, calcBackStep2) {
    Assemble assemble;

    EXPECT_EQ(assemble.calcBackStep(2), 1);
}

TEST(AssembleGROUP, runStepCarType) {
    Assemble assemble;

    EXPECT_EQ(assemble.runStep(CarType_Q, SEDAN), Engine_Q);
    EXPECT_EQ(assemble.runStep(CarType_Q, SUV), Engine_Q);
    EXPECT_EQ(assemble.runStep(CarType_Q, TRUCK), Engine_Q);
}

TEST(AssembleGROUP, runStepEngine) {
    Assemble assemble;

    assemble.runStep(CarType_Q, SEDAN);
    EXPECT_EQ(assemble.runStep(Engine_Q, GM), BrakeSystem_Q);
}

TEST(AssembleGROUP, runStepBrakeSystem) {
    Assemble assemble;

    assemble.runStep(CarType_Q, SEDAN);
    EXPECT_EQ(assemble.runStep(BrakeSystem_Q, MANDO), SteeringSystem_Q);
}

TEST(AssembleGROUP, runStepSteeringSystem) {
    Assemble assemble;

    assemble.runStep(CarType_Q, SEDAN);
    EXPECT_EQ(assemble.runStep(SteeringSystem_Q, MOBIS), Run_Test);
}

TEST(AssembleGROUP, runStepRunTest) {
    Assemble assemble;

    assemble.runStep(CarType_Q, SEDAN);
    assemble.runStep(Engine_Q, GM);
    assemble.runStep(BrakeSystem_Q, MANDO);
    assemble.runStep(SteeringSystem_Q, MOBIS);
    EXPECT_EQ(assemble.runStep(Run_Test, 1), Run_Test);
    EXPECT_EQ(assemble.runStep(Run_Test, 2), Run_Test);
}

TEST(AssembleGROUP, ConvertNumber) {
    Assemble assemble;

    const char buf[10] = "2";
    int answer;

    EXPECT_EQ(assemble.convertNumber(buf, answer), true);
    EXPECT_EQ(answer, 2);
}

TEST(AssembleGROUP, ConvertNumberFail) {
    Assemble assemble;

    const char buf[10] = "fa";
    int answer;
    EXPECT_EQ(assemble.convertNumber(buf, answer), false);
}