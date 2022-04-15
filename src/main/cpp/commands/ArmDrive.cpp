#include "commands/ArmDrive.h"

#include "Robot.h"


ArmDrive::ArmDrive(
        Arm& arm,
        std::function<double()> speed):
            m_arm(&arm),
            m_speed(std::move(speed)){

    SetName("ArmDrive");
    AddRequirements({m_arm});

}


void ArmDrive::Execute() {
    m_arm->Rotate(m_speed());
}


void ArmDrive::End(bool) {
    m_arm->Rotate(0);
}