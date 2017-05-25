#ifndef HIERARCHY_ERROR_H
#define HIERARCHY_ERROR_H

#include <errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifndef ENODATA
#define ENODATA 200
#endif

#ifndef EPROTO
#define EPROTO 201
#endif

#ifndef EBADMSG
#define EBADMSG 202
#endif

#ifndef EOVERFLOW
#define EOVERFLOW 203
#endif

#ifndef EDESTADDRREQ
#define EDESTADDRREQ 205
#endif

#ifndef EPROTONOSUPPORT
#define EPROTONOSUPPORT 206
#endif

#ifndef ENOTSUP
#define ENOTSUP 207
#endif

#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT 208
#endif

#ifndef EADDRNOTAVAIL
#define EADDRNOTAVAIL 209
#endif

#ifndef ECONNABORTED
#define ECONNABORTED 210
#endif

#ifndef ECONNRESET
#define ECONNRESET 211
#endif

#ifndef ENOTCONN
#define ENOTCONN 212
#endif

#ifndef ETIMEDOUT
#define ETIMEDOUT 213
#endif

#ifndef ECONNREFUSED
#define ECONNREFUSED 214
#endif

#ifndef EALREADY
#define EALREADY 215
#endif

#ifndef EINPROGRESS
#define EINPROGRESS 216
#endif

#ifndef EAUTH
#define EAUTH 217
#endif

#ifndef ENOSR
#define ENOSR 218
#endif

#ifndef ESUCCESS
#define ESUCCESS 0
#endif

typedef int32_t ErrnoT;

const char *ErrnoToString(ErrnoT ErrorCode,
                          char *ReasonString,
                          uint32_t ReasonStringLength);

#endif
