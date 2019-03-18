//
// Created by syonfox on 18/03/19.
//

#ifndef MOTION_FLOW_MOTION_HPP
#define MOTION_FLOW_MOTION_HPP


#include <opencv2/core/mat.hpp>

class Motion {
private:
    static void* pose_detection(void* threadid);

    static cv::Mat bones;
    static int tid;
    static pthread_t poseThread;

public:


    static  int init();
    static  int shutdown();
    //static  cv::Mat get_bones();
    //array get_curent_scelition();
    //
};


#endif //MOTION_FLOW_MOTION_HPP
