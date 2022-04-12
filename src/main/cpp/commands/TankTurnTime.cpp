// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TankTurnTime.h"

TankTurnTime::TankTurnTime(Drivetrain& drivetrain, double angle, int duration):
    m_drivetrain(&drivetrain),
    m_angle(angle),
    m_duration(duration) {

    SetName("TankTurnTime");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void TankTurnTime::Initialize() {
    m_drivetrain->m_navX.Reset();//SetAngleAdjustment(0);
    m_drivetrain->Drive(0, 0);
    periods = 0;
    period_target = m_duration * 50;
}


// Called repeatedly when this Command is scheduled to run
void TankTurnTime::Execute() {
    double angle = m_drivetrain->m_navX.GetAngle();
    if (m_angle >= 0 && angle < 0){
        angle += 360;
    } else if(m_angle < 0 && angle > 0){
        angle -= 360;
    }
    int time = (period_target - periods)/period_target;
    if (m_angle <= angle){
        m_drivetrain->Drive(-0.4-0.3*time, 0.4+0.3*time);
    }
    else{
        m_drivetrain->Drive(0.4-0.3*time, -0.4+0.3*time);
    }
    periods++;
}

// Make this return true when this Command no longer needs to run execute()
bool TankTurnTime::IsFinished() {
    return (periods >= period_target);
}

// Called once after isFinished returns true
void TankTurnTime::End(bool) {
    m_drivetrain->Drive(0, 0);
}


