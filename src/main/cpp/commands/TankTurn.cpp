#include "commands/TankTurn.h"

TankTurn::TankTurn(
        Drivetrain& drivetrain, 
        double angle_target):
            m_drivetrain(&drivetrain),
            m_angle_target(angle_target){

    SetName("TankTurn");
    AddRequirements({m_drivetrain});

}


void TankTurn::Initialize() {

    m_drivetrain->m_navX.Reset();
    m_drivetrain->Drive(0, 0);

    // If negative (CCW), turn positive and note CCW
    if (m_angle_target < 0){
        m_angle_target = m_angle_target * -1;
        m_turn_clockwise = false;
    }

}


void TankTurn::Execute() {

    m_angle_current = m_drivetrain->m_navX.GetYaw();
    // If negative (CCW), absolute value
    if (m_angle_current < 0){
        m_angle_current = m_angle_current * -1;
    }
    m_angle_current++;

    // Turns CCW
    if (m_turn_clockwise){
        m_drivetrain->Drive(-m_turn_speed, m_turn_speed);
    } else {
        m_drivetrain->Drive(m_turn_speed, -m_turn_speed);
    }

}


bool TankTurn::IsFinished() {
    return m_angle_current >= m_angle_target - m_turn_error;
}


void TankTurn::End(bool) {
    m_drivetrain->Drive(0, 0);
}
