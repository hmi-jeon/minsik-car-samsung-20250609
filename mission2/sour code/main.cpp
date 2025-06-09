#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}

#else

#include "assemble.h"

int main()
{
    Assemble assemble;
    char buf[100];
    int step = 0;
    int answer;

    while (1)
    {
        assemble.printSelectScreen(step);

        fgets(buf, sizeof(buf), stdin);

        // 엔터 개행문자 제거
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("바이바이\n");
            break;
        }

        if (!assemble.convertNumber(buf, answer))
        {
            printf("ERROR :: 숫자만 입력 가능\n");
            assemble.delay(800);
            continue;
        }

        if (!assemble.isValidSelectRange(step, answer))  continue;

        if (assemble.isSelectBackStep(answer))
        {
            step = assemble.calcBackStep(step);
            continue;
        }

        step = assemble.runStep(step, answer);
    }

	return 0;
}

#endif