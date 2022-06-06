#pragma once

#include "ConnectedState.hpp"

namespace  ue {
    class ViewSmsState : public ConnectedState {
    public:
        ViewSmsState(Context& context, int index);
        void acceptButton() override;
        void refuseButton() override;
    };
};