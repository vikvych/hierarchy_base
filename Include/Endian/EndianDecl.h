#ifndef ENDIAN_DECL_H
#define ENDIAN_DECL_H

#define ENDIAN_LITTLE 0
#define ENDIAN_BIG 1
#define ENDIAN_UNKNOWN 2

#define LITTLE_ENDIAN_STRING 0x41424344UL
#define BIG_ENDIAN_STRING 0x44434241UL
#define ENDIAN_ORDER ('ABCD')

#if ENDIAN_ORDER == BIG_ENDIAN_STRING
#   define ENDIAN ENDIAN_BIG
#else
#   if ENDIAN_ORDER == LITTLE_ENDIAN_STRING
#       define ENDIAN ENDIAN_LITTLE
#   else
#       error "Endian: Invalid"
#   endif
#endif

#endif
