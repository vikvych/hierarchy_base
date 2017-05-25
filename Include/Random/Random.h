#ifndef HIERARCHY_RANDOM_H
#define HIERARCHY_RANDOM_H

#include <stdint.h>

#ifdef WIN32
#include <WinSock2.h>
#endif
#include <openssl/rand.h>
#include <openssl/err.h>

#include "../Debug/DebugLib.h"

uint16_t RandomUInt16(void);
uint32_t RandomUInt32(void);
uint64_t RandomUInt64(void);

char RandomChar(void);
void RandomString(char *String, uint32_t Length);

void RandomBytes(uint8_t *Buffer, uint32_t Length);

#endif
