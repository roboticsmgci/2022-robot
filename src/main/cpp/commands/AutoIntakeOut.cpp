
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoIntakeOut.h"

#include <frc/controller/PIDController.h>

#include "Robot.h"

AutoIntakeOut::AutoIntakeOut(
        Intake& intake):
            m_intake(&intake) {
    
    SetName("MoveBack");
    AddRequirements({m_intake});
}

// Called just before this Command runs the first time
void AutoIntakeOut::Initialize() {
    duration_counter = 0;
    // Get everything in a safe starting state.
    m_intake->Stop();
}

// Called repeatedly when this Command is scheduled to run
void AutoIntakeOut::Execute() {
    if (duration_counter < duration){
        m_intake->Rotate(1);
        duration_counter++;
    }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoIntakeOut::IsFinished() {
    return (duration_counter >= duration);;
}

// Called once after isFinished returns true
void AutoIntakeOut::End(bool) {
    m_intake->Stop();
}

