#define ERROR_H
#ifdef ERROR_H

#pragma once

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR(x)                                                               \
  do {                                                                         \
    fprintf(stderr, "%s:%u @ %s: %s", __FILE__, __LINE__, #x,                  \
            strerror(errno));                                                  \
    abort();                                                                   \
  } while (0)

#endif