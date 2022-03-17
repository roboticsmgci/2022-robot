// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveBack.h"

#include <frc/controller/PIDController.h>

#include "Robot.h"

DriveBack::DriveBack(
        Drivetrain& drivetrain):
            m_drivetrain(&drivetrain) {
    
    SetName("MoveBack");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void DriveBack::Initialize() {
    // Get everything in a safe starting state.
    m_drivetrain->Drive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void DriveBack::Execute() {
    m_drivetrain->Drive(0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveBack::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void DriveBack::End(bool) {
    m_drivetrain->Drive(0, 0);
}

