#pragma once

#include <gmock/gmock.h>
#include "Ports/IUserPort.hpp"
#include "IUeGui.hpp"

namespace ue
{

class IUserEventsHandlerMock : public IUserEventsHandler
{
public:
    IUserEventsHandlerMock();
    ~IUserEventsHandlerMock() override;

};

class IUserPortMock : public IUserPort
{
public:
    IUserPortMock();
    ~IUserPortMock() override;

    MOCK_METHOD(void, showNotConnected, (), (final));
    MOCK_METHOD(void, showConnecting, (), (final));
    MOCK_METHOD(void, showConnected, (), (final));

    MOCK_METHOD(void, showSms, (int), (final));
    MOCK_METHOD(void, showSmsList, (), (final));
    MOCK_METHOD(IUeGui::ISmsComposeMode &, composeSms, (), (final));
    MOCK_METHOD(int, getAction, (), (final));
    MOCK_METHOD(SmsDb&, getSmsDb, (), (final));

    MOCK_METHOD(void, acceptCallback, (IUeGui::Callback), (final));
    MOCK_METHOD(void, rejectCallback, (IUeGui::Callback), (final));
    MOCK_METHOD(void, showCallRequest, (common::PhoneNumber phoneNumber), (final));
    MOCK_METHOD(void, callAchieved, (common::PhoneNumber phoneNumber), (final));
    MOCK_METHOD(void, showPartnerNotAvailable, (common::PhoneNumber phoneNumber), (final));
    MOCK_METHOD(void, startTalking, (common::PhoneNumber phoneNumber), (final));
    MOCK_METHOD(void, showStartMenu,(), (final));
    MOCK_METHOD(void, showEnterPhoneNumber, (), (final));
    MOCK_METHOD(void, showDialing, (common::PhoneNumber phoneNumber), (final));
};

}
