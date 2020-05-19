#include <iostream>
#include "spc.hpp"

using namespace std;

static const std::map<MainPageType, std::string> kMainPages = {
    {MainPageType::Default,   "Default"},
    {MainPageType::Actual,    "Actual"},
    {MainPageType::Program,   "Program"}
};

static const std::map<SubPageType, std::string> kSubPages = {
    {SubPageType::HeatTemp,   "HeatTemp"},
    {SubPageType::HeatStatus,    "HeatStatus"},
    {SubPageType::SystemStatus,   "SystemStatus"},
    {SubPageType::HeatTemp,   "Temp"},
    {SubPageType::HeatStatus,    "TempA"}
};

SubPage::SubPage(
    int         aIndex,
    SubPageType aType,
    IMainPage&  aMain)
    :   iIndex        (1)
    ,   iParentIndex  (aIndex)
    ,   iType         (aType)
    ,   iParent       (aMain)
{
}

void
SubPage::Right()
{
    iParent.Increase();
    iParent.Show();
}

void
SubPage::Show()
{
    cout << kSubPages.at(iType) << endl << endl;
}

MainPage::MainPage(
    int                         aIndex,
    int                         aMaxPages,
    MainPageType                aType,
    ISinglePC&                  aSPC)
    :   iIndex        (1)
    ,   iMaxPages     (aMaxPages)
    ,   iParentIndex  (aIndex)
    ,   iType         (aType)
    ,   iParent       (aSPC)
{
    switch (aType) {
    case MainPageType::Default:
        {
            iSubPages.try_emplace(1, new SubPage(1, SubPageType::HeatTemp, *this));
            iSubPages.try_emplace(2, new SubPage(2, SubPageType::HeatStatus, *this));
            iSubPages.try_emplace(3, new SubPage(3, SubPageType::SystemStatus, *this));
        }
        break;
    case MainPageType::Actual:
        {
            iSubPages.try_emplace(1, new SubPage(1, SubPageType::SystemStatus, *this));
            iSubPages.try_emplace(2, new SubPage(2, SubPageType::Temp, *this));
            iSubPages.try_emplace(3, new SubPage(3, SubPageType::TempA, *this));
            /*iSubPages.try_emplace(4, new SubPage(4, SubPageType::Temp));
            iSubPages.try_emplace(5, new SubPage(5, SubPageType::ConfigInt16));
            iSubPages.try_emplace(6, new SubPage(6, SubPageType::ConfigInt16));
            iSubPages.try_emplace(7, new SubPage(7, SubPageType::ConfigInt16));
            iSubPages.try_emplace(8, new SubPage(8, SubPageType::ConfigInt16));
            iSubPages.try_emplace(9, new SubPage(9, SubPageType::StatusTemp));
            iSubPages.try_emplace(10, new SubPage(10, SubPageType::StatusTemp));
            iSubPages.try_emplace(11, new SubPage(11, SubPageType::StatusInt16));
            iSubPages.try_emplace(12, new SubPage(12, SubPageType::StatusInt16));
            iSubPages.try_emplace(13, new SubPage(13, SubPageType::StatusInt16));
            iSubPages.try_emplace(14, new SubPage(14, SubPageType::StatusInt16));
            iSubPages.try_emplace(15, new SubPage(15, SubPageType::ConfigInt16));
            iSubPages.try_emplace(16, new SubPage(16, SubPageType::ConfigInt16));
            iSubPages.try_emplace(17, new SubPage(17, SubPageType::ConfigInt16));
            iSubPages.try_emplace(18, new SubPage(18, SubPageType::ConfigInt16));*/
        }
        break;
    case MainPageType::Program:
        break;
    default:
        return;
    }
}

void
MainPage::Right()
{
    iSubPages.at(iIndex)->Right();
}

void
MainPage::Increase()
{
    if (iIndex >= iMaxPages) {
        iParent.Increase();
    } else {
        iIndex++;
    }
}

void
MainPage::Show()
{
    cout << kMainPages.at(iType) << endl;
    iSubPages.at(iIndex)->Show();
}

SinglePC::SinglePC(
    std::shared_ptr<HardwareDriver> aStm32)
    :   iIndex    (1)
    ,   iMaxPages (3)
    ,   iStm32    (aStm32)
{
    iMainPages.try_emplace(1, new MainPage(1, 3, MainPageType::Default, *this));
    iMainPages.try_emplace(2, new MainPage(2, 3, MainPageType::Actual, *this));
    iMainPages.try_emplace(3, new MainPage(3, 0, MainPageType::Program, *this));
}

void
SinglePC::Right()
{
    iMainPages.at(iIndex)->Right();
}

void
SinglePC::Increase()
{
    if (iIndex >= iMaxPages) {
        iIndex = 1;
    } else {
        iIndex++;
    }
}
