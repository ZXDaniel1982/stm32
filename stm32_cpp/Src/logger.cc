#include <logger.hpp>

void
STM32F103VET_LOGGER::Register(
    ODevice                         aDevice,
    std::shared_ptr<ILoggerHandle>  aLogger)
{
    iDeviceLogger.try_emplace(aDevice, aLogger);
}

void
STM32F103VET_LOGGER::WriteLine(
    ODevice         aDevice,
    std::string     aInfo)
{
    auto logger = iDeviceLogger.at(aDevice);
    logger->Write(aInfo);
}