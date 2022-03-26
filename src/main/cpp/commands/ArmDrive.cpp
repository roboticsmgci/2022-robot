#include "commands/ArmDrive.h"

#include <utility>

#include "Robot.h"

ArmDrive::ArmDrive(
        std::function<double()> speed,
        Arm& arm):
            m_speed(std::move(speed)),
            m_arm(&arm){

    SetName("ArmDrive");
    AddRequirements({m_arm});
}

void ArmDrive::Execute() {
    m_arm->Rotate(m_speed());
}

void ArmDrive::End(bool) {
    m_arm->Rotate(0);
}