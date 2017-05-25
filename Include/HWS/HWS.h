#ifndef HIERARCHY_HWS_H
#define HIERARCHY_HWS_H

#include "../WS/WSLib.h"
#include "../EON/EONLib.h"
#include "../ECGamal/ECGamalLib.h"
#include "../Compression/GZIPLib.h"
#include "../AES/AESLib.h"
#include "../SHA2/SHA2Lib.h"

typedef enum {
    HWS_STATE_ACCEPTING = 0x00,
    HWS_STATE_CONNECTING = 0x01,
    HWS_STATE_OPEN = 0x02,
    HWS_STATE_CLOSING = 0x03,
    HWS_STATE_CLOSED = 0x04
} HWSStateT;

typedef void (HWSOpenCb)(void *HWSConnectionV, void *Argument);

typedef void (HWSDataCb)(void *HWSConnectionV, ObjectT *Data, void *Argument);

typedef void (HWSCloseCb)(void *HWSConnectionV, ErrnoT Error, void *Argument);

typedef void (HWSShutdownCb)(void *HWSConnectionV);

#endif
