// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ArcadeDrive.h"

#include <utility>

#include "Robot.h"

// Initialises the command with its name and requirements
ArcadeDrive::ArcadeDrive(std::function<double()> speed, std::function<double()> rotation, Drivetrain& drivetrain)
    : m_speed(std::move(speed)), m_rotation(std::move(rotation)), m_drivetrain(&drivetrain) {
    SetName("ArcadeDrive");
    AddRequirements({m_drivetrain});
}

// Called repeatedly when this Command is scheduled to run
void ArcadeDrive::Execute() {
    m_drivetrain->Drive(m_speed(), m_rotation());
}

// Make this return true when this Command no longer needs to run execute()
bool ArcadeDrive::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void ArcadeDrive::End(bool) {
  m_drivetrain->Drive(0, 0);
}
