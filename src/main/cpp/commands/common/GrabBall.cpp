#include "commands/common/GrabBall.h"

#include <frc2/command/ParallelCommandGroup.h>

#include "commands/ArmMove.h"
#include "commands/IntakeMove.h"
#include "commands/TankMoveGyro.h"


GrabBall::GrabBall(
        Arm& arm,
        Drivetrain& drivetrain, 
        Intake& intake):
            m_arm(&arm),
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("GrabBall");
    AddCommands(
        ArmMove(arm, -0.23, 0.6),
        // Move forward while intake in
        frc2::ParallelCommandGroup(
            ArmMove(arm, -0.1, 1.3),
            IntakeMove(intake, 0.8, 1.3),
            TankMoveGyro(drivetrain, 0.5, 0.7))
    );

}
