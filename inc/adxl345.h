#ifndef ADXL345_H
#define ADXL345_H

/**
 * @brief Inicializa as variáveis utilizadas pelas funções do acelerômetro e
 * configura o timer de leitura dos dados.
 * 
 */
void adxl345_init();

/**
 * @brief Lê as acelerações nas direções x, y e z do acelerômetro e registra
 * esses valores (nessa ordem) no vetor readings.
 * 
 * @param readings Vetor de tamanho 3 onde serão escritas as leituras de aceleração do acelerômetro
 * @return 0, caso a leitura seja bem-sucedida. Caso contrário, retorna algum valor negativo
 */
int adxl345_read_acceleration(double readings[3]);

/**
 * @brief Fornece a velocidade do acelerômetro. Para obter a velocidade,
 * presume-se que a velocidade inicial (no momento em que a função adxl345_init
 * é chamada) é 0 e então a aceleração é lida periodicamente. A partir disso, determinamos
 * as variações da velocidade ao longo do tempo.
 * 
 * @param readings Vetor de tamanho 3 onde serão escritas as velocidades calculadas das direções x, y e z, nesta ordem
 */
void adxl345_read_speed(double readings[3]);

#endif