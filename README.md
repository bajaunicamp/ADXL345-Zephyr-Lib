# Biblioteca para uso do ADXL345

Essa biblioteca fornece o código necessário para controlar um acelerômetro ADXL345 a partir de um STM Blue Pill (STM32F103C6T6 ou STM32F103C8T6). 

## Como conectar o sensor
- Caso queira ler os logs do STM, conecte o RX de um leitor UART ao pino A9.
- Conecte o pino GND ao ground.
- Conecte o pino VCC+5V a uma fonte de tensão de 5V.
- Conecte o pino SCL ao pino A5 do STM.
- Conecte o pino SDA ao pino A7 do STM.
- Conecte o pino CS ao pino A4 do STM.
- Conecte o pino SDO ao pino A6 do STM.
- Energize o STM.

## Como usar a biblioteca
1. Execute a função **adxl345_init**. Essa função pode ser executada sempre que for necessário reiniciar o registro de velocidade.

2. Em seguida, basta utilizar as funções **adxl345_read_acceleration** e **adxl345_read_speed** para ler a aceleração e a velocidade conforme necessário.

## Sobre os logs do STM
Caso haja algum problema ao se comunicar com o sensor, será emitido um log de erro.


## Possíveis problemas / problemas conhecidos
- É possível melhorar a precisão da leitura de velocidade se os interrupts gerados pelo sensor forem utilizados.
