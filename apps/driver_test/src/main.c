/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <assert.h>
#include <string.h>
#include <os/os.h>

#include "sysinit/sysinit.h"
#include "syscfg/syscfg.h"
//#include <pwm/pwm.h>
#include <qdec/qdec.h>
#include "qdec_nrf52/qdec_nrf52.h"


#include "bsp/bsp.h"
//#include "drv8838/drv8838.h"
#ifdef ARCH_sim
#include "mcu/mcu_sim.h"
#endif
#define P0_4 (4)
//static volatile int g_task1_loops;

/* For LED toggling */
int g_led_pin;
//struct pwm_dev *pwm;
struct qdec_dev *qdec;
//uint16_t max_val;
/**
 * main
 *
 * The main task for the project. This function initializes packages,
 * and then blinks the BSP LED in a loop.
 *
 * @return int NOTE: this function should never return!
 */
int
main(int argc, char **argv)
{
//    struct pwm_chan_cfg chan_conf = {
//        .pin = P0_4,
//        .inverted = false,
//        .data = NULL
//    };
//    uint32_t base_freq;

    sysinit();

//    /* PWM Testing */
//
//    pwm = (struct pwm_dev *) os_dev_open("pwm0", 0, NULL);
//
//    /* set the PWM frequency */
//    pwm_set_frequency(pwm, 10000);
//    base_freq = pwm_get_clock_freq(pwm);
//    max_val = (uint16_t) (base_freq / 10000);
//
//    /* setup led 1 - 100% duty cycle*/
//    pwm_chan_config(pwm, 0, &chan_conf);
//    pwm_enable_duty_cycle(pwm, 0, max_val/160);

    /* QDEC Testing */

//    int16_t acc;
//    int16_t accdbl;

    qdec = (struct qdec_dev *) os_dev_open("qdec0", 0, NULL);
//    qdec_accumulators_read(qdec, &acc, &accdbl);


    while (1) {
        os_eventq_run(os_eventq_dflt_get());
    }
    assert(0);
    return(0);
//    int rc;
//
//#ifdef ARCH_sim
//    mcu_sim_parse_args(argc, argv);
//#endif
//
//    sysinit();
//
//    struct os_dev motor_driver;
//    struct drv8838_cfg motor_driver_config = {
//            .enable_pin = 4,
//            .phase_pin = 5,
//            .sleep_pin = 2
//        };
//;
////    motor_driver_config->enable_pin = 1;
////    motor_driver_config->phase_pin = 2;
////    motor_driver_config->sleep_pin = 3;
//
//    drv8838_init(&motor_driver, &motor_driver_config);
//    drv8838_open((struct drv8838_dev *)&motor_driver);
////    drv8838_open((struct drv8838_driver)motor_driver);
//
////    g_led_pin = LED_BLINK_PIN;
////    hal_gpio_init_out(g_led_pin, 1);
//
//    while (1) {
//        ++g_task1_loops;
//
//        /* Wait one second */
//        os_time_delay(OS_TICKS_PER_SEC);
//
//        /* Toggle the LED */
////        hal_gpio_toggle(g_led_pin);
//    }
//    assert(0);
//
//    return rc;
}

