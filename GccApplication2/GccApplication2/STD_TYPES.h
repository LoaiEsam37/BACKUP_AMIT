#ifndef STD_TYPES_H
#define STD_TYPES_H


typedef unsigned char         u8;
typedef signed char         s8;

typedef unsigned short int   u16;
typedef signed short int     s16;

typedef unsigned long int    u32;
typedef signed long int      s32;

typedef float                f32;
typedef double               f64;


typedef enum {
	FALSE,
	TRUE,
} bool_t;


typedef enum {
	E_OK,
	E_NOK,
} ErrorStatus_t;


#define NULL_PTR ((void*)0)

#ifndef NULL
#define NULL ((void*)0)
#endif


#endif // !STD_TYPES_H