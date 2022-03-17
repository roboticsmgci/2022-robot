// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autonomous.h"

#include <frc2/command/ParallelCommandGroup.h>

#include "commands/DriveBack.h"

Autonomous::Autonomous(
        Drivetrain& drivetrain):
            m_drivetrain(&drivetrain){

    SetName("Autonomous");
    AddCommands(DriveBack(drivetrain));
  
}
