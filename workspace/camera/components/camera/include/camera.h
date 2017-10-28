// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "esp_err.h"
#include "driver/ledc.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int pin_sscb_sda;       /*!< GPIO pin for camera SDA line */
    int pin_sscb_scl;       /*!< GPIO pin for camera SCL line */
    int pin_d7;             /*!< GPIO pin for camera D7 line */
    int pin_d6;             /*!< GPIO pin for camera D6 line */
    int pin_d5;             /*!< GPIO pin for camera D5 line */
    int pin_d4;             /*!< GPIO pin for camera D4 line */
    int pin_d3;             /*!< GPIO pin for camera D3 line */
    int pin_d2;             /*!< GPIO pin for camera D2 line */
    int pin_d1;             /*!< GPIO pin for camera D1 line */
    int pin_d0;             /*!< GPIO pin for camera D0 line */
    int pin_vsync;          /*!< GPIO pin for camera VSYNC line */
    int pin_rclk;           /*!< GPIO pin for camera RCLK line */
	int pin_rrst;			/*!< GPIO pin for camera RRST line */
	int pin_wrst;			/*!< GPIO pin for camera WRST line */
	int pin_wen;			/*!< GPIO pin for camera WEN line */
	int pin_oe;				/*!< GPIO pin for camera OE line */

    ledc_timer_t ledc_timer;        /*!< LEDC timer to be used for generating XCLK  */
    ledc_channel_t ledc_channel;    /*!< LEDC channel to be used for generating XCLK  */
} camera_config_t;

#define ESP_ERR_CAMERA_BASE 0x20000
#define ESP_ERR_CAMERA_NOT_DETECTED             (ESP_ERR_CAMERA_BASE + 1)
#define ESP_ERR_CAMERA_FAILED_TO_SET_FRAME_SIZE (ESP_ERR_CAMERA_BASE + 2)

/**
 * @brief Initialize the camera
 *
 * This function enables LEDC peripheral to generate XCLK signal,
 * detects and configures camera over I2C interface,
 * allocates framebuffer and DMA buffers,
 * initializes parallel I2S input, and sets up DMA descriptors.
 *
 * Currently camera is initialized in QVGA mode, and data is
 * converted into grayscale.
 *
 * Currently this function can only be called once and there is
 * no way to de-initialize this module.
 *
 * @param config  Camera configuration parameters
 * @return ESP_OK on success
 */
esp_err_t camera_init(const camera_config_t* config);


/**
 * @brief Obtain the pointer to framebuffer allocated by camera_init function.
 *
 * Currently framebuffer is grayscale, 8 bits per pixel.
 *
 * @return pointer to framebuffer
 */
uint8_t* camera_get_fb();

/**
 * @brief Get the width of framebuffer, in pixels.
 * @return width of framebuffer, in pixels
 */
int camera_get_fb_width();

/**
 * @brief Get the height of framebuffer, in pixels.
 * @return height of framebuffer, in pixels
 */
int camera_get_fb_height();

/**
 * @brief Acquire one frame and store it into framebuffer
 *
 * This function waits for the next VSYNC, starts DMA to get data from camera,
 * and blocks until all lines of the image are stored into the framebuffer.
 * Once all lines are stored, the function returns.
 *
 * @return ESP_OK on success
 */
esp_err_t camera_run();

/**
 * @brief Print contents of framebuffer on terminal
 *
 */
void camera_print_fb();


#ifdef __cplusplus
}
#endif
