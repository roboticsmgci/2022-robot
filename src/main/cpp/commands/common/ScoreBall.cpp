#include "commands/common/ScoreBall.h"

#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/ParallelRaceGroup.h>

#include "commands/ArmMove.h"
#include "commands/IntakeMove.h"
#include "commands/TankMove.h"
#include "commands/TankStop.h"

#include "commands/common/ArmLower.h"


ScoreBall::ScoreBall(
        Arm& arm,
        Drivetrain& drivetrain, 
        Intake& intake):
            m_arm(&arm),
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("ScoreBall");
    AddCommands(
        TankStop(drivetrain, 0.1),
        // Raise arm
        ArmMove(arm, 0.4, 1.5),
        // Move forward while keeping arm up
        frc2::ParallelRaceGroup(
            TankMove(drivetrain, 0.3, 0.4),
            ArmMove(arm, 0.1, 5)),
        // Dump ball while keeping arm up
        frc2::ParallelCommandGroup(
            IntakeMove(intake, -1, 0.3),
            ArmMove(arm, 0.1, 0.3)),
        // Move back
        TankMove(drivetrain, -2.5, 0.7),
        ArmLower(arm)
    );

}
