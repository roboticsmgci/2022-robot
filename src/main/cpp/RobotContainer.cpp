// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/ArcadeDrive.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  m_drivetrain.SetDefaultCommand(ArcadeDrive([this] { return -m_stick.GetY() * m_stick.GetThrottle(); }, [this] { return -m_stick.GetX() * m_stick.GetThrottle(); }, m_drivetrain));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
