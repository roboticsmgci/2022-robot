
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoDriveTaxi.h"

#include <frc/controller/PIDController.h>

#include "Robot.h"

AutoDriveTaxi::AutoDriveTaxi(
        Drivetrain& drivetrain):
            m_drivetrain(&drivetrain) {
    
    SetName("MoveBack");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void AutoDriveTaxi::Initialize() {
    duration_counter = 0;
    // Get everything in a safe starting state.
    m_drivetrain->Drive(0, 0);
}


// Called repeatedly when this Command is scheduled to run
void AutoDriveTaxi::Execute() {
    if (duration_counter < duration){
        m_drivetrain->Drive(-0.5, -0.5);
        duration_counter++;
    }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTaxi::IsFinished() {
    return (duration_counter >= duration);
}

// Called once after isFinished returns true
void AutoDriveTaxi::End(bool) {
    m_drivetrain->Drive(0, 0);
}

