#include "commands/autonomous/Ball2b.h"

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


Ball2b::Ball2b(
        Arm& arm,
        Drivetrain& drivetrain,
        Intake& intake): 
            m_arm(&arm),
            m_drivetrain(&drivetrain),
            m_intake(&intake){

    SetName("Ball2b");
    AddCommands(
        GrabBall(arm, drivetrain, intake),
        TankMoveGyro(drivetrain, -0.9, 0.5),
        TankStop(drivetrain, 0.3),
        TankTurn(drivetrain, 158),
        TankMoveGyro(drivetrain, 0.25, 0.45),
        // Score ball
        ScoreBall(arm, drivetrain, intake)
    );

}
