// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>

#include <cmath>

#include "commands/TankDrive.h"
#include "commands/ArmDrive.h"
#include "commands/IntakeDrive.h"

// Testing temp
#include "commands/TankMoveGyro.h"

RobotContainer::RobotContainer() {

    m_chooser.SetDefaultOption("Only Taxi", &m_only_taxi);
    m_chooser.AddOption("2 Ball", &m_ball2);
    m_chooser.AddOption("3 Ball", &m_ball3);

    frc::SmartDashboard::PutData(&m_chooser);

    // Initialize all of your commands and subsystems here
    // ((-m_stick2.GetThrottle() + 2) / 3)
    m_drivetrain.SetDefaultCommand(
        TankDrive(
            [this] {
                return ( - 
                    (
                        // tank
                        (
                            m_stick2.GetY()
                                * (int)!(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                            + (m_stick1.GetY() + m_stick2.GetY()) / 2
                                * (int)(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                        ) * (int)!(bool)round((-m_stick1.GetThrottle() + 1) / 2)
                        // tank
                        +
                        // arcade
                        (m_stick2.GetY()
                            * (
                                1 - std::abs(
                                    m_stick2.GetZ()
                                        * (int)!m_stick2.GetRawButton(1)
                                )
                            )
                        + m_stick2.GetZ()
                            * 0.75
                            * (int)!m_stick2.GetRawButton(1)
                        
                        ) * (int)round((-m_stick1.GetThrottle() + 1) / 2)
                        // arcade
                    ) * ((-m_stick2.GetThrottle() + 2) / 3)
                );
            },
            [this] {
                return ( -
                    (
                        // tank
                        (
                            m_stick1.GetY()
                                * (int)!(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                            + (m_stick1.GetY() + m_stick2.GetY()) / 2
                                * (int)(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                        ) * (int)!(bool)round((-m_stick1.GetThrottle() + 1) / 2)
                        // tank
                        + 
                        // arcade
                        (
                            m_stick2.GetY()
                                * (
                                    1 - std::abs(
                                        m_stick2.GetZ()
                                            * (int)!m_stick2.GetRawButton(1)
                                    )
                                )
                            - m_stick2.GetZ()
                                * 0.75
                                * (int)!m_stick2.GetRawButton(1)
                        ) * (int)round((-m_stick1.GetThrottle() + 1) / 2)
                        // arcade
                    ) * ((-m_stick2.GetThrottle() + 2) / 3)
                );
            },
            m_drivetrain
        )
    );

/* Me reading the above code:
&&&&&&&&&&&&&##BGPPPGBB#BBGBGJ???J5BB#BBB###BBPYY5Y5B#&&&&GY5PGGGYJYGGPG&&&&&&#BJ:.:?B##BGGGGPY!JGPP
&&###BBBGG##&&##BGGG##BGGBBBG?7???5#&#BBGG###BPYYYP#&##&&&BY5GGGPYJ5GBPB&&#BGPP57. .7GBBGPPPPPY!JPPG
&&#BGPPPGB####&&######BBBBBBG?7?7?5#&#GB#BG##G5GGG&&#GP!5&BYPGBGPYYGBP?7!~~!~77?77!~~^~~~!????7~!???
#&&&#BGB#&&&&#&&&##B########G?!7775##BB##GB##GB&&&&&#!. J@BYPBBGPY5J~^!JP#&@@@@@@@@@@#B5?^:~J5J!?5PP
##&&###&&&&&&&&#BGGB#######BP?!77?5BBGGGBB#GG#&#&&&&B:  ?&BYGBBG5!.^5&@@@@@@@@@@@@@@@@@@@@B7.~J7YBBB
#BBBBPG#######BGPGB###BBBGGGBB#BB##########B&&&#&&&&#J. ^B&GGB#5::P@@@@@@@BY7!!!~^!?YB@@@@@@#! ^YB#B
G###GG#&&###BGGGPG#BBBB###&&&&&BB&&&&&&##&&&&&&&&&&&&#J.~##PB#P.~&@@@@@@G~:?5G#B?. .::~G@@@@@@J ?###
!.!?JJ5#&&&&&&&######&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&B#PJ#G5B#^.&@@@@@@5 7#@&&&#Y:.:75! P@@@@@@^.B##
#~   :~?P#&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#&&&&&&&&#BGG5JBB::!??J5P5 7&&&##&#5:.^7GP J@@@@@@? GBB
&G:   7YYP#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###&#BBGP##B5Y55YJ7~!#&&&&#&#5^.^?J.~#@@@@@@~.PBB
&&P:  ^5BBB#&&&&&&&&&&&&&&&&&&&&&&&&&&##&&&&&&&&&&&&&##&&BPG#&BGB&@@&#GB&&&#BBBGY^.:.:J&@@@@@@J !GGG
#&&G! .P#BB###&&##&&&&&&&&&&&&&&#B&&&&&##&&&&&&&&&&&&&B#&&#G#&BGB&&#BG5GBBGPYJJJ!. :J#@@@@@@#! ^7???
##&&#J.Y&#BBBGB&##&&&&&#B#&&&&&&&G#&&&###&&&&&#&&##&&&#B#&&#BBBGB&&&&#GB&&#BBBP!.!5&@@@@@@#?.~J!?YYY
&&#BB#PYG###BBG#B#&&&&&&B#&&&&&&&GB&###&##&&&&&#B#B#&&&#B&###GGG#&&&&#GB&&&#B7:7B@@@@@@@B7:~YGY!?555
&&&#PG##PJYGB##BG#&&&&&###&&&&&&&B5##B#&&#&&&&&&GBGGB###B##B##PG&&&&&#GB&&&G::G@@@@@@&5~:75GBBY!JPGG
&&&#G5P#&#PJ7YGBGGB########&&&&###5PGGG&&&&&&&&&GB#BB#&&&G##B#BB#&&#&#GB&&#^:#@@@@@B7:!YB#GPBGY!JPPP
&&&#GPG#&&&&#GGBGGG####&&&GB&####BGGGGPB#&&&&&&#GBB#BB&&&GP##B#BB&#&&#GB&@Y 5@@@@@G :P&&#BGPGGY!JPPP
&&&#PGBGBB#&&&&&B#B####&&&BP#&&&&GGB#BGPG###&&&BGBB#GG#&##GG&BBGG###&#PB&&? &@@@@@J !B&&&&#BBGY!JPPP
&&&#5GBB#BBB#&&&######&&&&&PPB&&&PPBBGPPGB#####G###57!?YJ5PPGGGBPB###BPG#&J.777777^ 7B@@@&&&&#Y!JPGG
&&&#5GGG&##BBBBBBB&G#&&&&&&BGBBGBY7!^::^YB##BBBB###P7!^~7Y?PBGGBBGB#BGPPBBPJ????!. .!5GGGGGGGPJ!?5PP
&&&#PPGB&BBB#&##BG&5B&&&&&&#GBP!Y5?7!!J7J####BB#BB##5Y5YJ#PPB#BG#BBBGG55GG7 !777!!!^ 7JJJJ??77!^!777
&&&#PGGB&BBB#&&#&B&55&&&&&&&BGB#B#5Y5P5YG############BGPB#PPBG#BBGG&&#GG#&? &@@@@@@J PBBBBBGGPJ!JPPP
&&&#GGGB###B##&&&##GPB#&&&&&&GG#&##BGGBB##############BBBBG5BB#BGGG###GG#&? &@@@@@@J P#BBGGGBGY!JGGG
&&&#BGGB5#####&&#5BBPB##&&&&&BGB##BBBBBBB#################BPG#&GBGGB&#GB#&? B#####&? 5GGGPPGBBY!YB##
&&&##BGBP#&####&PJGP5P###&@&&&GG###################&#######P5BB##BBB&#GB##Y~!!!!~:..:5BBBBBGGGY!Y#&&
&&&#&#GGB#&#BB#GJY5P55G##&@&&&#P#############GPPPP5PB######P5GGBGGBG##GB####BBBGY^.:7PBBB###&#Y!JB##
&&#&##GGBB&#BBBYY55PP55###&&&#&B###########&B5PPGGP5G#####G55GBBBBGG&#GB&&#GGGGPY^.:!5GBBBB###Y7JB#&
####&#PBBB&#BBPY5P55PG5B&#&&&BB&B#######################BGPP5PB##GPGGGPPBBPYJJJJ7:.:~????JJJJJ7~7Y55
######5BBB&##GY55PP5PGGPB&&&&#P#G5B###&&##############BPPGP555#BBGBGBBGB##BGGGBGY:.:!YPPPPPP55?~7Y5Y
PPPGGPYBBG&&&P555PPP5PPPPB&&&&GPB?JY55PGBB#####&####BP55GPP555&#55GG##B#&&###&##5^.:!5###&&&&#5!Y&&&
YYYJJY?YYG&&G5555PPPYYPP5P#&&&#5BYJYYYYYYYYY555PPP555PPPGP555P&&GPGB##B#&&&###&#5^.:!P##&&&&&#5!Y#&&
YYJJ?J??JG&BP555Y5PPY?5PPYP&&&&PPGJYYYYYYYYYYYYJ55Y5PP5PG555PP&#BBBB&#B#&&&&##&&5^.:7G&&&&&&&#Y~Y#&&
JJJJ?J5GBB#5GP5P5Y55YYJPP5JP&&&BYGJ?YYYYYYYYYY77PP55PP5PP55YY5&#G#GG&#B#&&&###&BJ:.^?P&&&&&&&#Y~Y#&&
YYYYY5BB#BBPBG55PY5B5?7?Y5YJP&&B55? :~7JYYYYJ^ .55Y5P5YJ?!~^.!&#G##B&#B#&&&GYYJ!:..:^7YPBB####Y~J##&
JJJYG####GBGBBP55G#&5   .:^~75&B7:!.   .755Y:   :..:~~^.     7&YP##GBBGGBBBJ^:......:^~7?Y5YYJ7~7Y5P
7?YG&&&&&BB#GBG5P#&&&Y        7#7  .     !Y~                 JJ^B#BBBPPPBBGP5Y!^~!~:.:?5PGBBGGP5PP55
J5B&&&&&&#P#BGGBB#&&&&Y.       ~!  .      :                  7 7##B#&BBBBBBG5J77JYY?!!7??5BBGGBB##&&
#&&&&&&&&&BPBBB##&&&&&@5.       .       ^JPY?~.               .GBB#&&&###GY?7777??YYYJJJYYPPPGBBB#&&
&&&&&&&&&&BG##########&&P.           .~JPGBBBG5J?!^.          Y#GB##&#BGGYY7~!!!!!77????JJJJYYYY5PGB
########&&##GB#&&&&#####&G:         :5#BBBBBBBBB##G:         ~&#B####BGB#55Y???7777777???77!!!!!!!!!
############PB#BB##&&&&&&@B^         ^5#&#########7         !#&&@&BBB####GPBG55PGGPP55YYJJJ??777!!!!
############PB###BBB##&&&&&#!          ?B#######&P         7&@&BP5G######BPBB?:!5BBBBBBBBBBGGGPPP55Y
############P#######BBBB##&@&Y.         ~G###BB#&?        J#G5YJ5B########GP5^  ~PBBBBBBBBBBBBBBBBBB
############G#####B###BGGPPPGBP?!^:.     :YPJ~:~?.    .:~JPJ!7YG##########BY!.^:^5BBBBBBBBBBBBBBBBBB
######BBBBBBP#####BBB###BGGP?7?5PPP5YJ7~:         .:!?JYYYY5J?YB#B#BB######Y   .7GBBBBBBBBBBBBBBBBBB
BBBBGGGGBB#BG######BGGGBB###PJJYY55J?JJYYY?!:^7J?7JYJ??JY555GGYP#BBGB######G:  .JBBBBBBBBBBBBBBBBBBB
PPPGGGGGBGJ!Y#######BG5P###BGYGBGP555YJ7777!!J????7!?Y5GBBB&&&G5###BPG#####B?.~JBBBBBBBBBBBBBBBBBBBB
*/

    m_arm.SetDefaultCommand(
        ArmDrive(
            [this] {
                return (
                    m_stick3.GetY() / 5
                );
            },
            m_arm
        )
    );

    // Configure the button bindings
    ConfigureButtonBindings();

    // if (m_stick2.GetRawButton(3)){
    //     speed += 0.01;
    // }
    // if (m_stick2.GetRawButton(5)){
    //     speed -= 0.01;
    // }
}

void RobotContainer::ConfigureButtonBindings() {
    frc2::JoystickButton(&m_stick3,3).WhenHeld(
        IntakeDrive(m_intake, 0.5)
    );
    frc2::JoystickButton(&m_stick3,4).WhenHeld(
        IntakeDrive(m_intake, -1)
    );
    frc2::JoystickButton(&m_stick3, 1).WhenPressed(
        TankMoveGyro(m_drivetrain, 4, 0.25)
    );

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    // An example command will be run in autonomous
    return m_chooser.GetSelected();
}
