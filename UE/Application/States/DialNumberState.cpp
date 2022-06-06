#include "DialNumberState.hpp"
#include "ConnectedState.hpp"
#include "CallState.hpp"
#include "IUeGui.hpp"

namespace ue {
    DialNumberState::DialNumberState(Context &context, IUeGui::IDialMode &iDialMode) : ConnectedState(context),
                                                                                       iDialMode(iDialMode) {}
    // TODO idialmode argument fix

    void DialNumberState::acceptButton() {
        context.setState<CallState>(iDialMode.getPhoneNumber());
    }

    void DialNumberState::refuseButton() {
        context.setState<ConnectedState>();
    }
}
