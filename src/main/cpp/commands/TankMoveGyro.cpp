
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/*
test 1: moved about 0.2 speed 212 cm 5 rotations -> 42cm per rotation
conversion factor around 2.3
*/

#include "commands/TankMoveGyro.h"


TankMoveGyro::TankMoveGyro(Drivetrain& drivetrain, double distance, double speed):
    m_distance(distance),
    m_drivetrain(&drivetrain),
    m_speed(speed) {

    SetName("TankMove");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void TankMoveGyro::Initialize() {
    m_drivetrain->m_leftLeadEncoder.SetPosition(0);
    m_drivetrain->m_rightLeadEncoder.SetPosition(0);
    m_drivetrain->m_navX.Reset();
    m_drivetrain->m_pid_move.SetSetpoint(0);
    distanceCounter = 0;
    m_drivetrain->Drive(0, 0);
}


// Called repeatedly when this Command is scheduled to run
void TankMoveGyro::Execute() {
    distanceCounter = (-m_drivetrain->m_leftLeadEncoder.GetPosition() + m_drivetrain->m_rightLeadEncoder.GetPosition())/2;
    double correction = m_drivetrain->m_pid_move.Calculate(m_drivetrain->m_navX.GetAngle());
    if (m_distance >= 0 && distanceCounter < m_distance){
        m_drivetrain->Drive(m_speed-correction, m_speed+correction);
    }
    else if(m_distance < 0 && distanceCounter > m_distance){
        m_drivetrain->Drive(-m_speed-correction, -m_speed+correction);
    }
}

// Make this return true when this Command no longer needs to run execute()
bool TankMoveGyro::IsFinished() {
    distanceCounter = (-m_drivetrain->m_leftLeadEncoder.GetPosition() + m_drivetrain->m_rightLeadEncoder.GetPosition())/2;
    if (m_distance >= 0){
        return(distanceCounter >= m_distance);
    }
    else{
        return(distanceCounter <= m_distance);
    }
}

// Called once after isFinished returns true
void TankMoveGyro::End(bool) {
    m_drivetrain->Drive(0, 0);
}

