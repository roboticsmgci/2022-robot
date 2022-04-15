#include "commands/TankMove.h"


TankMove::TankMove(
        Drivetrain& drivetrain, 
        double distance, 
        double speed):
            m_drivetrain(&drivetrain),
            m_distance(distance),
            m_speed(speed){

    SetName("TankMove");
    AddRequirements({m_drivetrain});

}


void TankMove::Initialize() {

    m_drivetrain->Drive(0, 0);
    m_drivetrain->m_leftLeadEncoder.SetPosition(0);
    m_drivetrain->m_rightLeadEncoder.SetPosition(0);
    m_distanceCounter = 0;

}


void TankMove::Execute() {

    m_distanceCounter = (- m_drivetrain->m_leftLeadEncoder.GetPosition() 
                         + m_drivetrain->m_rightLeadEncoder.GetPosition())
                        / 2;
    
    if (m_distance >= 0 && m_distanceCounter < m_distance){
        m_drivetrain->Drive(m_speed, m_speed);
    } else if (m_distance < 0 && m_distanceCounter > m_distance){
        m_drivetrain->Drive(-m_speed, -m_speed);
    }

}


bool TankMove::IsFinished() {

    m_distanceCounter = (- m_drivetrain->m_leftLeadEncoder.GetPosition() 
                         + m_drivetrain->m_rightLeadEncoder.GetPosition())
                        / 2;

    if (m_distance >= 0){
        return(m_distanceCounter >= m_distance);
    } else {
        return(m_distanceCounter <= m_distance);
    }

}


void TankMove::End(bool) {
    m_drivetrain->Drive(0, 0);
}
