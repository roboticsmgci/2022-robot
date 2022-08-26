#include "commands/autonomous/OnlyTaxi.h"

#include "commands/TankMove.h"


OnlyTaxi::OnlyTaxi(
        Drivetrain& drivetrain): 
            m_drivetrain(&drivetrain){

    SetName("OnlyTaxi");
    AddCommands(
        TankMove(drivetrain, -3, 0.5)
    );

}
