#ifndef THREEDIOT_H
#define THREEDIOT_H

/* Helper dùng chung cho các ví dụ của khóa học 3DIOT. */
#include <stdio.h>

#define LOG_INFO(fmt, ...)  printf("[INFO] " fmt "\n", ##__VA_ARGS__)
#define ARRAY_LEN(a)        (sizeof(a) / sizeof((a)[0]))

#endif /* THREEDIOT_H */
