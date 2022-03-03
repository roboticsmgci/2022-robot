// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"

/**
 * Have the robot drive tank style using the PS3 Joystick until interrupted.
 */
class ArcadeDrive : public frc2::CommandHelper<frc2::CommandBase, ArcadeDrive> {
 public:
  ArcadeDrive(std::function<double()> speed, std::function<double()> rotation,
            Drivetrain& drivetrain);
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;

 private:
  std::function<double()> m_speed;
  std::function<double()> m_rotation;
  Drivetrain* m_drivetrain;
};
