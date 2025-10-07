#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(REG,BIT)     (REG |= (1<<BIT))

#define CLR_BIT(REG,BIT)     (REG &= ~(1<<BIT))

#define TOG_BIT(REG,BIT)     (REG ^= (1<<BIT))

#define GET_BIT(REG,BIT)     ((REG >> BIT) & 1)


#define SET_REG(REG)         (REG = 0xFF)

#define CLR_REG(REG)         (REG = 0x00)

#define TOG_REG(REG)         (REG ^= 0xFF)

#define GET_REG(REG)         (REG)


#endif // !BIT_MATH_H