
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoDriveForward.h"

#include <frc/controller/PIDController.h>

#include "Robot.h"

AutoDriveForward::AutoDriveForward(
        Drivetrain& drivetrain):
            m_drivetrain(&drivetrain) {
    
    SetName("MoveBack");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void AutoDriveForward::Initialize() {
    duration_counter = 0;
    // Get everything in a safe starting state.
    m_drivetrain->Drive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveForward::Execute() {
    if (duration_counter < duration){
        m_drivetrain->Drive(-0.5, 0.5);
        duration_counter++;
    }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveForward::IsFinished() {
    return (duration_counter >= duration);
}

// Called once after isFinished returns true
void AutoDriveForward::End(bool) {
    m_drivetrain->Drive(0, 0);
}

