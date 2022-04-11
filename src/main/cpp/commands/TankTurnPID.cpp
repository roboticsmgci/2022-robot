// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TankTurnPID.h"

TankTurnPID::TankTurnPID(Drivetrain& drivetrain, double angle, int duration):
    m_drivetrain(&drivetrain),
    m_angle(angle),
    m_duration(duration) {

    SetName("TankTurnPID");
    AddRequirements({m_drivetrain});
}

// Called just before this Command runs the first time
void TankTurnPID::Initialize() {
    m_drivetrain->m_navX.Reset();//SetAngleAdjustment(0);
    m_drivetrain->Drive(0, 0);
    m_drivetrain->m_turnPid.SetSetpoint(m_angle);
    //m_drivetrain->m_navX.SetAngleAdjustment(-90);
    periods = 0;
    period_target = m_duration * 50;
}


// Called repeatedly when this Command is scheduled to run
void TankTurnPID::Execute() {
    double angle = m_drivetrain->m_navX.GetAngle();
    if (m_angle >= 0 && angle < 0){
        angle += 360;
    } else if(m_angle < 0 && angle > 0){
        angle -= 360;
    }
    double correction = m_drivetrain->m_turnPid.Calculate(angle);
    if(correction > 0.4){
        correction = 0.4;
    } else if(correction < -0.4){
        correction = -0.4;
    }
    int time = (period_target - periods)/period_target;
    if (m_angle >= 0){
        m_drivetrain->Drive(-0.3-correction, 0.3+correction);
    }
    else{
        m_drivetrain->Drive(0.3-correction, -0.3+correction);
    }
    periods++;
}

// Make this return true when this Command no longer needs to run execute()
bool TankTurnPID::IsFinished() {
    return (periods >= period_target);
}

// Called once after isFinished returns true
void TankTurnPID::End(bool) {
    m_drivetrain->Drive(0, 0);
}


