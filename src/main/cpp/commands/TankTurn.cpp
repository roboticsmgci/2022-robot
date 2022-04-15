#include "commands/TankTurn.h"


TankTurn::TankTurn(
        Drivetrain& drivetrain, 
        double angleTarget):
            m_drivetrain(&drivetrain), 
            m_angleTarget(angleTarget){

    SetName("TankTurn");
    AddRequirements({m_drivetrain});

}


void TankTurn::Initialize() {

    m_drivetrain->m_navX.Reset();
    m_drivetrain->Drive(0, 0);

    // If negative (CCW), turn positive and note CCW
    if (m_angleTarget < 0){
        m_angleTarget = m_angleTarget * -1;
        m_clockwise = false;
    }

}


void TankTurn::Execute() {

    m_angleCurrent = m_drivetrain->m_navX.GetYaw();
    // If negative (CCW), absolute value
    if (m_angleCurrent < 0){
        m_angleCurrent = m_angleCurrent * -1;
    }

    // Increase by 1 for gyro inconsistencies
    m_angleCurrent++;

    if (m_clockwise){
        m_drivetrain->Drive(-m_speed, m_speed);
    } else {
        m_drivetrain->Drive(m_speed, -m_speed);
    }

}


bool TankTurn::IsFinished() {
    return m_angleCurrent >= m_angleTarget - m_error;
}


void TankTurn::End(bool) {
    m_drivetrain->Drive(0, 0);
}
