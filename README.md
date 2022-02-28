# rubiks-cube

### [Currently found bugs]
- If there's an extra space at the end of the input
the code copies the last turn and adds it, probably something to do with
how stringstream handles spaces.


### [Currently working on this]
I noticed blinking on my own machine when the array for turns
got really long. A good feature would be to create a slider of sorts, where
the current turn moves to the center and is only surrounded by 3 turns
on both sides, as if it is sliding along the moveset. This would remove the
blinking that is probably caused by the output of the entire array repeatedly.
It would also add aesthetic value.