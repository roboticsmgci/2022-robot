#include "subsystems/Intake.h"

#include <frc/smartdashboard/SmartDashboard.h>

Intake::Intake(){
    m_motor.RestoreFactoryDefaults();
    SetName("Propeller");
}

void Intake::Rotate(double speed){
    m_motor.Set(speed * invert);
}

void Intake::Stop(){
    m_motor.Set(0);
}
