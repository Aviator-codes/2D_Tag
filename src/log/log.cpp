#include "log.h"

void LogError(const std::string& Error)
{
    printf(FG_BRED "[ERROR] : " FG_YELLOW "%s" ANSI_RESET "\n", Error);
}

void LogWarning(const std::string& Warn)
{
    printf(FG_BYELLOW "[WARNING]: " FG_MAGENTA "%s" ANSI_RESET "\n", Warn);
}

void LogPass(const std::string& Test)
{
    printf(FG_BGREEN "[PASSED]: " FG_CYAN "%s" ANSI_RESET "\n", Test);
}
