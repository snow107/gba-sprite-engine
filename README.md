
## A GBA platforming game

For a school project we had to make a game for the gameboy advance using the provided engine:
https://github.com/wgroeneveld/gba-sprite-engine

We made a platforming game where sonic needs to go through levels with spikes and jumps.

#### Game model

We tried to code in a way that it is easy to create new levels and add more mechanics to the levels without changing the code in every level.

We have implemented the following diagram: 

![alt text](https://raw.githubusercontent.com/snow107/gba-sprite-engine/master/img/Diagram.png)

The Engine has a scene which we need to Inherit to work with. We made a generic scene for our game which inherits from the engine scene.
In the genericScenen we have the mechanics of our game. This makes it easy to create more scenes.
 
#### Backgrounds

Our game uses 2 backgrounds and a sprite for the character. Background 1 is our level, we have collision detection
between our level and our character. Background 2 is just a aesthetic background.

The second scene has a level of 64x64 tiles (every tile is 8x8).  

### Screenshot from the game

![alt text](https://raw.githubusercontent.com/snow107/gba-sprite-engine/master/img/game.png)

### Features in the game

The first level is a standard small level with a few spikes where you can die.  
In the second level the map is larger and becomes a level of 64x64 tiles.  
The third level has jump pad to create a bigger jump height.  
The fourth and last level has rising water, which makes it a time based level.

If you die in a level you will respawn back at the start of the level.