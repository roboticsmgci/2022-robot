#include "commands/common/GrabBall.h"

#include <frc2/command/ParallelCommandGroup.h>

#include "commands/IntakeMove.h"
#include "commands/TankMove.h"


GrabBall::GrabBall(
        Drivetrain& drivetrain, 
        Intake& intake):
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("GrabBall");
    AddCommands(
        // Move forward while intake in
        frc2::ParallelCommandGroup(
            TankMove(drivetrain, 0.5, 0.6),
            IntakeMove(intake, 0.5, 0.8))
    );

}
