// ip5306.cc
#include "ip5306.h"
#include "board.h"
#include "display.h"

#include <esp_log.h>

#define TAG "IP5306"

IP5306::IP5306(i2c_master_bus_handle_t i2c_bus, uint8_t addr)
    : I2cDevice(i2c_bus, addr) {}

uint8_t IP5306::GetPowerStatus() {
    return ReadReg(REG_CHG_STATUS);
}

uint8_t IP5306::getBatteryLevelReg() {
    return ReadReg(REG_BAT_LEVEL);
}
bool IP5306::IsCharging() {
    // 第3位表示充电状态：0-未充电，1-充电中
    return (GetPowerStatus() & 0x08) != 0;
}

bool IP5306::IsChargeFull() {
    // 第4位表示充满状态：0-未充满，1-已充满
    return (GetPowerStatus() & 0x10) != 0;
}

float IP5306::GetBatteryLevel() {
    // 根据规格书，电量等级划分（示例值，需要根据实际规格校准）
    const uint8_t level_bits = (getBatteryLevelReg() >> 4) & 0x0F;
    
    switch (level_bits) {
        case 0x00: return 100;
        case 0x08: return 75;
        case 0x0C: return 50;
        case 0x0E: return 25;
        default:   return 0;
    }
}
