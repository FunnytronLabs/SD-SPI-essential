/*
 * Adapted from: https://github.com/espressif/arduino-esp32/tree/master/libraries/SD
 */

/*
 * pin 1 - not used          |  Micro SD card     |
 * pin 2 - CS (SS)           |                   /
 * pin 3 - DI (MOSI)         |                  |__
 * pin 4 - VDD (3.3V)        |                    |
 * pin 5 - SCK (SCLK)        | 8 7 6 5 4 3 2 1   /
 * pin 6 - VSS (GND)         | ▄ ▄ ▄ ▄ ▄ ▄ ▄ ▄  /
 * pin 7 - DO (MISO)         | ▀ ▀ █ ▀ █ ▀ ▀ ▀ |
 * pin 8 - not used          |_________________|
 *                             ║ ║ ║ ║ ║ ║ ║ ║
 *                     ╔═══════╝ ║ ║ ║ ║ ║ ║ ╚═════════╗
 *                     ║         ║ ║ ║ ║ ║ ╚══════╗    ║
 *                     ║   ╔═════╝ ║ ║ ║ ╚═════╗  ║    ║
 * Connections for     ║   ║   ╔═══╩═║═║═══╗   ║  ║    ║
 * full-sized          ║   ║   ║   ╔═╝ ║   ║   ║  ║    ║
 * SD card             ║   ║   ║   ║   ║   ║   ║  ║    ║
 * Pin name         |  -  DO  VSS SCK VDD VSS DI CS    -  |
 * SD pin number    |  8   7   6   5   4   3   2   1   9 /
 *                  |                                  █/
 *                  |__▍___▊___█___█___█___█___█___█___/
 *
 * Note:  The SPI pins can be manually configured by using `SPI.begin(sck, miso, mosi, cs).`
 *        Alternatively, you can change the CS pin and use the other default settings by using `SD.begin(cs)`.
 *
 * +--------------+---------+-------+----------+----------+----------+
 * | SPI Pin Name | ESP8266 | ESP32 | ESP32-S2 | ESP32-C3 | ESP32-S3 |
 * +==============+=========+=======+==========+==========+==========+
 * | CS (SS)      | GPIO15  | GPIO5 | GPIO5    | GPIO13   | GPIO13   |
 * +--------------+---------+-------+----------+----------+----------+
 * | DI (MOSI)    | GPIO13  | GPIO23| GPIO24   | GPIO14   | GPIO14   |
 * +--------------+---------+-------+----------+----------+----------+
 * | DO (MISO)    | GPIO12  | GPIO19| GPIO25   | GPIO15   | GPIO15   |
 * +--------------+---------+-------+----------+----------+----------+
 * | SCK (SCLK)   | GPIO14  | GPIO18| GPIO19   | GPIO16   | GPIO16   |
 * +--------------+---------+-------+----------+----------+----------+
 *
 * For more info see file README.md in this library or on URL:
 * https://github.com/espressif/arduino-esp32/tree/master/libraries/SD
 */

// === INCLUDES === //
#include "FS.h"
#include "SD.h"
#include "SPI.h"


// === PROTOTYPES === //
void listDir(fs::FS &fs, const char * dirname, uint8_t levels);
void createDir(fs::FS &fs, const char * path);
void removeDir(fs::FS &fs, const char * path);
void readFile(fs::FS &fs, const char * path);
void writeFile(fs::FS &fs, const char * path, const char * message);
void appendFile(fs::FS &fs, const char * path, const char * message);
void renameFile(fs::FS &fs, const char * path1, const char * path2);
void deleteFile(fs::FS &fs, const char * path);
void testFileIO(fs::FS &fs, const char * path);

void SD_SPI_initialise(int sck, int miso, int mosi, int cs);
