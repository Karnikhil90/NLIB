#ifndef NLIB_H
#define NLIB_H

// Standard Input/Output
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <errno.h>

// Math and Number Operations
#include <math.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <complex.h>

// Data Structures
#include <stddef.h>   // size_t, ptrdiff_t, NULL
#include <stdint.h>   // int8_t, int16_t, int32_t, int64_t
#include <assert.h>   // assert macro
#include <stdbool.h>  // bool type

// File Handling
#include <fcntl.h>
#include <unistd.h>   // read/write/close
#include <sys/types.h>
#include <sys/stat.h>

// String Manipulations
#include <strings.h>  // POSIX string functions
#include <wchar.h>
#include <wctype.h>

// Misc Utilities
#include <signal.h>
#include <setjmp.h>
#include <locale.h>

// Optional / System Specific
#ifdef _WIN32
#include <windows.h>
#endif

#endif // NLIB_H