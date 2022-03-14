// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Joystick.h>
#include <frc2/command/Command.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Propeller.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // This declares the joystick 
  frc::Joystick m_stick1{0};
  frc::Joystick m_stick2{1};
  
  Propeller m_propeller;

  // The robot's subsystems and commands are defined here...
  Drivetrain m_drivetrain;

  void ConfigureButtonBindings();
};
