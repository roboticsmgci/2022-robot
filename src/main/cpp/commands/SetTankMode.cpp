// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SetTankMode.h"

SetTankMode::SetTankMode(Drivetrain& drivetrain, bool brake):
            m_drivetrain(&drivetrain),
            m_brake(brake) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void SetTankMode::Initialize() {
  if(m_brake){
    m_drivetrain->SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  } else {
    m_drivetrain->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  }
}
