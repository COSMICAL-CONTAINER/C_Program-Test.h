#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>

#define ADDRESS(obj) ((size_t)&obj)

#define READ_ADDRESS_char(address)    (*(char *)(address))
#define READ_ADDRESS_uchar(address)   (*(unsigned char *)(address))

#define READ_ADDRESS_short(address)   (*(short *)(address))
#define READ_ADDRESS_ushort(address)  (*(unsigned short *)(address))

#define READ_ADDRESS_int(address)     (*(int *)(address))
#define READ_ADDRESS_uint(address)    (*(unsigned int *)(address))

#define READ_ADDRESS_float(address)   (*(float *)(address))
#define READ_ADDRESS_ufloat(address)  (*(unsigned float *)(address))

#define READ_ADDRESS_double(address)  (*(double *)(address))
#define READ_ADDRESS_udouble(address) (*(unsigned double *)(address))

// 1字节8位数据解析
typedef struct _data_char_structTypDef
{
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
}data_char_structTypeDef;

typedef union _data_char_union
{
    unsigned char all;
    data_char_structTypeDef decode;
}data_char_unionTypeDef;

// 解码char类型
void decode_char(char data_char)
{
    data_char_unionTypeDef char_A;

    char_A.all = data_char;
    printf("%d"  , char_A.decode.bit7);
    printf("%d"  , char_A.decode.bit6);
    printf("%d"  , char_A.decode.bit5);
    printf("%d " , char_A.decode.bit4);
    printf("%d"  , char_A.decode.bit3);
    printf("%d"  , char_A.decode.bit2);
    printf("%d"  , char_A.decode.bit1);
    printf("%d\n", char_A.decode.bit0);
}

// 4字节32位数据解析
typedef struct _data_int_structTypDef
{
    data_char_unionTypeDef byte0;
    data_char_unionTypeDef byte1;
    data_char_unionTypeDef byte2;
    data_char_unionTypeDef byte3;
}data_int_structTypeDef;

typedef union _data_int_union
{
    unsigned int all;
    data_int_structTypeDef decode;
}data_int_unionTypeDef;

// 解码int类型
void decode_int(unsigned int data_int) 
{
    data_int_unionTypeDef int_A_union;

    int_A_union.all = data_int;
    printf("Byte 3: ");
    decode_char(int_A_union.decode.byte3.all);
    printf("Byte 2: ");
    decode_char(int_A_union.decode.byte2.all);
    printf("Byte 1: ");
    decode_char(int_A_union.decode.byte1.all);
    printf("Byte 0: ");
    decode_char(int_A_union.decode.byte0.all);
}

// 8字节64位数据解析
typedef struct _data_long_structTypDef
{
    data_char_unionTypeDef byte0;
    data_char_unionTypeDef byte1;
    data_char_unionTypeDef byte2;
    data_char_unionTypeDef byte3;
    data_char_unionTypeDef byte4;
    data_char_unionTypeDef byte5;
    data_char_unionTypeDef byte6;
    data_char_unionTypeDef byte7;
}data_long_structTypeDef;

typedef union _data_long_union
{
    unsigned long long int all;
    data_long_structTypeDef decode;
}data_long_unionTypeDef;

// 解码long类型
void decode_long(unsigned long long int data_long) 
{
    data_long_unionTypeDef long_A_union;

    long_A_union.all = data_long;
    printf("Byte 7: ");
    decode_char(long_A_union.decode.byte7.all);
    printf("Byte 6: ");
    decode_char(long_A_union.decode.byte6.all);
    printf("Byte 5: ");
    decode_char(long_A_union.decode.byte5.all);
    printf("Byte 4: ");
    decode_char(long_A_union.decode.byte4.all);
    printf("Byte 3: ");
    decode_char(long_A_union.decode.byte3.all);
    printf("Byte 2: ");
    decode_char(long_A_union.decode.byte2.all);
    printf("Byte 1: ");
    decode_char(long_A_union.decode.byte1.all);
    printf("Byte 0: ");
    decode_char(long_A_union.decode.byte0.all);
}

#endif