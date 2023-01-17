<div align="center">

 # FRC 8574 (Audeamus)'s 2022 Season Robot

 ![](https://img.shields.io/badge/license-WPILib-orange)
 ![](https://img.shields.io/github/v/release/roboticsmgci/2022-robot)
 ![](https://img.shields.io/github/contributors/roboticsmgci/2022-robot)
 ![](https://img.shields.io/github/last-commit/roboticsmgci/2022-robot)
 ![](https://img.shields.io/badge/deploy%20to-8574__03-blue)
 ![](https://img.shields.io/badge/made%20with-c%2B%2B-blue)

 ![](https://img.shields.io/badge/ontario%20district-rookie%20all%20stars-%23ffbf00?style=for-the-badge)
 ![](https://img.shields.io/badge/world%20championships-had%20fun-brightgreen?style=for-the-badge)

</div>

---

## ⚠ Make sure you deploy to the right robot!

Deploying to the wrong robot will permanently damage the motors. This code is designed for `03` (Everybot). 

## Thank you for a fun season!

---

# Table of Contents

- [Table of Contents](#table-of-contents)
- [About](#about)
- [Installation](#installation)
- [Contributing](#contributing)

# About

This is the code used for team 8574's robot in the 2022 FRC season. It was a chaotic yet enjoyable season; check out how we did at [The Blue Alliance](https://www.thebluealliance.com/team/8574/2022). This repository is technically now archived, but we may make small edits every so often.

# Installation

1. Follow [this guide](https://github.com/roboticsmgci/main/blob/main/guides/wpilib/.installation.md) on installing WPILib. The latest **2022** version definitely works. The 2023 version has not been tested yet.

2. Open the VSCode that was installation with WPILib

3. Press `Ctrl + Shift + P` to open the command palette

4. Search and select `WPILib: Build Robot Code` and wait for the process to complete

5. Connect to the robot you want to deploy to

6. Press `Ctrl + Shift + P` to open the command palette

7. Search and select `WPILib: Deploy Robot Code` and wait for the process to complete

# Contributing

The rules are generally lax, but here are a few ground rules.

 - The `main` branch should be updated with the most recent working code on the robot
 - Create a branch/fork to test new code, then merge into `main` once it works and is permanent
 - Commands must be ordered like the following:
    - `commands/autonomous/` has commands used in autonomous
    - `commands/common/` has complex command groups used often
    - `commands/` has lower level commands
 - Includes must be ordered alphabetically, in categories by this order: header, third-party libraries, first-party include
 - Variables are named in camelCase, if they are in an object's scope (i.e. command private), add a `m_` prefix
 - Follow the [PEP 8](https://peps.python.org/pep-0008/) style guide
