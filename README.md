# rubiks-cube

### [Currently found bugs]
- If there's an extra space at the end of the input
the code copies the last turn and adds it, probably something to do with
how stringstream handles spaces.


### [Features currently in the works]
- Very Important: Add an option to input multiple algorithms into the
periodicity function and have them all be calculated withou the cube
being displayed since the function that checks if it's solved is flawless
there's no need for it to be displayed anyway.

- I noticed blinking on my own machine when the array for turns
got really long. A good feature would be to create a slider of sorts, where
the current turn moves to the center and is only surrounded by 3 turns
on both sides, as if it is sliding along the moveset. This would remove the
blinking that is probably caused by the output of the entire array repeatedly.
- For now the coloring is only supported on MacOS and Linux 
(Terminals that use bash and zsh), and probably WSL. Maybe I'll add a batch version in
the future, although the system("cls") might be a bit blinky since batch
terminals are a bit slow.
- Currently working on a generalized formula for calculating the periodicity of any
algorithm without repeating it until the cube returns to its solved state.