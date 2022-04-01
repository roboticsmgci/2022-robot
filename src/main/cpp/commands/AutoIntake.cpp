
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoIntake.h"

#include <frc/controller/PIDController.h>

#include "Robot.h"

AutoIntake::AutoIntake(Intake& intake, double speed):
    m_speed(speed),
    m_intake(&intake) {
    
    SetName("AutoIntake");
    AddRequirements({m_intake});
}

// Called just before this Command runs the first time
void AutoIntake::Initialize() {
    duration_counter = 0;
    // Get everything in a safe starting state.
    m_intake->Stop();
}

// Called repeatedly when this Command is scheduled to run
void AutoIntake::Execute() {
    if (duration_counter < duration){
        m_intake->Rotate(m_speed);
        duration_counter++;
    }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoIntake::IsFinished() {
    return (duration_counter >= duration);;
}

// Called once after isFinished returns true
void AutoIntake::End(bool) {
    m_intake->Stop();
}

