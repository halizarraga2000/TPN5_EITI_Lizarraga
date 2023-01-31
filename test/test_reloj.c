#include "clock.h"
#include "unity.h"

/*
x-> 1) Configurar la libreria, consultar la hora y tiene que ser invalida.
x-> 2) Configurar la libraria, ajustar la hora (con valores correctos), consultar la hora y tiene que ser valida.
3) Configurar la libraria, ajustar la hora (con valores incorrectos) tiene devolver un error y consultar la hora y tiene que ser invalida.
x-> 4) Simular el paso de n ciclos de reloj, consultar la hora y verificar que avano un segunto.
5) Simular el paso de 10*n ciclos, consultar la hora y verificar que avanzo diez segundos
..... Y varias igual
6) Configurar la hora de la alarma (con valores correctos) y revisar si la guarda.
7) Configurar la hora de la alarma (con valores incorrectos) y revisar si la rechaze.
8) Configurar la hora de la alarma (con valores correctos) y revisar si la queda activada.
9) Si la alarma esta activa y la desactiva, queda desactiva, pero no cambia la hora.
10) Si la alarma esta desactiva y la activa, queda activa, pero no cambia la hora.
11) Si la alarma esta activa y la hora del reloj coincide con la hora de la alarma, entonces suena.
12) Si la se activo, y las pospongo n minutos, vuelve a sonar n minutos
13) Si la se activo, y la cancelo, al dia siguente, vuelve a sonar
*/

#define TICKS_PER_SECOND 5

clock_t reloj;

void SimulateSeconds(int seconds) {
    for(int index = 0; index < seconds * TICKS_PER_SECOND; index++){
        ClockNewTick(reloj);
    }
}

void setUp(void){
    static const uint8_t INICIAL[] = {1, 2, 3, 4};
    reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetupTime(reloj, INICIAL, sizeof(INICIAL));  

}
// Configurar la libreria, consultar la hora y tiene que ser invalida.

void test_start_up(void){
    static const uint8_t ESPERADO[] = {0, 0, 0, 0, 0, 0};

    uint8_t hora[6];
    uint8_t alarma[4];
    reloj = ClockCreate(TICKS_PER_SECOND);

    TEST_ASSERT_FALSE(ClockGetTime(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
    TEST_ASSERT_FALSE(ClockGetAlarm(reloj, alarma, sizeof(alarma)));
}

// Configurar la libraria, ajustar la hora (con valores correctos), consultar la hora y tiene que ser valida.

void test_set_up_current_time(void){
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 0};
    uint8_t hora[6];
    TEST_ASSERT_TRUE(ClockGetTime(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}

// Simular el paso de n ciclos de reloj, consultar la hora y verificar que avano un segunto.

void test_one_second_elapsed(void){
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 0, 1};
    uint8_t hora[6];

    SimulateSeconds(1);
    ClockGetTime(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}

void test_ten_second_elapsed(void){
    static const uint8_t ESPERADO[] = {1, 2, 3, 4, 1, 0};
    uint8_t hora[6];

    SimulateSeconds(10);
    ClockGetTime(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}

void test_one_minute_elapsed(void){
    static const uint8_t ESPERADO[] = {1, 2, 3, 5, 0, 0};
    uint8_t hora[6];

    SimulateSeconds(60);
    ClockGetTime(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}

void test_ten_minutes_elapsed(void){
    static const uint8_t ESPERADO[] = {1, 2, 4, 4, 0, 0};
    uint8_t hora[6];

    SimulateSeconds(10 * 60);
    ClockGetTime(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}

void test_setup_and_get_alarm(void){
    static const uint8_t ALARMA[] = {1, 2, 3, 5};
    uint8_t hora[4];

    ClockSetupAlarm(reloj, ALARMA, sizeof(ALARMA));
    TEST_ASSERT_TRUE(ClockGetAlarm(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ALARMA, hora, sizeof(ALARMA));
}

void test_setup_and_disable_alarm(void){
    static const uint8_t ALARMA[] = {1, 2, 3, 5};
    uint8_t hora[4];

    ClockSetupAlarm(reloj, ALARMA, sizeof(ALARMA));
    TEST_ASSERT_FALSE(ClockToggleAlarm(reloj));

    TEST_ASSERT_FALSE(ClockGetAlarm(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ALARMA, hora, sizeof(ALARMA));
}


/*
void test_one_hour_elapsed(void){
    static const uint8_t ESPERADO[] = {1, 3, 3, 4, 0, 0};
    uint8_t hora[6];

    SimulateSeconds(ONE_HOUR);
    ClockGetTime(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}

void test_ten_hour_elapsed(void){
    static const uint8_t ESPERADO[] = {2, 2, 3, 4, 0, 0};
    uint8_t hora[6];
    
    SimulateSeconds(TEN_HOURS);
    ClockGetTime(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}
*/