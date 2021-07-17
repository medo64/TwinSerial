#include <stdint.h>
#include "Microchip/usb.h"
#include "Microchip/usb_device.h"
#include "Microchip/usb_device_cdc.h"
#include "app.h"

bool processInput(const uint8_t* data, const uint8_t count, bool* out_LastUseLarge);
bool processCommand(const uint8_t* data, const uint8_t count);
void initOled(void);
uint8_t nibbleToHex(const uint8_t value);
bool hexToNibble(const uint8_t hex, uint8_t* nibble);

#define LED_TIMEOUT       20
#define LED_TIMEOUT_NONE  65535
uint16_t LedTimeout = LED_TIMEOUT_NONE;

void main(void) {
    init();

    USBDeviceInit();
    USBDeviceAttach();

    while(true) {
#if defined(USB_POLLING)
        USBDeviceTasks();
#endif

        if (USBGetDeviceState() < CONFIGURED_STATE) { continue; }
        if (USBIsDeviceSuspended()) { continue; }

        CDCTxService();
    }
}