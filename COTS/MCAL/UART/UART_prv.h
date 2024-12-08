#ifndef UART_PRV_H
#define UART_PRV_H

#define UART_u8_UDR_REG         *((volatile u8*)(0x2C))

#define UART_u8_UCSRA_REG       *((volatile u8*)(0x2B))  
#define UCSRA_RXC_BIT       7
#define UCSRA_TXC_BIT       6
#define UCSRA_UDRE_BIT      5

#define UART_u8_UCSRB_REG       *((volatile u8*)(0x2A))
#define UCSRB_RXCIE_BIT     7
#define UCSRB_TXCIE_BIT     6
#define UCSRB_UDRIE_BIT     5
#define UCSRB_RXEN_BIT      4
#define UCSRB_TXEN_BIT      3
#define UCSRB_UCSZ2_BIT     2

#define UART_u8_UCSRC_REG       *((volatile u8*)(0x40))     
#define UCSRC_URSEL_BIT     7
#define UCSRC_UMSEL_BIT     6
#define UCSRC_UPM1_BIT      5
#define UCSRC_UPM0_BIT      4
#define UCSRC_USBS_BIT      3
#define UCSRC_UCSZ1_BIT     2
#define UCSRC_UCSZ0_BIT     1

#define UART_u8_UBRRH_REG       *((volatile u8*)(0x40))
#define UART_u8_UBRRL_REG       *((volatile u8*)(0x29))
/*---------------------------------UART Configuratios---------------------------------*/
/*UART Transmitter and Receiver enable*/
#define UART_TRANSMITTE_ENABLE          1
#define UART_TRANSMITTE_DISABLE         3

#define UART_RECEIVE_ENABLE             2
#define UART_RECEIVE_DISABLE            4

/*UART Parity Modes*/
#define UART_PARITY_DISABLE             1
#define UART_PARITY_EVEN                2
#define UART_PARITY_ODD                 3

/*UART NO.Stop Bits*/
#define UART_STOP_BIT_1               1
#define UART_STOP_BIT_2               2

/*UART Char Size*/
#define UART_CHARCHTER_SIZE_5           5
#define UART_CHARCHTER_SIZE_6           6
#define UART_CHARCHTER_SIZE_7           7
#define UART_CHARCHTER_SIZE_8           8
#define UART_CHARCHTER_SIZE_9           9
#endif /*UART_PRV_H**/



