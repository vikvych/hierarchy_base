#ifndef HIERARCHY_EON_LIB_H
#define HIERARCHY_EON_LIB_H

#include "UndefinedT.h"
#include "Undefined/UndefinedParse.h"
#include "Undefined/UndefinedSerialize.h"
#include "Undefined/UndefinedClone.h"
#include "Undefined/UndefinedSet.h"

#include "NullT.h"
#include "Null/NullParse.h"
#include "Null/NullSerialize.h"
#include "Null/NullClone.h"
#include "Null/NullSet.h"
#include "Null/NullGet.h"

#include "BooleanT.h"
#include "Boolean/BooleanParse.h"
#include "Boolean/BooleanSerialize.h"
#include "Boolean/BooleanClone.h"
#include "Boolean/BooleanGet.h"
#include "Boolean/BooleanSet.h"

#include "NumberT.h"
#include "Number/NumberParse.h"
#include "Number/NumberSerialize.h"
#include "Number/NumberClone.h"
#include "Number/NumberGet.h"
#include "Number/NumberSet.h"
#include "Number/NumberIsInt.h"
#include "Number/NumberIsDouble.h"

#include "StringT.h"
#include "String/StringParse.h"
#include "String/StringSerialize.h"
#include "String/StringClone.h"
#include "String/StringGet.h"
#include "String/StringSet.h"
#include "String/StringSize.h"

#include "ByteStringT.h"
#include "ByteString/ByteStringParse.h"
#include "ByteString/ByteStringSerialize.h"
#include "ByteString/ByteStringClone.h"
#include "ByteString/ByteStringGet.h"
#include "ByteString/ByteStringSet.h"
#include "ByteString/ByteStringSize.h"

#include "ArrayT.h"
#include "Array/ArrayParse.h"
#include "Array/ArraySerialize.h"
#include "Array/ArrayClone.h"
#include "Array/ArrayPush.h"
#include "Array/ArrayUnshift.h"
#include "Array/ArrayPop.h"
#include "Array/ArrayShift.h"
#include "Array/ArrayClear.h"
#include "Array/ArrayChangeSize.h"
#include "Array/ArrayRemove.h"
#include "Array/ArrayDelete.h"
#include "Array/ArrayGet.h"
#include "Array/ArraySet.h"
#include "Array/ArrayElementType.h"
#include "Array/ArraySize.h"
#include "Array/ArrayIsTypeOf.h"

#include "ObjectT.h"
#include "Object/ObjectDebug.h"
#include "Object/ObjectParse.h"
#include "Object/ObjectSerialize.h"
#include "Object/ObjectClone.h"
#include "Object/ObjectGet.h"
#include "Object/ObjectSet.h"
#include "Object/ObjectDelete.h"
#include "Object/ObjectIsExists.h"
#include "Object/ObjectIsTypeOf.h"
#include "Object/ObjectElementType.h"
#include "Object/ObjectSize.h"
#include "Object/ObjectKeys.h"

extern const struct EONLibrary {
    struct {
        ObjectT *(*Init)(void);

        ObjectT *(*Clone)(ObjectT *ObjectOld);

        void (*Debug)(const char *Prefix,
                      ObjectT *Object);

        ObjectT *(*Parse)(MemoryBufferT *ThisBuffer);

        MemoryBufferT *(*Serialize)(ObjectT *Object);

        struct {
            ListT *(*Keys)(ObjectT *Object);

            AbstractT *(*Get)(ObjectT *Object,
                              char *Key);

            ErrnoT (*Set)(ObjectT *Object,
                          char *Key,
                          void *Value);

            bool (*IsExists)(ObjectT *Object,
                             char *Key);

            void (*Delete)(ObjectT *Object,
                           char *Key);

            EONTypeT (*ElementType)(ObjectT *Object,
                                    char *Key);

            bool (*IsTypeOf)(ObjectT *Object,
                             char *Key,
                             EONTypeT ValueType);

            SizeT (*Size)(ObjectT *Object);
        } Simple;

        struct {
            ListT *(*Keys)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount);

            AbstractT *(*Get)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount);

            ErrnoT (*Set)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount,
                          AbstractT *Value);

            bool (*IsExists)(ObjectT *Object,
                             char *Key[],
                             SizeT KeyCount);

            void (*Delete)(ObjectT *Object,
                           char *Key[],
                           SizeT KeyCount);

            EONTypeT (*ElementType)(ObjectT *Object,
                                    char *Key[],
                                    SizeT KeyCount);

            bool (*IsTypeOf)(ObjectT *Object,
                             char *Key[],
                             SizeT KeyCount,
                             EONTypeT ValueType);

            ErrnoT (*Size)(SizeT *Size,
                           ObjectT *Object,
                           char *Key[],
                           SizeT KeyCount);
        } Chain;
    } Object;

    struct {
        UndefT *(*Init)(void);
        UndefT *(*Clone)(UndefT *UndefinedOld);
        ErrnoT (*Set)(ObjectT *Object,
                      char *Key[],
                      SizeT KeyCount);
    } Undefined;

    struct {
        NullT *(*Init)(void);
        NullT *(*Clone)(NullT *NullOld);
        ErrnoT (*Set)(ObjectT *Object,
                      char *Key[],
                      SizeT KeyCount);
        NullT *(*Get)(ObjectT *Object,
                      char *Key[],
                      SizeT KeyCount);
    } Null;

    struct {
        BoolT *(*Init)(bool Value);
        BoolT *(*Clone)(BoolT *BooleanOld);

        struct {
            bool (*Get)(ObjectT *Object,
                        char *Key);

            ErrnoT (*Set)(ObjectT *Object,
                          char *Key,
                          bool Value);
        } Simple;

        struct {
            bool (*Get)(ObjectT *Object,
                        char *Key[],
                        SizeT KeyCount);

            ErrnoT (*Set)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount,
                          bool Value);
        } Chain;
    } Boolean;

    struct {
        NumberT *(*InitInt)(int64_t Value);
        NumberT *(*InitDouble)(double Value);
        NumberT *(*Clone)(NumberT *NumberOld);

        struct {
            int64_t (*GetInt)(ObjectT *Object,
                              char *Key);

            double (*GetDouble)(ObjectT *Object,
                                char *Key);

            ErrnoT (*SetInt)(ObjectT *Object,
                             char *Key,
                             int64_t Value);

            ErrnoT (*SetDouble)(ObjectT *Object,
                                char *Key,
                                double Value);

            bool (*IsInt)(ObjectT *Object,
                          char *Key);

            bool (*IsDouble)(ObjectT *Object,
                             char *Key);
        } Simple;

        struct {
            int64_t (*GetInt)(ObjectT *Object,
                              char *Key[],
                              SizeT KeyCount);

            double (*GetDouble)(ObjectT *Object,
                                char *Key[],
                                SizeT KeyCount);

            ErrnoT (*SetInt)(ObjectT *Object,
                             char *Key[],
                             SizeT KeyCount,
                             int64_t Value);

            ErrnoT (*SetDouble)(ObjectT *Object,
                                char *Key[],
                                SizeT KeyCount,
                                double Value);

            bool (*IsInt)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount);

            bool (*IsDouble)(ObjectT *Object,
                             char *Key[],
                             SizeT KeyCount);
        } Chain;
    } Number;

    struct {
        StringT *(*Init)(char *Value);
        StringT *(*Clone)(StringT *StringOld);

        struct {
            char *(*Get)(ObjectT *Object,
                         char *Key);

            ErrnoT (*Set)(ObjectT *Object,
                          char *Key,
                          char *Value);

            ErrnoT (*CharSize)(SizeT *Size,
                               ObjectT *Object,
                               char *Key);

            ErrnoT (*ByteSize)(SizeT *Size,
                               ObjectT *Object,
                               char *Key);
        } Simple;

        struct {
            char *(*Get)(ObjectT *Object,
                         char *Key[],
                         SizeT KeyCount);

            ErrnoT (*Set)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount,
                          char *Value);

            ErrnoT (*CharSize)(SizeT *Size,
                               ObjectT *Object,
                               char *Key[],
                               SizeT KeyCount);

            ErrnoT (*ByteSize)(SizeT *Size,
                               ObjectT *Object,
                               char *Key[],
                               SizeT KeyCount);
        } Chain;
    } String;

    struct {
        ByteStringT *(*Init)(MemoryBufferT *MemoryBuffer);
        ByteStringT *(*Clone)(ByteStringT *StringOld);

        struct {
            MemoryBufferT *(*Get)(ObjectT *Object,
                                  char *Key);

            ErrnoT (*Set)(ObjectT *Object,
                          char *Key,
                          MemoryBufferT *Value);

            ErrnoT (*Size)(SizeT *Size,
                           ObjectT *Object,
                           char *Key);
        } Simple;

        struct {
            MemoryBufferT *(*Get)(ObjectT *Object,
                                  char *Key[],
                                  SizeT KeyCount);

            ErrnoT (*Set)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount,
                          MemoryBufferT *Value);

            ErrnoT (*Size)(SizeT *Size,
                           ObjectT *Object,
                           char *Key[],
                           SizeT KeyCount);
        } Chain;
    } ByteString;

    struct {
        ArrayT *(*Init)(void);
        ArrayT *(*Clone)(ArrayT *ArrayOld);
        ArrayT *(*Parse)(MemoryBufferT *ThisBuffer);
        MemoryBufferT *(*Serialize)(ArrayT *Array);
        struct {
            AbstractT *(*Get)(ArrayT *Array,
                              SizeT Index);

            ErrnoT (*Set)(ArrayT *Array,
                          SizeT Index,
                          AbstractT *Value);

            void (*Clear)(ArrayT *Array);

            void (*Remove)(ArrayT *Array,
                           SizeT Index);

            void (*Delete)(ArrayT *Array,
                           SizeT Index);

            ErrnoT (*ChangeSize)(ArrayT *Array,
                                 SizeT NewLength);

            EONTypeT (*ElementType)(ArrayT *Array,
                                    SizeT Index);

            bool (*IsTypeOf)(ArrayT *Array,
                             SizeT Index,
                             EONTypeT Type);

            SizeT (*Size)(ArrayT *Array);

            ErrnoT (*Push)(ArrayT *Array,
                           AbstractT *Value);

            ErrnoT (*Unshift)(ArrayT *Array,
                              AbstractT *Value);

            ErrnoT (*Pop)(AbstractT **Value,
                          ArrayT *Array);

            ErrnoT (*Shift)(AbstractT **Value,
                            ArrayT *Array);

        } Simple;

        struct {
            AbstractT *(*Get)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount,
                          SizeT Index);


            ErrnoT (*Set)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount,
                          SizeT Index,
                          AbstractT *Value);

            void (*Clear)(ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount);


            void (*Remove)(ObjectT *Object,
                           char *Key[],
                           SizeT KeyCount,
                           SizeT Index);

            void (*Delete)(ObjectT *Object,
                           char *Key[],
                           SizeT KeyCount,
                           SizeT Index);

            void (*ChangeSize)(ObjectT *Object,
                               char *Key[],
                               SizeT KeyCount,
                               SizeT NewLength);

            EONTypeT (*ElementType)(ObjectT *Object,
                                    char *Key[],
                                    SizeT KeyCount,
                                    SizeT Index);

            bool (*IsTypeOf)(ObjectT *Object,
                             char *Key[],
                             SizeT KeyCount,
                             SizeT Index,
                             EONTypeT Type);

            ErrnoT (*Size)(SizeT *Size,
                           ObjectT *Object,
                           char *Key[],
                           SizeT KeyCount);

            ErrnoT (*Push)(ObjectT *Object,
                           char *Key[],
                           SizeT KeyCount,
                           AbstractT *Value);

            ErrnoT (*Unshift)(ObjectT *Object,
                              char *Key[],
                              SizeT KeyCount,
                              AbstractT *Value);

            ErrnoT (*Pop)(AbstractT **Value,
                          ObjectT *Object,
                          char *Key[],
                          SizeT KeyCount);

            ErrnoT (*Shift)(AbstractT **Value,
                            ObjectT *Object,
                            char *Key[],
                            SizeT KeyCount);
        } Chain;
    } Array;


} EONLib;


#endif
