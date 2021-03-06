//
// Created by syonfox on 18/03/19.
//

#include "motion.hpp"
#include <iostream>


#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn/dnn.hpp>

#define MPI

#ifdef MPI


const int POSE_PAIRS[14][2] =
        {
                {0,1},
                {1,2},

                {2,3},
                {3,4},

                {1,5},

                {5,6},
                {6,7},
                {1,14},
                {14,8},
                {8,9},
                {9,10},
                {14,11},
                {11,12},
                {12,13}
        };

// 0 (HEAD ), 1 (NECK) , 2 (Right shoulder), 5 (LEFT shoulder)

std::string protoFile = "../pose/mpi/pose_deploy_linevec_faster_4_stages.prototxt";
std::string weightsFile = "../pose/mpi/pose_iter_160000.caffemodel";

int nPoints = 15;

#endif

#ifdef COCO
const int POSE_PAIRS[17][2] =
{
    {1,2}, {1,5}, {2,3},
    {3,4}, {5,6}, {6,7},
    {1,8}, {8,9}, {9,10},
    {1,11}, {11,12}, {12,13},
    {1,0}, {0,14},
    {14,16}, {0,15}, {15,17}
};

string protoFile = "pose/coco/pose_deploy_linevec.prototxt";
string weightsFile = "pose/coco/pose_iter_440000.caffemodel";

int nPoints = 18;
#endif


//using namespace std;
//using namespace cv;
//using namespace cv::dnn;

void* Motion::pose_detection(void *threadid) {


    std::string videoFile = "../testsquathorz.mp4";

    // Take arguments from commmand line
    int inWidth = 368;
    int inHeight = 368;
    float thresh = 0.05;

    cv::VideoCapture cap(videoFile);
    //cv::VideoCapture cap(0);
    //cap has the video file

    if (!cap.isOpened())
    {
        std::cerr << "Unable to connect to camera" << std::endl;
        running = false;
        return 0;
    }

    cv::Mat frame, frameCopy;
    int frameWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int frameHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    cv::VideoWriter video("Output-Skeleton.avi",cv::VideoWriter::fourcc('M','J','P','G'), 10, cv::Size(frameWidth,frameHeight));

    //video is where the output location

    cv::dnn::Net net = cv::dnn::readNetFromCaffe(protoFile, weightsFile);

    double t=0;

    //cap.release();
    while( cv::waitKey(1) < 0 && running)
    {
        double t = (double) cv::getTickCount();

        //cap.open(0);
        cap >> frame;
        //cv::Mat img;
        //img.create(frameWidth, frameHeight, CV_32F);
        //cap.set(cv::CAP_PROP_POS_AVI_RATIO, 1);

        //cap.read(img);

        //frame = img.clone();

        //cap.release();
        frameCopy = frame.clone();

        //changin the input image to blob type of dimension 368, 368
        cv::Mat inpBlob = cv::dnn::blobFromImage(frame, 1.0 / 255, cv::Size(inWidth, inHeight), cv::Scalar(0, 0, 0), false, false);

        net.setInput(inpBlob);

        cv::Mat output = net.forward();
        //cv::Mat output = frame.clone();


        int H = output.size[2];
        std::cout << "H : " << H << "\n";

        int W = output.size[3];
        // find the position of the body parts
        std::cout << "W : " << W << "\n";

        std::vector<cv::Point> points(nPoints); //15 points nPoints = 15

        for (int n=0; n < nPoints; n++)
        {
            // Probability map of corresponding body's part.
            cv::Mat probMap(H, W, CV_32F, output.ptr(0,n));

            cv::Point2f p(-1,-1);
            cv::Point maxLoc;
            double prob;

            minMaxLoc(probMap, 0, &prob, 0, &maxLoc);
            if (prob > thresh)
            {
                p = maxLoc;
                p.x = p.x * ( (float)frameWidth / W )  ;
                p.y *= (float)frameHeight / H ;

                circle(frameCopy, cv::Point((int)p.x, (int)p.y), 8, cv::Scalar(0,255,255), -1);
                cv::putText(frameCopy, cv::format("%d", n), cv::Point((int)p.x, (int)p.y), cv::FONT_HERSHEY_COMPLEX, 1.1, cv::Scalar(0, 0, 255), 2);
            }
            points[n] = p;
        }


        float cutHeights = (15) * ( (float)frameHeight / H );
        cv::Point2f start (0.0f , cutHeights);
        cv::Point2f end (frameWidth , cutHeights);

        line(frame, start , end, cv::Scalar(0,255,255), 8);

        if ( points[1].y > cutHeights  || points[2].y > cutHeights || points[5].y > cutHeights) {

            pose = Pose::CROUCH;

        }

        else   {

            pose = Pose::STAND;
        }

        //points[n] = co-oridinate actual image

        int nPairs = sizeof(POSE_PAIRS)/sizeof(POSE_PAIRS[0]); // we have 14 pairs = 28/2 ?

        for (int n = 0; n < nPairs; n++)
        {
            // lookup 2 connected body/hand parts
            cv::Point2f partA = points[POSE_PAIRS[n][0]];
            std::cout << " POINT 1 x =" << partA.x << "AND y=" << partA.y << "\n";
            cv::Point2f partB = points[POSE_PAIRS[n][1]];
            std::cout << " POINT 2 x =" << partB.x << "AND y=" << partB.y << "\n";

            if (partA.x<=0 || partA.y<=0 || partB.x<=0 || partB.y<=0)
                continue;

            line(frame, partA, partB, cv::Scalar(0,255,255), 8);
            circle(frame, partA, 8, cv::Scalar(0,0,255), -1);
            circle(frame, partB, 8, cv::Scalar(0,0,255), -1);
        }


        t = ((double)cv::getTickCount() - t)/cv::getTickFrequency();
        cv::putText(frame, cv::format("time taken = %.2f sec", t), cv::Point(50, 50), cv::FONT_HERSHEY_COMPLEX, .8, cv::Scalar(255, 50, 0), 2);
        imshow("Output-Keypoints", frameCopy);
        imshow("Output-Skeleton", frame);


//        if(points[0] < 200) {
//            pose = Pose::CROUCH;
//        }

        //video.write(frame);


    }

    // When everything done, release the video capture and write object
    cap.release();
    video.release();

    return 0;
}


bool Motion::isRunning() { return  running; }

Pose Motion::getPose() {
    return pose;
}
Pose Motion::pose;
bool Motion::running;
pthread_t Motion::poseThread;
int Motion::init() {
    int rc;

    running = true;
    //Other Setup here

//    int tid;
//    pthread_t poseThread;

    std::cout << "Status: Creating Pose Detection Thread, " << std::endl;

    rc = pthread_create(&poseThread, NULL, pose_detection, NULL);

    if (rc) {
        std::cerr << "Error: unable to create thread," << rc << std::endl;
        exit(-1);
    }


    return 0;


}

int Motion::shutdown() {
    int rc;

    std::cout << "Status: Shuting Down Motion " << std::endl;
    running = false;

    rc = pthread_join(poseThread,NULL); //somting s wrong here
    if (rc) {
        std::cerr << "Error:unable to join thread," << rc << std::endl;
        exit(-1);
    }
    std::cout << "Status: Pose Thread Joined " << rc << std::endl;

    return 0;

}