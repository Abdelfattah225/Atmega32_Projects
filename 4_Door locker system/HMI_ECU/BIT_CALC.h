


#ifndef BIT_CALC_H_
#define	BIT_CALC_H_


#define Set_Bit(var,Bit_No) (var)|=(1<<(Bit_No))

#define Clear_Bit(var,Bit_No) (var)&=(~(1<<(Bit_No)))

#define Toggle_Bit(var,Bit_No) (var)^= (1<<(Bit_No))

#define Get_Bit(var,Bit_No) (((var)>>(Bit_No))&(1))

#define Assign_Bit(var,Bit_No,val) do{if(val==1)\
									Set_Bit(var,Bit_No);\
									else\
									Clear_Bit(var,Bit_No);}while(0)

#define Assgn_2Bits(var , pos , val)    ((var)=  ( (var ) &  ~((0b11)<<(pos)) )  | ( ((0b11)&(val)) << (pos)  )  )	\

#define SET_NIBBLE(byte, position, value) \
    ((byte) = ((byte) & ~(0xF << ((position) * 4))) | (((value) & 0xF) << ((position) * 4)))

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )
#endif /* BIT_CALC_H_ */
