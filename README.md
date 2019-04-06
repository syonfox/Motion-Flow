
# Motion Flow

This is a small game made using opencv and sfml meant to demonstrate the
use of machine learing pose detection as control for games.  

#### Dependences:

* OpenCV 4+
* SFML 2.5.1
* Thor (v2)
* OpenGL
* cmake and c++ build environment

OpenCV can be built from source by fallowing this [Tutorial](https://docs.opencv.org/3.4/d7/d9f/tutorial_linux_install.html)

If SFML 2.5.1 is not avalibal in your repo use option 2 in the [SFML Tutorial](https://www.sfml-dev.org/tutorials/2.5/start-linux.php) 

You can install Thor with the following:
```
git clone https://github.com/Bromeon/Thor.git
cd Thor
cmake .
sudo make install
```

### Build/Run
In order to build download the repositiory and build using cmake
```
git clone https://github.com/syonfox/Motion-Flow.git
cd Motion_Flow
./getModels.sh
mkdir build
cd build
cmake ..
make -j 8
./motion_flow
```

#### Design
##### Main:
Setup sfml window
initalize Imgui
Run the core loop whitch calls various engine features and preformes drawing
frame rate and times are handeled here

##### Engine:
This is responsibal for manageing the game
TODO: 
- Make Engine setup a thread to do image proccessing and pass the inputs on to the player
- Implement Menu and settings


##### Player:
A player object whitch hanedls contole events and the players physiscs
Player Contorles:
Brake: Snowplow (A) // Not used
Speed Up : Crouch (D)
Nothing : Stand NOrmally



##### Slope:
An object whitch has an slopeFunction whitch defines the ski hill
it also provies functions for detecting collisions with the hill


##### TODO:

- Make Player respond to controles from "Motion.cpp" or from sf::keyboard
- Make motion.cpp Parse Bones and output Controls Input ()
- Get Motion working with webcam not just video file

- OPtimize video capture, under 0.5 sec/frame
- get opencv runing on gpu


- Add menu and pause screen
    - get game states working (done kindof)
    - make menue screen (done could be better)
    - make pause screen (done)
    - make game over screen (Done)

- add more debug info (optional)

- Gamplay
    - Smooth out speed boost?
    - fix player rotation (optional smooth the rotation on inpact)
    - Detect when player looses (Do this after the others stuff) (to hard of collision, flip over or somting)
    - //Make slope generated with perlian noise not a function
    - Insted of perlian noise make the sing wave more suitibal for jumps
    - Tune the physcs to be funner for jumps
        - Tune the constenst
        - detect when the player dose a good landing and give apropreat speed Boost
    - Fix tree bug when the dispaera on restart of game.

- Graphics

    - better player sprite
        - Better drawing
        - an animation (Optional)
    - better snow
        - (Done, I thynk its good enough)Better drawing of the ground
        - mabe snow falling from sky (Optional)
    - Add trees to sope or somting
    - add other things that are interesting like candy cains or raindear lol
    - add paralec effect to background (Rafid)
    - Landing text for how good the landing was.


- Sound DONE
    - background music (Rafid) Done
    - sliding sound effect Removed
    - crash sound effect  (Rafid) Done (Kinda hard to hear because of the background music)
    - speedup sound effect (Rafid) Done


 sources:
 Sond clips used from:
 https://freesound.org/people/E330/sounds/223082/

 https://pixabay.com/vectors/tree-trunk-nature-leaves-branches-576836/

 background music:
 8 Bit Happy! by HeatleyBros
 https://www.youtube.com/watch?v=jHcWhQUmJ8E
