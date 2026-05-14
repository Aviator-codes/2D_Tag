#include "log.h"

void LogError(const char* Error)
{
    printf(FG_BRED "[ERROR] : " FG_YELLOW "%s" ANSI_RESET "\n", Error);
}

void LogWarning(const char *Warn)
{
    printf(FG_BYELLOW "[WARNING]: " FG_MAGENTA "%s" ANSI_RESET "\n", Warn);
}

void LogPass(const char *Test)
{
    printf(FG_BGREEN "[PASSED]: " FG_CYAN "%s" ANSI_RESET "\n", Test);
}
