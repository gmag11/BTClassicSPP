// Copyright 2018 Evandro Luis Copercini
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _BLUETOOTH_SERIAL_H_
#define _BLUETOOTH_SERIAL_H_

#include "sdkconfig.h"

#if defined(CONFIG_BT_ENABLED) && defined(CONFIG_BLUEDROID_ENABLED)

#include "Arduino.h"
#include "Stream.h"
#include <esp_spp_api.h>
#include <esp_gap_bt_api.h>

class BluetoothSerial: public Stream
{
    public:

        BluetoothSerial(void);
        ~BluetoothSerial(void);

		bool begin (String localName = String (), esp_spp_role_t role = ESP_SPP_ROLE_SLAVE, String bda_name = String (), esp_bd_addr_t destAddress = 0, esp_bt_pin_code_t pin_code = 0, uint8_t pin_length = 0);
        int available(void);
        int peek(void);
        bool hasClient(void);
        int read(void);
        size_t write(uint8_t c);
        size_t write(const uint8_t *buffer, size_t size);
        void flush();
        void end(void);
        esp_err_t register_callback(esp_spp_cb_t * callback);

    private:
        String local_name;
		esp_spp_role_t own_role;
		String slave_name;
		esp_bd_addr_t slave_address = { 0,0,0,0,0,0 };

};

#endif

#endif
