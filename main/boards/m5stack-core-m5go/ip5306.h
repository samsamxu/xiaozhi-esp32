// ip5306.h
#ifndef IP5306_H
#define IP5306_H

#include "i2c_device.h"

class IP5306 : public I2cDevice {
public:
    // IP5306 I2C地址通常为0x75
    static constexpr uint8_t DEFAULT_ADDRESS = 0x75;
    
    explicit IP5306(i2c_master_bus_handle_t i2c_bus, uint8_t addr = DEFAULT_ADDRESS);

    // 电源状态寄存器地址（根据IP5306规格书）
    static constexpr uint8_t REG_CHG_STATUS    = 0x70; // 状态读取寄存器
    static constexpr uint8_t REG_BAT_LEVEL    = 0x78; 

    // 获取电池电量百分比
    float GetBatteryLevel();
    // 是否正在充电
    bool IsCharging();

    // 是否充满电
    bool IsChargeFull();

    // 获取电源状态寄存器原始值
    uint8_t GetPowerStatus();
    uint8_t getBatteryLevelReg();
};

#endif // IP5306_H
