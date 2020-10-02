 
#pragma once

#include <unordered_map>
#include <memory>

enum class ODevice: unsigned int {
    LCD,
    USART,
};

class ILoggerHandle {
public:
    ~ILoggerHandle() = default;
    virtual void Write(std::string aInfo) = 0;
};

class IDeviceLogger {
public:
    ~IDeviceLogger() = default;
    virtual void Register(ODevice, std::shared_ptr<ILoggerHandle>) = 0;
    virtual void WriteLine(ODevice, std::string) = 0;
};

class STM32F103VET_LOGGER : public IDeviceLogger {
public:
    void Register(ODevice, std::shared_ptr<ILoggerHandle>) override;
    void WriteLine(ODevice, std::string) override;
private:
    std::unordered_map<ODevice, std::shared_ptr<ILoggerHandle>> iDeviceLogger;
};