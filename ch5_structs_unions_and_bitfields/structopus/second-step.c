//
// Created by cam on 2025-12-10.
//

#include "second-step.h"

#include <stdio.h>
#include <stdlib.h>

char* secondStep()
{
    const auto name = (char*)malloc(sizeof(char) * 10);
    scanf("%9s", name);
    return name;
}
