//
// Created by syonfox on 18/03/19.
//

#ifndef MOTION_FLOW_MOTION_HPP
#define MOTION_FLOW_MOTION_HPP


#include <opencv2/core/mat.hpp>

enum class Pose{STAND,CROUCH, SNOWPLOW, JUMP, LEANLEFT, LEANRIGHT};

class Motion {
private:
    static void* pose_detection(void* threadid);

    static cv::Mat bones;
    static int tid;
    static pthread_t poseThread;

    static Pose pose;
public:


    static  int init();
    static  int shutdown();

    static Pose getPose();
    //static  cv::Mat get_bones();
    //array get_curent_scelition();
};


#endif //MOTION_FLOW_MOTION_HPP
