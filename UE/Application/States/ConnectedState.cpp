#include "ConnectedState.hpp"
#include "SendingSmsState.hpp"
#include "ViewSmsListState.hpp"
#include "IUeGui.hpp"
#include "NotConnectedState.hpp"

namespace ue
{

ConnectedState::ConnectedState(Context &context)
    : BaseState(context, "ConnectedState")
{
    context.user.acceptCallback([this] { showSmsButton(); });
    context.user.rejectCallback([this] { closeSmsButton(); });
    context.user.showConnected();
}

void ConnectedState::handleDisconnected()
    {
        context.setState<NotConnectedState>();
    }

void ConnectedState::showSmsButton() {
    switch(context.user.getAction()){
        case 0:
            context.setState<SendingSmsState>();
            break;
        case 1:
            context.setState<ViewSmsListState>();
            break;
    }
}

void ConnectedState::closeSmsButton() {
    // TODO
}

void ConnectedState::handleFailedSendingSms() {
    context.user.getSmsDb().markLastSmsSentAsFailed();
}

void ConnectedState::handleSmsReceive(uint8_t action, const std::string& text, common::PhoneNumber fromPhoneNumber, common::PhoneNumber toPhoneNumber) {
    SmsDb &db = context.user.getSmsDb();
    db.addSms(text, fromPhoneNumber, toPhoneNumber);
}

}
