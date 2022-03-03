// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "rev/CANSparkMax.h"

Drivetrain::Drivetrain() {
  // Implementation of subsystem constructor goes here.

  // Restores factory defaults, does not persist
  m_leftLeadMotor.RestoreFactoryDefaults();
  m_rightLeadMotor.RestoreFactoryDefaults();
  m_leftFollowMotor.RestoreFactoryDefaults();
  m_rightFollowMotor.RestoreFactoryDefaults();

  // Inverts one side of the drivetrain
  m_leftLeadMotor.SetInverted(true);
  m_leftFollowMotor.SetInverted(true);

  // Configures the motors to follow each other
  m_leftFollowMotor.Follow(m_leftLeadMotor);
  m_rightFollowMotor.Follow(m_rightLeadMotor);

  SetName("Drivetrain");
}

void Drivetrain::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Drivetrain::Drive(double speed, double rotation) {
    m_robotDrive.ArcadeDrive(speed, rotation);
}
