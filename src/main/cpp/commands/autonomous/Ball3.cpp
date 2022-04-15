#include "commands/autonomous/Ball3.h"

#include "commands/common/ArmLower.h"
#include "commands/common/GrabBall.h"
#include "commands/common/ScoreBall.h"

#include "commands/ArmMove.h"
#include "commands/TankMove.h"
#include "commands/TankTurn.h"
#include "commands/IntakeMove.h"


Ball3::Ball3(
        Arm& arm,
        Drivetrain& drivetrain,
        Intake& intake): 
            m_arm(&arm),
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("Ball3");
    AddCommands(
        // Remove ball
        IntakeMove(intake, -1, 0.2),
        // Taxi out
        TankMove(drivetrain, -0.5, 0.4),
        // Break tape
        //ArmLower(arm),
        // Turn to face ball 1
        TankTurn(drivetrain, -120),
        // Move to ball 1
        TankMove(drivetrain, 1.10, 0.4),
        // Get ball 1
        GrabBall(arm, drivetrain, intake),
        // Turn to face ball 2
        TankTurn(drivetrain, -115),
        // Move to ball 2
        TankMove(drivetrain, 1.4, 0.4),
        // Get ball 2
        GrabBall(arm, drivetrain, intake),
        // Turn to hub
        TankTurn(drivetrain, -100),
        // Move to hub
        TankMove(drivetrain, 2, 0.4),
        // Realign perpendicular to hub
        //TankTurn(drivetrain, -10),
        // Score ball
        ScoreBall(arm, drivetrain, intake)
    );

}
