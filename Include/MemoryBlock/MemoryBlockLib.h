#ifndef HIERARCHY_MEMORY_BLOCK_LIB_H
#define HIERARCHY_MEMORY_BLOCK_LIB_H

#include "MemoryBlockT.h"
#include "MemoryBlockAdvance.h"
#include "MemoryBlockSet.h"
#include "MemoryBlockCompare.h"
#include "MemoryBlockIsSet.h"
#include "MemoryBlockDup.h"
#include "MemoryBlockSearch.h"
#include "MemoryBlockRead.h"
#include "MemoryBlockCopy.h"
#include "MemoryBlockDebug.h"

extern const struct MemoryBlockLibrary {
    struct {
        void (*String)(MemoryBlockT *MemoryBlock,
                       const char *String);

        void (*MemoryBuffer)(MemoryBlockT *MemoryBlock,
                             const MemoryBufferT *MemoryBuffer);
    } Set;

    bool (*IsSet)(const MemoryBlockT *MemoryBlock);

    const char *(*Search)(const MemoryBlockT *MemoryBlock,
                            char Char);

    void (*Advance)(MemoryBlockT *MemoryBlock, SSizeT Shifting);
    void (*Debug)(const char *Prefix, MemoryBlockT *MemoryBlock);

    struct {
        uint32_t (*BinToUInt32)(const MemoryBlockT *MemoryBlock);
        uint32_t (*HexToUInt32)(const MemoryBlockT *MemoryBlock);
        uint64_t (*BinToUInt64)(const MemoryBlockT *MemoryBlock);
        uint64_t (*HexToUInt64)(const MemoryBlockT *MemoryBlock);
        double (*BinToDouble)(const MemoryBlockT *MemoryBlock);
    } Read;

    struct {
        ErrnoT (*MemoryBlock)(const MemoryBlockT *MemoryBlock1,
                               const MemoryBlockT *MemoryBlock2);

        ErrnoT (*MemoryBlockI)(const MemoryBlockT *MemoryBlock1,
                                const MemoryBlockT *MemoryBlock2);

        ErrnoT (*String)(const MemoryBlockT *MemoryBlock,
                          const char *String);

        ErrnoT (*StringI)(const MemoryBlockT *MemoryBlock,
                           const char *String);
    } Compare;

    struct {
        ErrnoT (*MemoryBlock)(MemoryBlockT *Destination,
                               const MemoryBlockT *Source);

        ErrnoT (*String)(char **Destination,
                          const MemoryBlockT *Source);
    } Dup;

    struct {
        ErrnoT (*String)(const MemoryBlockT *MemoryBlock,
                         char *StringBuffer,
                         SizeT StringBufferLength);
    } Copy;
} MemoryBlockLib;

#endif
