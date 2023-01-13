/* Copyright 2022, Laboratorio de Microprocesadores, EITI 
 * Universidad Nacional de Tucuman
 * Hugo A. Lizarraga <lizarragahugo@gmail.com>
 * ============================================================================
 */

/** @file bsp.c
 **
 ** @brief Plantilla de archivos fuente
 **
 ** Plantilla para los archivos de codigo fuente de prácticos de las 
 ** asignaturas Diseño Integrado de Sistemas Emebebidos y Sistemas Embebidos
 ** de Tiempo Real dictadas en de la Especialización en Integración de
 ** Sistemas Informaticos de la Univesidad Nacional de Tucumán
 ** 
 ** | RV | YYYY.MM.DD | Autor       | Descripción de los cambios              |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.11.23 | Lizarraga H.| Version inicial del archivo             |
 ** 
 ** @defgroup plantilla Plantilals de Archivos
 ** @brief Plantillas de archivos normalizadas
 ** @{ 
 */

/* === Inclusiones de cabeceras ============================================ */
#include "bsp.h"
#include "chip.h"
#include "poncho.h"


/* === Definicion y Macros privados ======================================== */

/* === Declaraciones de tipos de datos privados ============================ */

/* === Definiciones de variables privadas ================================== */
static struct board_s board = {0};

/* === Definiciones de variables publicas ================================== */

/* === Declaraciones de funciones privadas ================================= */
static void DigitsInit(void);
static void SegmentsInit(void);
static void BuzzerInit(void);
static void KeyInit(void);

static void DisplayInit(void);
static void ScreenOff();
static void WriteNumber(uint8_t segments);
static void SelectDigit(uint8_t digit);

/* === Definiciones de funciones privadas ================================== */
void DigitsInit(void){
    Chip_SCU_PinMuxSet(DIGIT_1_PORT, DIGIT_1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | DIGIT_1_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_1_GPIO, DIGIT_1_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, DIGIT_1_GPIO, DIGIT_1_BIT, true);

    Chip_SCU_PinMuxSet(DIGIT_2_PORT, DIGIT_2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | DIGIT_2_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_2_GPIO, DIGIT_2_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, DIGIT_2_GPIO, DIGIT_2_BIT, true);

    Chip_SCU_PinMuxSet(DIGIT_3_PORT, DIGIT_3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | DIGIT_3_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_3_GPIO, DIGIT_3_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, DIGIT_3_GPIO, DIGIT_3_BIT, true);

    Chip_SCU_PinMuxSet(DIGIT_4_PORT, DIGIT_4_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | DIGIT_4_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, DIGIT_4_GPIO, DIGIT_4_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, DIGIT_4_GPIO, DIGIT_4_BIT, true);
}

void SegmentsInit(void){
    Chip_SCU_PinMuxSet(SEGMENT_A_PORT, SEGMENT_A_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_A_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_A_GPIO, SEGMENT_A_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_A_GPIO, SEGMENT_A_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_B_PORT, SEGMENT_B_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_B_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_B_GPIO, SEGMENT_B_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_B_GPIO, SEGMENT_B_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_C_PORT, SEGMENT_C_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_C_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_C_GPIO, SEGMENT_C_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_C_GPIO, SEGMENT_C_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_D_PORT, SEGMENT_D_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_D_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_D_GPIO, SEGMENT_D_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_D_GPIO, SEGMENT_D_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_E_PORT, SEGMENT_E_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_E_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_E_GPIO, SEGMENT_E_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_E_GPIO, SEGMENT_E_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_F_PORT, SEGMENT_F_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_F_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_F_GPIO, SEGMENT_F_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_F_GPIO, SEGMENT_F_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_G_PORT, SEGMENT_G_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_G_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_G_GPIO, SEGMENT_G_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_G_GPIO, SEGMENT_G_BIT, true);

    Chip_SCU_PinMuxSet(SEGMENT_P_PORT, SEGMENT_P_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | SEGMENT_P_FUNC);
    Chip_GPIO_SetPinState(LPC_GPIO_PORT, SEGMENT_P_GPIO, SEGMENT_P_BIT, false);
    Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, SEGMENT_P_GPIO, SEGMENT_P_BIT, true);
}

void BuzzerInit(void){
    Chip_SCU_PinMuxSet(BUZZER_PORT, BUZZER_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | BUZZER_FUNC);
    board.buzzer = DigitalOutputCreate (BUZZER_GPIO,BUZZER_BIT);
}

void KeyInit(void){
    Chip_SCU_PinMuxSet(KEY_F1_PORT, KEY_F1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_F1_FUNC);
    board.set_time = DigitalInputCreate (KEY_F1_GPIO, KEY_F1_BIT, true);

    Chip_SCU_PinMuxSet(KEY_F2_PORT, KEY_F2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_F2_FUNC);
    board.set_alarm = DigitalInputCreate (KEY_F2_GPIO, KEY_F2_BIT, true);

    Chip_SCU_PinMuxSet(KEY_F3_PORT, KEY_F3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_F3_FUNC);
    board.decrement = DigitalInputCreate (KEY_F3_GPIO, KEY_F3_BIT, true);

    Chip_SCU_PinMuxSet(KEY_F4_PORT, KEY_F4_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_F4_FUNC);
    board.increment = DigitalInputCreate (KEY_F4_GPIO, KEY_F4_BIT, true);

    Chip_SCU_PinMuxSet(KEY_ACCEPT_PORT, KEY_ACCEPT_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_ACCEPT_FUNC);
    board.accept = DigitalInputCreate (KEY_ACCEPT_GPIO, KEY_ACCEPT_BIT, true);

    Chip_SCU_PinMuxSet(KEY_CANCEL_PORT, KEY_CANCEL_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | KEY_CANCEL_FUNC);
    board.cancel = DigitalInputCreate (KEY_CANCEL_GPIO, KEY_CANCEL_BIT, true);
}

void DisplayInit(void){
    static const struct display_driver_s display_driver = {
        .ScreenTurnOff = ScreenOff,
        .SegmentsTurnOn = WriteNumber,
        .DigitTurnOn = SelectDigit,
    };
    board.display = DisplayCreate(4, &display_driver);
}

void ScreenOff(){
    Chip_GPIO_ClearValue (LPC_GPIO_PORT, DIGITS_GPIO, DIGITS_MASK);
    Chip_GPIO_ClearValue (LPC_GPIO_PORT, SEGMENTS_GPIO, SEGMENTS_MASK);
}

void WriteNumber(uint8_t segments){
    Chip_GPIO_SetValue (LPC_GPIO_PORT, SEGMENTS_GPIO, segments);
}

void SelectDigit(uint8_t digit){
    Chip_GPIO_SetValue (LPC_GPIO_PORT, DIGITS_GPIO, (1<<digit));
}


/* === Definiciones de funciones publicas ================================== */
board_t BoardCreate (void) {
    BuzzerInit();
    KeyInit();
    DigitsInit();
    SegmentsInit();
    DisplayInit();  //<----

    return & board;
}

/* === Ciere de documentacion ============================================== */

/** @} Final de la definición del modulo para doxygen */

