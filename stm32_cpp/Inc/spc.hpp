#pragma once

#include <memory>
#include <map>
#include "driver.hpp"

enum class MainPageType {
    Default,
    Actual,
    Program,
};

enum class SubPageType {
    HeatTemp,
    HeatStatus,
    SystemStatus,
    Temp,
    TempA,
    ConfigInt16,
    StatusTemp,
    StatusInt16,
    Energy,
    HeatOnPer,
    Cost,
    HeatOnTime,
    ResetStatis,
    FirmwareVer,
};

class IMainPage {
public:
    ~IMainPage() = default;
    virtual void Right() = 0;
    virtual void Increase() = 0;
    virtual void Show() = 0;
};

class ISinglePC {
public:
    ~ISinglePC() = default;
    virtual void Right() = 0;
    virtual void Increase() = 0;
};

// sub page
class SubPage {
public:
    SubPage(
        int, 
        SubPageType,
        IMainPage&);
public:
    void Right();
    void Show();
private:
    int                                        iIndex;
    int                                        iParentIndex;
    SubPageType                                iType;
    IMainPage&                                 iParent;
};

// main page
class MainPage
    : public IMainPage {
public:
    MainPage(
        int,
        int,
        MainPageType,
        ISinglePC&);
public:
    void Right() override;
    void Increase() override;
    void Show() override;
private:
    int                                        iIndex;
    int                                        iMaxPages;
    int                                        iParentIndex;
    MainPageType                               iType;
    ISinglePC&                                 iParent;
    std::map<int, std::shared_ptr<SubPage>>    iSubPages;
};

// spc
class SinglePC
    : public ISinglePC {
public:
    SinglePC(std::shared_ptr<HardwareDriver>);
public:
    void Right() override;
    void Increase() override;
private:
    int                                        iIndex;
    int                                        iMaxPages;
    std::shared_ptr<HardwareDriver>            iStm32;
    std::map<int, std::shared_ptr<MainPage>>   iMainPages;
};
