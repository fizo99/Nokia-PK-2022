#include "ConnectedState.hpp"
#include "ViewSmsListState.hpp"
#include "IUeGui.hpp"

namespace ue
{

ConnectedState::ConnectedState(Context &context)
    : BaseState(context, "ConnectedState")
{
    context.user.acceptCallback(std::bind(&ConnectedState::showSmsButton, this));
    context.user.rejectCallback(std::bind(&ConnectedState::closeSmsButton, this));
    context.user.showConnected();
}

void ConnectedState::showSmsButton() {
    if(context.user.getAction() == 1) {
        context.setState<ViewSmsListState>();
    }
}

void ConnectedState::closeSmsButton() {
    // TODO
}

void ConnectedState::handleSmsReceive(uint8_t action, std::string text) {
    SmsDb &db = context.user.getSmsDb();
    db.addSms(text);
}

}
