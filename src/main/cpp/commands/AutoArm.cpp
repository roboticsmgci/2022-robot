
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoArm.h"

#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "Robot.h"

AutoArm::AutoArm(Arm& arm, double height):
    m_height(height),
    m_arm(&arm) {
    
    SetName("AutoArm");
    AddRequirements({m_arm});
}

// Called just before this Command runs the first time
void AutoArm::Initialize() {
    // Get everything in a safe starting state.
    if(m_arm->m_armEncoder.GetPosition() <= m_height){
        m_direction = 1;
    } else {
        m_direction = -1;
    }
    m_arm->Stop();
}

// Called repeatedly when this Command is scheduled to run
void AutoArm::Execute() {
    double position = m_arm->m_armEncoder.GetPosition();
    if (m_direction == 1 &&  position < m_height){
        m_arm->Rotate(0.1*m_direction);
    } else if (m_direction == -1 && position > m_height){
        m_arm->Rotate(0.1*m_direction);
    }
    frc::SmartDashboard::PutNumber("Arm", position);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoArm::IsFinished() {
    double position = m_arm->m_armEncoder.GetPosition();
    if (m_direction == 1){
        return (position >= m_height);
    } else if (m_direction == -1){
        return (position <= m_height);;
    }
}

// Called once after isFinished returns true
void AutoArm::End(bool) {
    m_arm->Stop();
}


