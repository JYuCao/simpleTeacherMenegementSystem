#include "Sqlist.h"
#include "TMS_Sqlist.h"
#include <stdio.h>

int main(void)
{
    List teachersList;

    InitializeItem(&teachersList);
    showMenu(&teachersList);
    EmptyTheItem(&teachersList);

    return 0;
}
