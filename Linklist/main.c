#include "Linklist.h"
#include "TMS_Linklist.h"
#include <stdio.h>

int main(void)
{
    List teachersList;

    system("chcp 65001");
    InitializeList(&teachersList);
    addSomeInfo(&teachersList);
    showMenu(&teachersList);
    EmptyTheList(&teachersList);

    return 0;
}
