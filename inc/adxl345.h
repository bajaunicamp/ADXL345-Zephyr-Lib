#ifndef ADXL345_H
#define ADXL345_H

/**
 * @file
 * @brief Biblioteca para comunicação com o acelerômetro ADXL345.
 *
 * Este arquivo contém as definições e funções necessárias para inicializar 
 * e ler dados do acelerômetro ADXL345 de acordo com as necessidades da equipe
 * UNICAMP Baja SAE
 *
 * @author Lucas Mendonça
 */

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
 * @return 
 * - `0`: caso a leitura seja bem-sucedida 
 * - `< 0`: leitura mal-sucedida
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
