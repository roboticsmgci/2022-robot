#include "commands/ArmMove.h"

#include <utility>

#include "Robot.h"

ArmMove::ArmMove(
        std::function<double()> speed,
        Arm& arm):
            m_speed(std::move(m_speed)),
            m_arm(&arm){
    
    SetName("ArmMove");
    AddRequirements({m_arm});

}

void ArmMove::Execute() {
    m_arm->Rotate(m_speed());
}

void ArmMove::End(bool) {
    m_arm->Rotate(0);
}
