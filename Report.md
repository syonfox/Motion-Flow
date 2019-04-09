# Motion Flow
##### By: Kier Lindsay, Rafid Ashab Pranta

## Introduction

Motion flow is a game in which, we attempt to create a interesting arcade game from scratch and
experimented to control the game using Computer Vision.  
The players skies through randomly generated terrain and the objective of the game is 
travel the farthest and score as high as possible before night falls. 

#### Technology used

The game is build with in C++ with SFML Library, Thor Library and IMgui Library. 
//the game has it's own physics engine? 

The pose detection of the player is achieved with using OpenPose model created by CMU-Perpetual-Computing-Lab, Opencv
Libraries and Google Cloud Services.

We editied audios required for the game using audacity. Gimp was used to create and edit 
sprties for the game.


#### Motivation

We created an arcade game because arcade games are one of the major genre of games where people sit idly and play the
games with little to no movement. We wanted to create an arcade game that can be more physcially engaging.

Using computer vision that detects human motion and control the game using human motion, 
we can replace the cost for expensive sensors and controllers that are used currently in controlling game using
human motion. For example, Nintendo Wii , Xbox Kinect and PlayStation Move.

To use computer vision all we need is a webcam and possibly a graphics card for better game play. 

Most importantly our goal was to explore and demonstrate the a possible future use of Computer Vision and 
Machine learning in games. 

The goal was to use Computer Vision to detect human body pose or hand gesture to control the player in a game. 

## Related Work

https://github.com/CMU-Perceptual-Computing-Lab/openpose the openpose github that provided the caffemodels required 
to detect human pose and hand gesture.

### Concept (do we need a concept section ?)
#### Game Concept

The game concept started as a ski game where the player would ski down a
slope taking jumps and possibly tricks.  This idea took inspiration from
Altos Adventure.  After working on the intital sole mehanics and gettig//

#### ML Concepts


## Description

The game allows a player to ski down a slope and upon making a smooth landing on the slope of the terrain the player gains
speed. The goal of the game is get the highest score before the sun sets.

The player can get points in three ways : 
1. Points for distance travelled 
2. Bonus point for each perfect landing 
3. Consequetive perfect landings 

The game ends when the sun sets or the sky turns black (as night falls).

There are two different type of input for the game :
1. Keyboard : Pressing S on the keyboard speeds of the player when the player is on the ground and pulls the player downwards
when the player is on the air
2. Camera : The camera takes a picture of the player and detects keypoints of the player's body. If the player's shoulders are
below a certain horizontal line, it is equivalent of pressing s on the keyboard. If the players shoulder is above a certain 
it is eqivalent of not pressing the button S on keyboard. 


### The Game

Design of the game, how the classes interact with each other and a screen shot of the game. (Kier)


### Pose Detection

We the MPII model provided by OpenPose by CMU-Perceptual-Computing-Lab. The model detects 15 keypoints
of the human body. 

Which are the following :

Head – 0, 
Neck – 1, 
Right Shoulder – 2, 
Right Elbow – 3, 
Right Wrist – 4,
Left Shoulder – 5, 
Left Elbow – 6, 
Left Wrist – 7, 
Right Hip – 8,
Right Knee – 9, 
Right Ankle – 10, 
Left Hip – 11, 
Left Knee – 12,
Left Ankle – 13, 
Chest – 14

The point of interest in our program are Point 0,1,2 and 5. This encompasses the head neck and both shoulders.
The pose detection program checks if the Point (1,2,5) are below a certain horizontal line.

It is possible by loading the caffemodel provided by openpose using openCV in a net variable, which stores
the convulutional nueral network provided by the model. 

We can choose the input stream to from the webcam of the laptop or a video recording of a file. 
The input frames are then changed in a blob using OpenCV blobFromImage() function and the blob is passed to the network
to be analyzed.  

OpenCV then looks for every point defined by the MPII model and stores their co-ordinate in an
array of <cv::points>. The points array is used to detect if the shoulder is below or above the set horizontal line.


### Challenges

The image processing of pose-detection is a very intensive task for CPU and is particularly suited for GPUs. In an Intel 7th 
Quad-core processor can only analyze 0.5 frames per second.

To overcome this limitation, we have created a virtual instance on Google Cloud Platform with a 64 vCPUs.
which can analyze achieves a 5 FPS. 

However, this process is signigicantly faster on GPU's and due to our limited time and resources we were not able to load
the nueral network on a GPU and run image processing.

## Whats Missing?

Implementation of running the code in GPU. 

Improvements to the visuals and graphics of the game.

More interesting features such as multiplayer as the pose-detection algorithm is capable of detecting
more than one pose without affecting it's speed singnificantly.

Connecting webcam stream to the cloud 

Run the game on the cloud. 

## Discussion



## Credits and References


Sound clips used from : 

 https://freesound.org/people/E330/sounds/223082/
 https://freesound.org/people/Breviceps/sounds/454595/
 https://freesound.org/people/fschaeffer/sounds/337912/
 
Sprites were used from : 

 https://pixabay.com/vectors/tree-trunk-nature-leaves-branches-576836/
 
