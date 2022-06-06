#include "SendingSmsState.hpp"

namespace ue {
    SendingSmsState::SendingSmsState(Context &context) : ConnectedState(
            context), iSmsComposeMode(context.user.composeSms()) {
    }

    void SendingSmsState::acceptButton() {
        std::string text = iSmsComposeMode.getSmsText();
        common::PhoneNumber toPhoneNumber = iSmsComposeMode.getPhoneNumber();

        SmsDb &db = context.user.getSmsDb();
        db.addSms(text, context.bts.getOwnPhoneNumber(), toPhoneNumber);
        context.bts.sendSms(toPhoneNumber, text);
        context.setState<ConnectedState>();
    }

    void SendingSmsState::refuseButton() {
        context.setState<ConnectedState>();
    }
}
