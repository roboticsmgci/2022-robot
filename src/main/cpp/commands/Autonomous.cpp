// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autonomous.h"

#include <frc2/command/ParallelCommandGroup.h>

#include "commands/AutoDriveForward.h"
#include "commands/AutoDriveTaxi.h"
#include "commands/AutoIntakeOut.h"

Autonomous::Autonomous(
        Drivetrain& drivetrain, Intake& intake):
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("Autonomous");
    AddCommands(
        //AutoDriveForward(drivetrain),
        AutoIntakeOut(intake)
        //AutoDriveTaxi(drivetrain)
    );
  
}
