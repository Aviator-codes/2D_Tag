#pragma once

#include "../config.h"

#pragma once

#define ANSI_ESC                    "\x1b["
#define ANSI_RESET ANSI_ESC         "0m"
#define ANSI_CLEAR_TERMINAL         "\033[2J\033[1;1H"

#define ANSI_BOLD                   ANSI_ESC "1m"
#define ANSI_UNDERLINE              ANSI_ESC "4m"
#define ANSI_INVERSE                ANSI_ESC "7m"

#define FG_BLACK                    ANSI_ESC "30m"
#define FG_RED                      ANSI_ESC "31m"
#define FG_GREEN                    ANSI_ESC "32m"
#define FG_YELLOW                   ANSI_ESC "33m"
#define FG_BLUE                     ANSI_ESC "34m"
#define FG_MAGENTA                  ANSI_ESC "35m"
#define FG_CYAN                     ANSI_ESC "36m"
#define FG_WHITE                    ANSI_ESC "37m"

#define FG_BBLACK                   ANSI_ESC "90m"
#define FG_BRED                     ANSI_ESC "91m"
#define FG_BGREEN                   ANSI_ESC "92m"
#define FG_BYELLOW                  ANSI_ESC "93m"
#define FG_BBLUE                    ANSI_ESC "94m"
#define FG_BMAGENTA                 ANSI_ESC "95m"
#define FG_BCYAN                    ANSI_ESC "96m"
#define FG_BWHITE                   ANSI_ESC "97m"


void LogError(const std::string& Error);
void LogWarning(const std::string& Warn);
void LogPass(const std::string& Test);