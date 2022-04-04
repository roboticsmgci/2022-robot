// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include "commands/Autonomous.h"

#include <frc2/command/ParallelCommandGroup.h>

#include "commands/AutoDriveForward.h"
#include "commands/AutoDriveTaxi.h"
#include "commands/AutoIntake.h"
#include "commands/AutoArm.h"

Autonomous::Autonomous(Drivetrain& drivetrain, Intake& intake, Arm& arm):
            m_drivetrain(&drivetrain),
            m_intake(&intake),
            m_arm(&arm){

    SetName("Autonomous");
    AddCommands(
        //AutoDriveForward(drivetrain),
        //AutoIntake(intake, 1),
        AutoDriveTaxi(drivetrain, 1),
        //AutoIntake(intake, -1),
        //AutoIntake(intake, 1),
        //AutoDriveTaxi(drivetrain, 20),
        ///AutoArm(arm, -13),
        AutoArm(arm, 17)
    );

}
