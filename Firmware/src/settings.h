#ifndef SETTINGS_H
#define	SETTINGS_H

#define SETTING_DEFAULT_I2C_ADDRESS         0x3C
#define SETTING_DEFAULT_I2C_SPEED_INDEX     1
#define SETTING_DEFAULT_DISPLAY_HEIGHT      64
#define SETTING_DEFAULT_DISPLAY_BRIGHTNESS  0xCF
#define SETTING_DEFAULT_DISPLAY_INVERSE     0

#define _SETTINGS_FLASH_RAW {                                                                \
                              0, 0, 0, 0,                                                    \
                              0, 0,                                                          \
                              26, 0x03,                                                      \
                              'E', 0, 'A', 0, '9', 0, 'E', 0,                                \
                              '1', 0, '9', 0, '7', 0, '9', 0,                                \
                              '2', 0, '8', 0, '0', 0, '1', 0                                 \
                            }  // reserving space because erase block is block 32-word (32-bytes as only low bytes are used)
#define _SETTINGS_FLASH_LOCATION 0x1FE0
const uint8_t _SETTINGS_PROGRAM[] __at(_SETTINGS_FLASH_LOCATION) = _SETTINGS_FLASH_RAW;

typedef struct {
    uint8_t Reserved[6];
    uint8_t UsbSerialLength;
    uint8_t UsbSerialType;
    uint8_t UsbSerialValue[24];
} SettingsRecord;

SettingsRecord Settings;


/** Initializes settings. */
void settings_init();

/** Saves settings to EEPROM. */
void settings_save();


#endif	/* SETTINGS_H */
