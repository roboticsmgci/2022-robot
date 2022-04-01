// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoDriveTurn.h"

#include <frc/controller/PIDController.h>

#include "Robot.h"

AutoDriveTurn::AutoDriveTurn(Drivetrain& drivetrain, double angle):
    m_angle(angle),
    m_drivetrain(&drivetrain) {

    SetName("AutoMove");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void AutoDriveTurn::Initialize() {
    m_drivetrain->m_leftLeadEncoder.SetPosition(0);
    m_drivetrain->m_rightLeadEncoder.SetPosition(0);
    m_drivetrain->m_navX.SetAngleAdjustment(0);
    // Get everything in a safe starting state.
    //distanceCounter = 0;
    m_drivetrain->Drive(0, 0);
}


// Called repeatedly when this Command is scheduled to run
void AutoDriveTurn::Execute() {
    m_drivetrain->Drive(0, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTurn::IsFinished() {
    return (true);
}

// Called once after isFinished returns true
void AutoDriveTurn::End(bool) {
    m_drivetrain->Drive(0, 0);
}


