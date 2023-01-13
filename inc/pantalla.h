/* Copyright 2022, Laboratorio de Microprocesadores, EITI 
 * Universidad Nacional de Tucuman
 * Hugo A. Lizarraga <lizarragahugo@gmail.com>
 * ============================================================================
 */

#ifndef PANTALLA_H   /*! @cond    */
#define PANTALLA_H   /*! @endcond */

/** @file pantalla.h
 **
 ** @brief Pantalla de archivos de cabecera 
 **
 ** Plantilla para los archivos de cabeceras de las prácticos de las 
 ** asignaturas Diseño Integrado de Sistemas Emebebidos y Sistemas Embebidos
 ** de Tiempo Real dictadas en de la Especialización en Integración de
 ** Sistemas Informaticos de la Univesidad Nacional de Tucumán
 ** 
 ** | RV | YYYY.MM.DD | Autor       | Descripción de los cambios              |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.11.29 | Lizarraga H.| Version inicial del archivo             |
 ** 
 ** @defgroup pantalla de Archivos
 ** @brief Pantalla de archivos normalizadas
 ** @{ 
 */

/* === Inclusiones de archivos externos ==================================== */
#include <stdint.h>

/* === Cabecera C++ ======================================================== */
#ifdef __cplusplus
extern "C" {
#endif

/* === Definicion y Macros publicos ======================================== */
//Definiciones de bits asociados a cada segmento para construir los digitos
#define SEGMENT_A (1 << 0)
#define SEGMENT_B (1 << 1)
#define SEGMENT_C (1 << 2)
#define SEGMENT_D (1 << 3)
#define SEGMENT_E (1 << 4)
#define SEGMENT_F (1 << 5)
#define SEGMENT_G (1 << 6)
#define SEGMENT_P (1 << 7)

/* == Declaraciones de tipos de datos publicos ============================= */
//! Referencia a un descriptor para gestinar una pantalla de Siete Segmentos Multiplexada
typedef struct display_s * display_t;

typedef void(*display_screen_off_t)(void);

typedef void(*display_segments_on_t)(uint8_t segments);

typedef void(*display_digit_on_t)(uint8_t digit);

typedef struct display_driver_s{
    display_screen_off_t ScreenTurnOff;
    display_segments_on_t SegmentsTurnOn;
    display_digit_on_t DigitTurnOn;
}const * display_driver_t;

/* === Declaraciones de variables publicas ================================= */
/**
 * @brief Metodo para crear una pantalla multiplexada de 7 segmentos
 * 
 * @param digits Cantidad de digitos que forman la pantalla multiplexada
 * @return display_t Puntero al descriptor de la pantalla creada
 */
display_t DisplayCreate(uint8_t digits, display_driver_t driver);

/**
 * @brief Funcion para escribir un numero BCD en la pantalla de 7 segmentos
 * 
 * @param display Puntero al descripor de la pantalla en la que se escribe
 * @param number Puntero el primer elemento de numero BDC al ecribir
 * @param size Cantidad de elementos en el vector que contienen al numero BDC
 */
void DisplayWriteBDC(display_t display, uint8_t * number, uint8_t size);

/**
 * @brief Funcion para refrescar la pantalla
 * 
 * @param display Puntero al descriptor de la pantalla que se debe refrescar
 */
void DiplayRefresh(display_t display);

/* === Declaraciones de funciones publicas ================================= */

/* === Ciere de documentacion ============================================== */
#ifdef __cplusplus
}
#endif

/** @} Final de la definición del modulo para doxygen */

#endif   /* PANTALLA_H */
