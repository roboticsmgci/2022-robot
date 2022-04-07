
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include "commands/TankMove.h"


TankMove::TankMove(Drivetrain& drivetrain, double distance):
    m_drivetrain(&drivetrain),
    m_distance(distance){

    SetName("TankMove");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void TankMove::Initialize() {
    m_drivetrain->m_leftLeadEncoder.SetPosition(0);
    m_drivetrain->m_rightLeadEncoder.SetPosition(0);
    distanceCounter = 0;
    m_drivetrain->Drive(0, 0);
}


// Called repeatedly when this Command is scheduled to run
void TankMove::Execute() {
    distanceCounter = (-m_drivetrain->m_leftLeadEncoder.GetPosition() + m_drivetrain->m_rightLeadEncoder.GetPosition())/2;
    if (m_distance >= 0 && distanceCounter < m_distance){
        m_drivetrain->Drive(0.4, 0.4);
    }
    else if(m_distance < 0 && distanceCounter > m_distance){
        m_drivetrain->Drive(-0.4, -0.4);
    }
}

// Make this return true when this Command no longer needs to run execute()
bool TankMove::IsFinished() {
    distanceCounter = (-m_drivetrain->m_leftLeadEncoder.GetPosition() + m_drivetrain->m_rightLeadEncoder.GetPosition())/2;
    if (m_distance >= 0){
        return(distanceCounter >= m_distance);
    }
    else{
        return(distanceCounter <= m_distance);
    }
}

// Called once after isFinished returns true
void TankMove::End(bool) {
    m_drivetrain->Drive(0, 0);
}

