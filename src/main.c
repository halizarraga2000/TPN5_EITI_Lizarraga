/* EITI - Universidad Nacional de Tucuman
 * Copyright 2022, Hugo Lizarraga <lizarragahugo@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \brief Simple sample of use LPC HAL gpio functions
 **
 ** \addtogroup samples Sample projects
 ** \brief Sample projects to use as a starting point
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "bsp.h"
#include <stdbool.h>
#include "pantalla.h"
#include "poncho.h"
#include "chip.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */


/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */

int main(void) {
    uint8_t numero[4] = {1,2,3,4};
    board_t board = BoardCreate();

    DisplayWriteBDC(board->display, numero, sizeof(numero));

    while (true) {
        DisplayRefresh(board->display);
        
//        if(refrescar){
//            //refrescar = false;
//            ScreenOff();
//            WriteNumber(screen[actual]);
//            SelectDigit(actual);
//        }
//        if (actual == 3) {
//            actual = 0;
//        } else {
//            actual = actual + 1;
//        }
//-----------------------------------------------------------
//        if (DigitalInputHasActivated(board->set_time)) {
//            if (valor == 9) {
//                valor = 0;
//            } else {
//                valor = valor + 1;
//            }
//            refrescar = true;
//        }
//        if (DigitalInputHasActivated(board->set_alarm)) {
//            if (valor == 0) {
//                valor = 9;
//            } else {
//                valor = valor - 1;
//            }
//            refrescar = true;
//        }
//        if (DigitalInputHasActivated(board->increment)) {
//            if (actual == 3) {
//                actual = 0;
//            } else {
//                actual = actual + 1;
//            }
//            refrescar = true;
//        }
//        if (DigitalInputHasActivated(board->decrement)) {
//            if (actual == 0) {
//                actual = 3;
//            } else {
//                actual = valor - 1;
//            }
//            refrescar = true;
//        }

//        for (int index = 0; index < 100; index++) {
            for (int delay = 0; delay < 2500; delay++) {
                __asm("NOP");
            }
//        }
    }
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
