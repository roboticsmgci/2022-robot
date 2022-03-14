#include "subsystems/Propeller.h"

#include <frc/smartdashboard/SmartDashboard.h>

Propeller::Propeller() {
  m_motor.RestoreFactoryDefaults();

  SetName("Propeller");
}

void Propeller::Rotate(){
  m_motor.Set(1);
}

void Propeller::Stop(){
  m_motor.Set(0);
}