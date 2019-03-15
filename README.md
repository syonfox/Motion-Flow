
#Motion Flow

This is a small game made using opencv and sfml meant to demonstrate the
use of machine learing pose detection as control for games.  

####Dependences:

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

###Build/Run
In order to build download the repositiory and build using cmake
```
git clone https://github.com/syonfox/Motion-Flow.git
cd Motion_Flow
cmake.
make -j 8
./motion_flow 

```

####Design
#####Main:
Setup sfml window
initalize Imgui
Run the core loop whitch calls various engine features and preformes drawing
frame rate and times are handeled here

#####Engine:
This is responsibal for manageing the game
TODO: 
- Make Engine setup a thread to do image proccessing and pass the inputs on to the player
- Implement Menu and settings


#####Player:
A player object whitch hanedls contole events and the players physiscs

#####Slope:
An object whitch has an slopeFunction whitch defines the ski hill
it also provies functions for detecting collisions with the hill

