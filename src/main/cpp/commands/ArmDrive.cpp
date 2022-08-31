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
    double speed = m_speed();
    if (speed < 0) {
        // going down
        m_arm->Rotate(m_speed() / 10);
    } else {
        // going up
        m_arm->Rotate(m_speed() / 2);
    }    
}


void ArmDrive::End(bool) {
    m_arm->Rotate(0);
}