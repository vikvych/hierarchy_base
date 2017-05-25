#ifndef HIERARCHY_MEMORYBUFFER_WRITE_H
#define HIERARCHY_MEMORYBUFFER_WRITE_H

#include "MemoryBufferT.h"
#include "../MemoryBlock/MemoryBlockT.h"

#include <stdarg.h>

ErrnoT MemoryBufferWriteData(MemoryBufferT *MemoryBuffer,
                             const ByteT *Data,
                             SizeT BytesLength);

ErrnoT MemoryBufferWriteByte(MemoryBufferT *MemoryBuffer,
                              ByteT Value);

ErrnoT MemoryBufferWriteWord(MemoryBufferT *MemoryBuffer,
                               uint16_t Value);

ErrnoT MemoryBufferWriteDWord(MemoryBufferT *MemoryBuffer,
                               uint32_t Value);

ErrnoT MemoryBufferWriteQWord(MemoryBufferT *MemoryBuffer,
                               uint64_t Value);

ErrnoT MemoryBufferWriteString(MemoryBufferT *MemoryBuffer,
                               const char *String);

ErrnoT MemoryBufferWriteMemoryBlock(MemoryBufferT *MemoryBuffer,
                                    const MemoryBlockT *MemoryBlock);

ErrnoT MemoryBufferWriteVPrint(MemoryBufferT *MemoryBuffer,
                               const char *Format,
                               va_list ArgsPtr);

ErrnoT MemoryBufferWritePrint(MemoryBufferT *MemoryBuffer,
                              const char *Format,
                              ...);

ErrnoT MemoryBufferWriteMemoryBlockWithExcluding(MemoryBufferT *MemoryBuffer,
                                                 const MemoryBlockT *MemoryBlock,
                                                 const MemoryBlockT *ExcludingOfMemoryBlock);

#endif
