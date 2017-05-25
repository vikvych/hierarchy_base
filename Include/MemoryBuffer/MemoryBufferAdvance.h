#ifndef HIERARCHY_MEMORYBUFFER_ADVANCE_H
#define HIERARCHY_MEMORYBUFFER_ADVANCE_H

#include "MemoryBufferT.h"

void MemoryBufferAdvancePosition(MemoryBufferT *MemoryBuffer,
                                 SizeT Position);
void MemoryBufferAdvanceEnd(MemoryBufferT *MemoryBuffer,
                            SizeT End);
void MemoryBufferAdvanceOffset(MemoryBufferT *MemoryBuffer,
                               SSizeT Offset);
void MemoryBufferAdvanceRewind(MemoryBufferT *MemoryBuffer);
void MemoryBufferAdvancePositionToEnd(MemoryBufferT *MemoryBuffer);

#endif
