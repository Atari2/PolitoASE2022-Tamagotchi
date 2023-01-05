# Requirements
- [x] Idle animation **with refresh rate of 1 second**
- [x] Top of the screen has STATUS:
    1. [x] Age (in hours:minutes:seconds)
    2. [x] Happiness (with associated bar representing the status e.g. battery with 5 bars, **decreases 1 bar every 5 seconds**)
    3. [x] Satiety (with associated bar representing the status e.g. battery with 5 bars, **decreases 1 bar every 5 seconds**)
- [x] Bottom of the screen has COMMANDS, when any are clicked, a food/snack (must be different) appears on the screen. Pet moves towards it and eats it. **Eating animation must last for at least 1 second**. Use joystick to select the food option. Food selection during eating is disabled. Show the currently selected COMMAND by highlighting it in some way.
    1. [x] Meal -> satisfies hunger **by one bar**
    2. [x] Snack -> satisfies happiness **by one bar**
- [x] If any of the bars are empty, the pet runs away (with basic animation), a message should be shown on screen, age counter stops and a RESET button replaces the COMMANDS at the bottom. Clicking RESET by using the joystick resets the game to the initial state.


# Video notes
- 4 minutes
- should showcase all the requirements and basic functionality (idle animation, batteries, eating, running away, resetting)
- talk about the central 50 ms tick system and what it does (Timer1)
  - check state
  - do eating if needed
  - update age/batteries
  - update selected button
- talk about the 1000 ms animation system that updates the main idle animation (Timer0)
- talk about the rit (50 ms) that handles the joystick. It doesn't do things immediately, it just registers the input and sets a flag. The main "tick system" checks the flag and does the appropriate action.
- if time left talk about in-depth code things like the font scaler and basic drawing library.