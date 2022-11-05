#include "Linklist.h"
#include "TMS_Linklist.h"
#include <stdio.h>

int main(void)
{
    List teachersList;

    InitializeList(&teachersList);
    showMenu(&teachersList);
    EmptyTheList(&teachersList);

    return 0;
}
