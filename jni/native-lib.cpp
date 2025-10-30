#include <jni.h>
#include <android/log.h>
#include <opencv2/opencv.hpp>

using namespace cv;

extern "C" {
JNIEXPORT void JNICALL
Java_com_example_edgeviewer_MainActivity_processFrame(JNIEnv *env, jobject instance, jlong matAddrInput, jlong matAddrOutput) {
    Mat &input = *(Mat *) matAddrInput;
    Mat &output = *(Mat *) matAddrOutput;
    if (input.empty()) return;

    // convert to gray
    Mat gray;
    cvtColor(input, gray, COLOR_RGBA2GRAY);
    // Canny edges
    Mat edges;
    Canny(gray, edges, 50, 150);
    // convert to RGBA for OpenGL texture
    cvtColor(edges, output, COLOR_GRAY2RGBA);
}
}
