# Requirements (part 1)
- [x] Idle animation **with refresh rate of 1 second**
- [x] Top of the screen has STATUS:
    1. [x] Age (in hours:minutes:seconds)
    2. [x] Happiness (with associated bar representing the status e.g. battery with 5 bars, **decreases 1 bar every 5 seconds**)
    3. [x] Satiety (with associated bar representing the status e.g. battery with 5 bars, **decreases 1 bar every 5 seconds**)
- [x] Bottom of the screen has COMMANDS, when any are clicked, a food/snack (must be different) appears on the screen. Pet moves towards it and eats it. **Eating animation must last for at least 1 second**. Use joystick to select the food option. Food selection during eating is disabled. Show the currently selected COMMAND by highlighting it in some way.
    1. [x] Meal -> satisfies hunger **by one bar**
    2. [x] Snack -> satisfies happiness **by one bar**
- [x] If any of the bars are empty, the pet runs away (with basic animation), a message should be shown on screen, age counter stops and a RESET button replaces the COMMANDS at the bottom. Clicking RESET by using the joystick resets the game to the initial state.
# Requirements (part 2)
- [x] Cuddles animation
    1. [x] Use touchscreen
    2. [x] last 2 seconds
    3. [x] only on the actual tamagotchi, increases happiness by one bar
- [x] Sound effects (simple sounds, nothing complex required)
    1. [x] Click of the Meal/Snack option
    2. [x] Eating animation
    3. [x] Run animation
    4. [x] Cuddles animation
- [x] Volume handling with potentiometer every 50 ms
    1. [x] Have a speaker icon with the volume level
    2. [x] When muted, use a different icon to signal the muting of the audio


# Application note
- max 1 page
- describes one of the newly implemented features
- instructional or tutorial style
- targeted audience
- It is typically a focused description of how to do something, including an introduction to the topic as well as precise implementation details, results, and recommendations. It is more than just the repetition of information from part of a spec sheet. 
For example: the writer should have done something with the information from a spec sheet, and describe how it was done or how ONE should do it. 
- It often includes references to other manuals, documents, or books where the user may gain more or related information.  You can avoid adding references.