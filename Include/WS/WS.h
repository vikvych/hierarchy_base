#ifndef HIERARCHY_WS_H
#define HIERARCHY_WS_H

#include "../Memory/MemoryLib.h"
#include "../MemoryBuffer/MemoryBufferLib.h"
#include "../SocketAddress/SocketAddressLib.h"
#include "../List/ListLib.h"
#include "../Timer/TimerLib.h"
#include "../TCP/TCPLib.h"
#include "../SSL/SSLLib.h"
#include "../HTTP/HTTPLib.h"
#include "../Base64/Base64Lib.h"
#include "../System/SystemLib.h"

#define WS_VERSION 13
#define WS_NONCE_SIZE 16
#define WS_TIMEOUT_CLOSE 3000
#define WS_BUFSIZE_MAX (20 * 1024 * 1024)
#define WS_MAGIC "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"

typedef struct {
    unsigned FIN:1;
    unsigned RSV1:1;
    unsigned RSV2:1;
    unsigned RSV3:1;
    unsigned OpCode:4;
    unsigned IsMasked:1;
    QWordT PayloadSize;
    ByteT Mask[4];
} WSHeaderT;

typedef void (WSOpenCb)(void *Argument);

typedef void (WSDataCb)(const WSHeaderT *Header,
                        MemoryBufferT *Data,
                        void *Argument);

typedef void (WSCloseCb)(ErrnoT Error,
                         void *Argument);

typedef void (WSShutdownCb)(void *Argument);

typedef enum {
    WS_OPCODE_CONTINUE = 0x00,
    WS_OPCODE_TEXT = 0x01,
    WS_OPCODE_BINARY = 0x02,
    WS_OPCODE_CLOSE = 0x08,
    WS_OPCODE_PING = 0x09,
    WS_OPCODE_PONG = 0x0A
} WSOpCodeT;

typedef enum {
    WS_CLOSECODE_NORMAL = 1000,
    WS_CLOSECODE_AWAY = 1001,
    WS_CLOSECODE_PROTOCOL_ERROR = 1002,
    WS_CLOSECODE_UNSUPPORTED_DATA = 1003,
    WS_CLOSECODE_INVALID_PAYLOAD = 1007,
    WS_CLOSECODE_POLICY_VIOLATION = 1008,
    WS_CLOSECODE_MESSAGE_TOO_BIG = 1009,
    WS_CLOSECODE_EXTENSION_ERROR = 1010,
    WS_CLOSECODE_INTERNAL_ERROR = 1011
} WSCloseCodeT;

typedef enum {
    WS_STATE_ACCEPTING = 0x00,
    WS_STATE_CONNECTING = 0x01,
    WS_STATE_OPEN = 0x02,
    WS_STATE_CLOSING = 0x03,
    WS_STATE_CLOSED = 0x04
} WSStateT;

WSCloseCodeT WSErrorToCloseCode(ErrnoT Error);

#endif
