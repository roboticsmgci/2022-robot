#include "commands/autonomous/Ball1sus.h"

#include "commands/TankMove.h"


Ball1sus::Ball1sus(
        Drivetrain& drivetrain): 
            m_drivetrain(&drivetrain){

    SetName("Ball1sus");
    AddCommands(
        TankMove(drivetrain, -0.8, 0.8),
        TankMove(drivetrain, 3, 0.5)
    );

}
