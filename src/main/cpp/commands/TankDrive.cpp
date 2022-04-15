#include "commands/TankDrive.h"

#include "Robot.h"


TankDrive::TankDrive(
        Drivetrain& drivetrain,
        std::function<double()> left,
        std::function<double()> right):
            m_drivetrain(&drivetrain),
            m_left(std::move(left)),
            m_right(std::move(right)){

    SetName("TankDrive");
    AddRequirements({m_drivetrain});

}


void TankDrive::Execute() {
    m_drivetrain->Drive(m_left(), m_right());
}


bool TankDrive::IsFinished() {
  return false;
}


void TankDrive::End(bool) {
  m_drivetrain->Drive(0, 0);
}
