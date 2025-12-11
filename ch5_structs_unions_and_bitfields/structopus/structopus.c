#include <stdio.h>

#include "first-step.h"
#include "fourth-step.h"
#include "second-step.h"
#include "third-step.h"

int main()
{
    firstStep();
    const auto result = secondStep();
    const struct third thirdResult = { result };
    thirdStep(thirdResult);
    fourthStep();
}
