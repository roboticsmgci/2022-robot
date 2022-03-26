#include "subsystems/Arm.h"

#include <frc/smartdashboard/SmartDashboard.h>

Arm::Arm(){
    m_arm.RestoreFactoryDefaults();
    SetName("Arm");
}

void Arm::Rotate(double speed){
    m_arm.Set(speed * invert);
}

void Arm::Stop(){
    m_arm.Set(0);
}
