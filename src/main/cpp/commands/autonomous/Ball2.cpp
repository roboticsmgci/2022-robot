#include "commands/autonomous/Ball2.h"

#include "commands/ArmMove.h"
#include "commands/TankMove.h"
#include "commands/TankTurn.h"
#include "commands/IntakeMove.h"

#include "commands/TankRawMove.h"

#include "commands/common/ArmLower.h"
#include "commands/common/GrabBall.h"
#include "commands/common/ScoreBall.h"


Ball2::Ball2(
        Arm& arm,
        Drivetrain& drivetrain,
        Intake& intake): 
            m_arm(&arm),
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("Ball2");
    AddCommands(
        // Remove ball
        IntakeMove(intake, 1, 0.2),
        // Taxi out
        TankMove(drivetrain, -1.4),
        // Break tape
        //ArmLower(arm),
        // Turn around to face the ball
        TankRawMove(drivetrain, 0.5, -0.5, 1),
        TankRawMove(drivetrain, 0.5, -0.5, 1),
        // Get the ball
        GrabBall(drivetrain, intake),
        // Turn back around to face hub
        TankTurn(drivetrain, 90),
        TankTurn(drivetrain, 90),
        // Move towards hub
        TankMove(drivetrain, 1.9),
        // Score ball
        ScoreBall(arm, drivetrain, intake)
    );

}
