#ifndef HIERARCHY_COMPRESSION_H
#define HIERARCHY_COMPRESSION_H

#include "../Memory/MemoryLib.h"
#include "../MemoryBlock/MemoryBlockLib.h"

/*static const DWordT CRC32Table[16] = { 0X00000000,
                                       0X1DB71064,
                                       0X3B6E20C8,
                                       0X26D930AC,
                                       0X76DC4190,
                                       0X6B6B51F4,
                                       0X4DB26158,
                                       0X5005713C,
                                       0XEDB88320,
                                       0XF00F9344,
                                       0XD6D6A3E8,
                                       0XCB61B38C,
                                       0X9B64C2B0,
                                       0X86D3D2D4,
                                       0XA00AE278,
                                       0XBDBDF21C
                                     };

typedef struct {
  const unsigned char *next_in;     // pointer to next byte to read
  unsigned int avail_in;            // number of bytes available at next_in
  mz_ulong total_in;                // total number of bytes consumed so far

  unsigned char *next_out;          // pointer to next byte to write
  unsigned int avail_out;           // number of bytes that can be written to next_out
  mz_ulong total_out;               // total number of bytes produced so far

  char *msg;                        // error msg (unused)
  struct mz_internal_state *state;  // internal state, allocated by zalloc/zfree

  mz_alloc_func zalloc;             // optional heap allocation function (defaults to malloc)
  mz_free_func zfree;               // optional heap free function (defaults to free)
  void *opaque;                     // heap alloc function user pointer

  int data_type;                    // data_type (unused)
  mz_ulong adler;                   // adler32 of the source or uncompressed data
  mz_ulong crc32;                   // crc32 of the source or uncompressed data
  mz_ulong reserved;
} CompressionStreamT;*/

#endif
