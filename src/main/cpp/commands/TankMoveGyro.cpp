#include "commands/TankMoveGyro.h"


TankMoveGyro::TankMoveGyro(
        Drivetrain& drivetrain, 
        double distance, 
        double speed):
            m_drivetrain(&drivetrain),
            m_distance(distance),
            m_speed(speed){

    SetName("TankMove");
    AddRequirements({m_drivetrain});

}


void TankMoveGyro::Initialize() {

    m_drivetrain->Drive(0, 0);
    m_drivetrain->m_leftLeadEncoder.SetPosition(0);
    m_drivetrain->m_rightLeadEncoder.SetPosition(0);
    m_drivetrain->m_navX.Reset();
    m_drivetrain->m_PIDMove.SetSetpoint(0);

    m_distanceCounter = 0;

}


void TankMoveGyro::Execute() {

    m_distanceCounter = (- m_drivetrain->m_leftLeadEncoder.GetPosition() 
                         + m_drivetrain->m_rightLeadEncoder.GetPosition())
                        / 2;
    m_correction = m_drivetrain->m_PIDMove.Calculate(m_drivetrain->m_navX.GetAngle());

    if (m_distance >= 0 && m_distanceCounter < m_distance){
        m_drivetrain->Drive(m_speed - m_correction, m_speed + m_correction);
    } else if (m_distance < 0 && m_distanceCounter > m_distance){
        m_drivetrain->Drive(-m_speed - m_correction, -m_speed + m_correction);
    }
}


bool TankMoveGyro::IsFinished() {

    m_distanceCounter = (- m_drivetrain->m_leftLeadEncoder.GetPosition() 
                         + m_drivetrain->m_rightLeadEncoder.GetPosition())
                        / 2;

    if (m_distance >= 0){
        return (m_distanceCounter >= m_distance);
    } else {
        return (m_distanceCounter <= m_distance);
    }

}


void TankMoveGyro::End(bool) {
    m_drivetrain->Drive(0, 0);
}

