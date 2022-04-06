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
&&&&@&&&&&&&&&&##BBB###&####BP55PPB##&###&&&##BGGGGG#&&@&&BGGB##BGPGB#B#&@@@@&&#P???5#&&####BBPYPBBB
&&&&&######&&&&&##BB&&##B####P5555G&&&####&&##BGPGB&&&&&&@#GGB##BGPG##B#@@&#BGGPJ!!7YB&##BBBBBGYPBBB
&&&##BBBB#&&&&&&&&&&&#######B5Y555G&&&B#&##&&#G###@@&#BYG@#GB###BPGB#GYJ77!777???77!!!!7?Y5P55YJY555
&&&&&###&&&&&&&&&&&#&&&&&&##B5Y555G&&##&###&&##&@&&@&Y!^P@#GB###BGGY!~7YG#&@@@@@@@@@@&BPJ~^75BPYPGBB
&&&&&&&&&&&&&&&&##B#&&&&&&&#B5Y555G##BB###&##&&&@&&@#7^^5&#GB###BJ^!P&@@@@@@@@@@@@@@@@@@@@BJ^!P5P###
&####B#&&&&&&&##BB#&&&###BB######&&&&&&&&&&#&&&&&&&&&P!^?&&B##&G^^G@@@@@@@#5?77!!!7?5#@@@@@@&7.?G#&#
#&&&##&@&&&&##BBB#&####&&&&&&&&##&&@&&&&&&@@&&&&&&&&&&P!J&&B#&B:!&@@@@@@B!~JPB##57!!!^!B@@@@@@Y Y&&&
Y!J55PG&@&&@&&&&&&&&&&&&&&&&&&&&&&&@&&&&&&@&&&&&&&&&&#&BP&#G#&!:&@@@@@@P.J&@@&@&G???5G?.G@@@@@@~^#&&
&?:^~7J5B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&###GP##^^??JY5GP ?@@&&&&&G??J5#B Y@@@@@@J B&#
@#7^^~YGGB&&&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&&&&&##BB&&#GPPP5YJ77&@&&&&&&G??J55^!&@@@@@@!:B##
&&B!^^?G###&&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@&&&&&&&#BB&&#B#&@@@&#&&&&&####GJ?7^^Y@@@@@@@Y JB##
&&&#J^!B&##&&&&@&&&&&&&&&&&&&&&&&#&&&&&&&&&&&&&&&&&&&&#&&&&B&&#B#&&&#BBB###BPPPPY!:^Y&@@@@@@#7.75555
&&&&&5!P&&###B#&&&&&&&@&#&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&#&&&&###B#&&&&&B#&&&###G7^!P@@@@@@@&J:7PY5PPP
&&&##&BG##&&###&#&&&&&&&#&&&&&&&&##&&&&&&&&&&&&&#&#&&&&&#&&&&BB#&@@@@&B#&@&&#?:?#@@@@@@@B?^!PBGY5GGG
&&&&BB&&BPPB#&&#B&&&&&&&&&&&&&&&@#G&&#&&&&&&&&@@B##B#&&&#&&#&&BB&&&&&&B#&&&#^^B@@@@@@&P!~?G###GYPBBB
&&&&#GB&&&BP5PB#B##&&&&&&&&&&&&&&#GBBB#&&&&@@&&&##&##&&&&B&&#&##&@&&@&B#&@&~^&@@@@@B?~75#&#B##GYPBBB
&&&&BBB&&&&&&BB####&&&&&&&B#&&&&######B#&&&@@&&&###&##&@@#B&&#&##&&&@&B#&@P P@@@@@B.~B@&&##BBBPYPBBB
&&&&BB#B##&&&@@@#&#&&&&&&@#B&&&@&BB#&##BB&&&&&&####&#B&@&&BB&##B#&&&&&B#&@J &@@@@@Y Y#@@@&&###PYPBBB
&&&&GB##&###&&@@&&&&&&&&&&&BB#&&&BB###BBB#&&&&&#&&&G5YPPPGBB####B#&&&#B#&&J.777777^.5#@@@@&&&&GYPBBB
&&&&GB##&&########&B&&&&&&@#B####P5YJ??JG#&&####&&&B5YJJ5G5B##B####&##BB##B5YYYY?!~7YG######BBPY5GBB
&&&&BB##&###&&&&##&G#&&&&&@&B#BYGG55YYP5P&&&&#####&&GGGGP&BB#&##&####BGGB#?.7777777^.5PPPPP555YJY555
&&&&BB##&###&&&&&#&GG&&&&&&@#B#&#&GPGBGPB&&&&&&&&&&&&##B#&BB#B&####&&&B#&&? &@@@@@@J G#######BPYPBBB
&&&&B###&&&#&&&&&&&#B#&&@&&@&B#&&&&#####&&&&&&&&&&&&&&####BG##&#BB#&&&B#&@? &@@@@@@J B&##BB###PYPB#B
&&&&##B#G&&&&&&&&B##B#&&@@@&@#B#&&#######&&&&&&&&&&&&&&&&&#BB&&#####&&B#&@? B#####&? G##BBBB##GYP#&&
&&&&&#B#B&&&#&&&BPBBGB&&&@@@@&BB&&&&&&&&&&&&&&&&&&&&&&&&&&&BB##&&###&&##&&P~!!!!!^^^~G########GYG&&&
&&&&&&###&@&##&#PGGBGG#&&&@@&@&B&&&&&&&&&&&&&#BBBBGB#&&&&&&BGB###B#B&&##&&&&####GJ7?5B###&&&&&GYP#&&
&&&&&&B###&&###GGBGBBGG&&&@@&&@#&&&&&&&&&&&&#GBBB#BG#&&&&&BGGB######&&##&&&####BPJ7?YG#####&&&GYP#&&
&&&&&&B###@###BGGBGGBBG#&&&&&##&#&&&&&&&&&&&&&&&&&&&&&&&##BBGB#&&BB##BBB##BPPPPP5???J5555PPPPP5J5GGB
&&&&&&G###&&&BGGGBBGBBBB#&&&&&B&BG#&&&&&&&&&&&&&&&&&&&#BBBBBGG&##B######&&######G?7?YGBBBBBBGG5J5GGP
BBBBBBP###&&&BGGGBBBGBBBB#@&&@BB#5PGGGB###&&&&&&&&&&#BGG#BBGGG&&GGBB&&#&&&&&&&&&G?7?YG&&&&&&&&GYG&@@
GGPPPP5PGB@&#GGGGBBBGGBBGB&@@@&G#GPGGGPPPPGGGGGBBBGGGBBB#BGGGB&&#B##&&#&&&&&&&&&G???YB&&&&&&&&GYG&@&
GGPPPP5PPB@#BGGGGGBBG5GBBPB&@&&BB#PGGGGGPPPPPPPPGGGGBBGBBGGGBB&&####&&#&&&&&&&&&GJ7?YB&&&&&&&&GYG&@&
PPPPPPGB##&GBBGBGPGGGPPBBGPB&&&#G#P5GGGGPGPGGGYYBBGBBBGBBGGGGG&&B&#B&&#&&&&&&&&#P?7J5B&&&@&&&&GYP&&&
PPPPGG##&##B#BGGBGG#G5Y5GGGPB@&#GB5^~?YPGGGGP7:~GGGBBGGP5YJ!~Y@#B&&#&&#&&&&BPPPY?77?JYPB##&&&&PJP&&&
PPPG#&&&&#####BGGB&@G^.:^!7JYG&#Y!J~..:~5GGG!..:~^^!?J7^..:  Y@GB&&###B####PJ??7777??JY5PGGGGP5J5GGB
55P#&&&&&##&##BGB&&@@G:     .^Y&J ^7:::.^JGJ:::::...:::.... .PP?#&###BBB###BGPYJJYJ?7?5GBB####BBBBGG
PG#&&&&&&&B&#BB##&&&&@G^  ..:::7Y::!~:::.:7^.::::::.:::^^:::^Y^Y&&#&&#######BP55PGG5YY55PG######&&&@
&&@@@@@@@@#B###&&&&&&@@G^:^^^^^:~!:^!::^75BGY?~^:::.:^^:^^^^^^!###&@@&#&&#G555555PPGGPPPPGBBB####&&@
@@@@@@@@@@##&&&&&&&&&&&@B!:^^^^:^^^:^~?PB#####BPYJ!^^^^:^^:^:^P&B#&&&&##BPPYYYYYYYY55555PPPPPPPGGBB#
&&&&&&&&&&&&##&&&&&&&&&&@B!:^^^^:^^^7B&########&&&#7^^^::::^:J&&#&&&####&BGG555555555555555YYYYYYYYY
&&&&&&&&&&&&B####&&&&&&&&@#?^^^^^^^^^7G&&&&&&&&&&&Y^^^^::^::J&@@@&####&&&#B##GGBBBBBGGGPPPP5555YYYYY
&&&&&&&&&&&&B#&&&###&&&&&&@&Y^^^^^^^^^~5#&&&&&&&&B~^^^:::^^Y&@&#BG#&&&&&&#B##5?YB###########BBBBBGGG
&&&&&&&&&&&&B&&&&&&&####&&&@@P~:^^^^^^^^?#&&&##&&5^^^::::~P&#GGPG#&&&&&&&&BBGJ!7YB##################
&&&&&&&&&&&&B&&&&&#&&&##BBBBB#BYJ7!~^::::7GB5?!?Y!^:::^!?PBPYYG##&&&&&&&&&#GY7??JG##################
&&&&&&######B&&&&&###&&&###BPY5BBBBGP5J7!^^^::^~^^^!?5PPGGGGPPG#&#&##&&&&&&P!!77YB##################
##########&#B&&&&&&##B###&&&BPPPGGGP5PPGGP5J!?5P5YPGP55PGGGGB#GB&##B#&&&&&&#7~~7P###################
BBBBB#####5?G&&&&&&&#BGB&&&#BG###BGGGPP5Y55YYPP5P55Y5GBB###&&&BB&&&#B#&&&&&#57JP####################
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
    frc2::JoystickButton(&m_stick3,5).WhenHeld(
        IntakeDrive(m_intake, 0.5)
    );
    frc2::JoystickButton(&m_stick3,4).WhenHeld(
        IntakeDrive(m_intake, -1)
    );

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    // An example command will be run in autonomous
    return m_chooser.GetSelected();
}
