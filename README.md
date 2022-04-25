# WARNING: Make sure you deploy to the right robot!

Deploying to the wrong robot will permanently damage the motors. This code is designed for `03` (Everybot). 

# Thank you for a fun season!

---

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
