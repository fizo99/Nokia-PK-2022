#include "ViewSmsState.hpp"
#include "ConnectedState.hpp"
#include "ViewSmsListState.hpp"

namespace ue {
    ViewSmsState::ViewSmsState(Context &context, int index) : ConnectedState(context) {
        context.user.showSms(index);
    }

    void ViewSmsState::acceptButton() {

    }

    void ViewSmsState::refuseButton() {
        context.setState<ViewSmsListState>();
    }
}