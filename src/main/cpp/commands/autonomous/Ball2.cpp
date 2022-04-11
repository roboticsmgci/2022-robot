#include "commands/autonomous/Ball2.h"

#include "commands/ArmMove.h"
#include "commands/TankMove.h"
#include "commands/TankMoveGyro.h"
#include "commands/TankTurn.h"
#include "commands/IntakeMove.h"

#include "commands/TankStop.h"
#include "commands/TankRawMove.h"

#include "commands/common/ArmLower.h"
#include "commands/common/GrabBall.h"
#include "commands/common/ScoreBall.h"
#include "commands/TankTurnPID.h"


Ball2::Ball2(
        Arm& arm,
        Drivetrain& drivetrain,
        Intake& intake): 
            m_arm(&arm),
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("Ball2");
    AddCommands(
        //TankTurn(drivetrain, 180),
        //TankTurn(drivetrain, -180),
        //TankStop(drivetrain, 100),
        // Remove ball
        IntakeMove(intake, -1, 0.3),
        // Taxi out
        TankMoveGyro(drivetrain, -1.3, 0.3),
        // Break tape
        ArmLower(arm),
        // Turn around to face the ball
        TankTurn(drivetrain, 180),
        // Get the ball
        GrabBall(arm, drivetrain, intake),
        // Turn back around to face hub
        TankTurn(drivetrain, 180),
        // Move towards hub
        TankMoveGyro(drivetrain, 1.8, 0.6),
        // Score ball
        ScoreBall(arm, drivetrain, intake)
    );

}
