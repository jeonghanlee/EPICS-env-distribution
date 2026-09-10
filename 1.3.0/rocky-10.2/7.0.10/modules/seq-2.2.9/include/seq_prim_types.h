/*************************************************************************\
Copyright (c) 2010-2015 Helmholtz-Zentrum Berlin f. Materialien
                        und Energie GmbH, Germany (HZB)
This file is distributed subject to a Software License Agreement found
in the file LICENSE that is included with this distribution.
\*************************************************************************/
#ifndef INCLseq_prim_typesh
#define INCLseq_prim_typesh

#ifdef __cplusplus
extern "C" {
#endif

enum prim_type_tag {
    P_CHAR,
    P_UCHAR,
    P_SHORT,
    P_USHORT,
    P_INT,
    P_UINT,
    P_LONG,
    P_ULONG,
    P_INT8T,
    P_UINT8T,
    P_INT16T,
    P_UINT16T,
    P_INT32T,
    P_UINT32T,
    P_FLOAT,
    P_DOUBLE,
    P_STRING,
};

#ifdef declare_prim_type_names

#ifndef prim_types_GLOBAL
extern
#endif
const char *prim_type_name[]
#ifdef prim_types_GLOBAL
= {
    "char",
    "unsigned char",
    "short",
    "unsigned short",
    "int",
    "unsigned int",
    "long",
    "unsigned long",
    "epicsInt8",
    "epicsUInt8",
    "epicsInt16",
    "epicsUInt16",
    "epicsInt32",
    "epicsUInt32",
    "float",
    "double",
    "string",
}
#endif
;

#ifndef prim_types_GLOBAL
extern
#endif
const char *prim_type_tag_name[]
#ifdef prim_types_GLOBAL
= {
    "P_CHAR",
    "P_UCHAR",
    "P_SHORT",
    "P_USHORT",
    "P_INT",
    "P_UINT",
    "P_LONG",
    "P_ULONG",
    "P_INT8T",
    "P_UINT8T",
    "P_INT16T",
    "P_UINT16T",
    "P_INT32T",
    "P_UINT32T",
    "P_FLOAT",
    "P_DOUBLE",
    "P_STRING",
}
#endif
;

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif	/*INCLseq_prim_typesh*/
