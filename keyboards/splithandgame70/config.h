#pragma once
#define MASTER_LEFT
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin
#define SERIAL_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral