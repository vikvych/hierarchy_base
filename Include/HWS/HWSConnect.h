#ifndef HIERARCHY_HWS_CONNECT_H
#define HIERARCHY_HWS_CONNECT_H

#include "HWS.h"
#include "HWSConnection.h"
#include "HWSSocket.h"

HWSConnectionT *HWSConnect(HWSSocketT *HWSSocket,
                           char *Host,
                           WordT Port,
                           char *Path,
                           char *UA,
                           char *DNSAddress,
                           WordT DNSPort,
                           ECCryptoModeT CryptoMode,
                           char *RootPublicKeyX,
                           char *RootPublicKeyY,
                           HWSOpenCb *OpenCb,
                           HWSDataCb *DataCb,
                           HWSCloseCb *CloseCb,
                           DWordT KeepAliveInterval,
                           void *Argument);

#endif
