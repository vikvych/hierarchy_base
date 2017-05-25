#ifndef HIERARCHY_WS_SEND_H
#define HIERARCHY_WS_SEND_H

#include "WS.h"
#include "WSConnection.h"

ErrnoT WSVSend(WSConnectionT *Connection,
               WSOpCodeT OpCode,
               WSCloseCodeT scode,
               const char *Format,
               va_list ArgsPtr);

ErrnoT WSSend(WSConnectionT *WSConnection,
              WSOpCodeT OpCode,
              const char *Format,
              ...);

#endif
