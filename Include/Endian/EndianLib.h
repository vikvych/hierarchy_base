#ifndef ENDIAN_H
#define ENDIAN_H

#include "../Memory/MemoryLib.h"

#include "../System/SystemLib.h"
#include "EndianHToNWord.h"
#include "EndianHToNDWord.h"
#include "EndianHToNQWord.h"
#include "EndianHToNDouble.h"
#include "EndianHToNFloat.h"

#include "EndianNToHWord.h"
#include "EndianNToHDWord.h"
#include "EndianNToHQWord.h"
#include "EndianNToHDouble.h"
#include "EndianNToHFloat.h"

#include "EndianWordToBE.h"
#include "EndianWordToLE.h"
#include "EndianDWordToBE.h"
#include "EndianDWordToLE.h"
#include "EndianQWordToBE.h"
#include "EndianQWordToLE.h"
#include "EndianDoubleToBE.h"
#include "EndianDoubleToLE.h"
#include "EndianFloatToBE.h"
#include "EndianFloatToLE.h"

extern const struct EndianLibrary {
    struct {
        WordT (*Word)(WordT Number);
        DWordT (*DWord)(DWordT Number);
        QWordT (*QWord)(QWordT Number);
        double (*Double)(double Number);
        float (*Float)(float Number);
    } HtoN;

    struct {
        WordT (*Word)(WordT Number);
        DWordT (*DWord)(DWordT Number);
        QWordT (*QWord)(QWordT Number);
        double (*Double)(double Number);
        float (*Float)(float Number);
    } NtoH;

    struct {
        WordT (*Word)(WordT Word);
        DWordT (*DWord)(DWordT DoubleWord);
        QWordT (*QWord)(QWordT QuadWord);
        double (*Double)(double Double);
        float (*Float)(float Float);
    } ToBigEndian;

    struct {
        WordT (*Word)(WordT Word);
        DWordT (*DWord)(DWordT DoubleWord);
        QWordT (*QWord)(QWordT QuadWord);
        double (*Double)(double Double);
        float (*Float)(float Float);
    } ToLittleEndian;

} EndianLib;


#endif
