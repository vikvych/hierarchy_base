#ifndef HIERARCHY_MEMORYBUFFER_LIB_H
#define HIERARCHY_MEMORYBUFFER_LIB_H

#include "MemoryBufferT.h"
#include "MemoryBufferAdvance.h"
#include "MemoryBufferClone.h"
#include "MemoryBufferData.h"
#include "MemoryBufferFill.h"
#include "MemoryBufferLeft.h"
#include "MemoryBufferDebug.h"
#include "MemoryBufferPrint.h"
#include "MemoryBufferRead.h"
#include "MemoryBufferRealloc.h"
#include "MemoryBufferReset.h"
#include "MemoryBufferShift.h"
#include "MemoryBufferSpace.h"
#include "MemoryBufferTrim.h"
#include "MemoryBufferWrite.h"

extern const struct MemoryBufferLibrary {
    MemoryBufferT *(*Init)(SizeT BytesLength);

    MemoryBufferT *(*InitRef)(MemoryBufferT *MemoryBuffer);

    void (*InitNull)(MemoryBufferT *MemoryBuffer);

    void (*Reset)(MemoryBufferT *MemoryBuffer);

    ErrnoT (*Realloc)(MemoryBufferT *MemoryBuffer,
                      SizeT BytesLength);

    void (*Trim)(MemoryBufferT *MemoryBuffer);

    ErrnoT (*Shift)(MemoryBufferT *MemoryBuffer,
                    SSizeT Shift);

    ErrnoT (*Fill)(MemoryBufferT *MemoryBuffer,
                   ByteT Byte,
                   SizeT Count);

    ErrnoT (*Print)(PrintT *Print,
                    const MemoryBufferT *MemoryBuffer);

    ByteT *(*Data)(const MemoryBufferT *MemoryBuffer);

    SizeT (*Left)(const MemoryBufferT *MemoryBuffer);

    SizeT (*Space)(const MemoryBufferT *MemoryBuffer);

    void (*Debug)(const char *Prefix, MemoryBufferT *MemoryBuffer);

    struct {
        MemoryBufferT *(*MemoryBuffer)(MemoryBufferT *MemoryBuffer);
        char *(*String)(MemoryBufferT *MemoryBuffer,
                        SizeT StringLength);
    } Clone;

    struct {
        void (*Position)(MemoryBufferT *MemoryBuffer, SizeT Position);

        void (*End)(MemoryBufferT *MemoryBuffer, SizeT End);

        void (*Offset)(MemoryBufferT *MemoryBuffer, SSizeT Offset);

        void (*Rewind)(MemoryBufferT *MemoryBuffer);

        void (*PositionToEnd)(MemoryBufferT *MemoryBuffer);
    } Advance;

    struct {
        ErrnoT (*Data)(MemoryBufferT *MemoryBuffer,
                       const ByteT *Data,
                       SizeT BytesLength);

        ErrnoT (*Byte)(MemoryBufferT *MemoryBuffer,
                        ByteT Value);

        ErrnoT (*Word)(MemoryBufferT *MemoryBuffer,
                         uint16_t Value);

        ErrnoT (*DWord)(MemoryBufferT *MemoryBuffer,
                         uint32_t Value);

        ErrnoT (*QWord)(MemoryBufferT *MemoryBuffer,
                         uint64_t Value);

        ErrnoT (*String)(MemoryBufferT *MemoryBuffer,
                          const char *String);

        ErrnoT (*MemoryBlock)(MemoryBufferT *MemoryBuffer,
                               const MemoryBlockT *MemoryBlock);

        ErrnoT (*VPrint)(MemoryBufferT *MemoryBuffer,
                          const char *Format,
                          va_list ArgsPtr);

        ErrnoT (*Print)(MemoryBufferT *MemoryBuffer,
                         const char *Format,
                         ...);

        ErrnoT (*MemoryBlockWithExcluding)(MemoryBufferT *MemoryBuffer,
                                            const MemoryBlockT *MemoryBlock,
                                            const MemoryBlockT *ExcludingOfMemoryBlock);

    } Write;

    struct {
        ErrnoT (*Data)(MemoryBufferT *MemoryBuffer,
                       ByteT *Data,
                       SizeT Size);

        ByteT (*Byte)(MemoryBufferT *MemoryBuffer);

        uint16_t (*Word)(MemoryBufferT *MemoryBuffer);

        uint32_t (*DWord)(MemoryBufferT *MemoryBuffer);

        uint64_t (*QWord)(MemoryBufferT *MemoryBuffer);

        ErrnoT (*String)(MemoryBufferT *MemoryBuffer,
                         char *String,
                         SizeT Size);
    } Read;
} MemoryBufferLib;

#endif
