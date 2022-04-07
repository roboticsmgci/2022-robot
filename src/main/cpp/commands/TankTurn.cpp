// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TankTurn.h"

TankTurn::TankTurn(Drivetrain& drivetrain, double angle):
    m_drivetrain(&drivetrain),
    m_angle(angle) {

    SetName("TankTurn");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void TankTurn::Initialize() {
    m_drivetrain->m_navX.Reset();//SetAngleAdjustment(0);
    m_drivetrain->Drive(0, 0);
}


// Called repeatedly when this Command is scheduled to run
void TankTurn::Execute() {
    double angle = m_drivetrain->m_navX.GetAngle();
    if (m_angle >= 0 && angle < m_angle){
        m_drivetrain->Drive(0.5, -0.5);
    }
    else if(m_angle < 0 && angle > m_angle){
        m_drivetrain->Drive(-0.5, 0.5);
    };
}

// Make this return true when this Command no longer needs to run execute()
bool TankTurn::IsFinished() {
    double angle = m_drivetrain->m_navX.GetAngle();
    if (m_angle >= 0){
        return(angle >= m_angle);
    }
    else{
        return(angle <= m_angle);
    }
}

// Called once after isFinished returns true
void TankTurn::End(bool) {
    m_drivetrain->Drive(0, 0);
}


