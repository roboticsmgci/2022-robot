
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoDriveTaxi.h"

#include <frc/controller/PIDController.h>

#include "Robot.h"

AutoDriveTaxi::AutoDriveTaxi(Drivetrain& drivetrain, double distance):
    m_distance(distance),
    m_drivetrain(&drivetrain) {

    SetName("AutoMove");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void AutoDriveTaxi::Initialize() {
    m_drivetrain->m_leftLeadEncoder.SetPosition(0);
    m_drivetrain->m_rightLeadEncoder.SetPosition(0);
    // Get everything in a safe starting state.
    distanceCounter = 0;
    m_drivetrain->Drive(0, 0);
}


// Called repeatedly when this Command is scheduled to run
void AutoDriveTaxi::Execute() {
    distanceCounter = (m_drivetrain->m_leftLeadEncoder.GetPosition() + m_drivetrain->m_rightLeadEncoder.GetPosition())/2;
    if (m_distance >= 0 && distanceCounter < m_distance){
        m_drivetrain->Drive(-0.3, 0.3);
        //slowly back until the end of 'duration' autonomous period??
    }
    else if(m_distance < 0 && distanceCounter > m_distance){
        m_drivetrain->Drive(0.3, -0.3);
    }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveTaxi::IsFinished() {
    distanceCounter = (m_drivetrain->m_leftLeadEncoder.GetPosition() + m_drivetrain->m_rightLeadEncoder.GetPosition())/2;
    if (m_distance >= 0){
        return(distanceCounter >= m_distance);
        //slowly back until the end of 'duration' autonomous period??
    }
    else if (m_distance < 0){
        return(distanceCounter <= m_distance);
        //slowly back until the end of 'duration' autonomous period??
    }
}

// Called once after isFinished returns true
void AutoDriveTaxi::End(bool) {
    m_drivetrain->Drive(0, 0);
}

