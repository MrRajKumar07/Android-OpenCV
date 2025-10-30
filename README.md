# 🧪 Android + OpenCV-C++ + OpenGL + Web Assessment

### 🚀 Real-Time Edge Detection Viewer  
A time-bound technical assessment integrating **Android Camera**, **OpenCV (C++)**, **OpenGL ES**, **JNI**, and a minimal **TypeScript Web Viewer**.

---

## 📦 Project Overview

This project demonstrates:
- Real-time camera capture on Android using **Camera2 API**.
- Frame processing in **native C++** via **OpenCV** (e.g., Canny edge detection / grayscale).
- Rendering the processed frame via **OpenGL ES 2.0**.
- Exporting or previewing the processed frame in a **TypeScript-based web viewer**.

---

## 🧱 Architecture Overview

```mermaid
flowchart TD
    A[Camera2 API] --> B[Java Frame Buffer]
    B --> C[JNI Bridge]
    C --> D[Native C++ - OpenCV Processing]
    D --> E[OpenGL Renderer]
    E --> F[Display in Android View]
    D --> G[Exported Frame (PNG)]
    G --> H[Web Viewer (TypeScript)]
🧩 Folder Structure
swift
Copy code
edge_assessment/
├── app/
│   ├── src/main/java/com/example/edgeviewer/
│   │   └── MainActivity.java
│   └── res/layout/
│       └── activity_main.xml
│
├── jni/
│   ├── CMakeLists.txt
│   └── native-lib.cpp
│
├── gl/
│   └── GLRenderer.java
│
├── web/
│   ├── index.html
│   ├── main.ts
│   ├── tsconfig.json
│   └── processed_sample.png
│
└── README.md
⚙️ Setup Instructions
🧰 Prerequisites
Android Studio (latest)

OpenCV Android SDK

Android NDK + CMake

Node.js + TypeScript (npm install -g typescript)

🧩 Android Setup
Clone the repository:

bash
Copy code
git clone https://github.com/yourusername/edge_assessment.git
cd edge_assessment
Open in Android Studio.

Configure NDK path in local.properties:

ini
Copy code
ndk.dir=/path/to/android-ndk
sdk.dir=/path/to/android-sdk
Copy OpenCV SDK to /OpenCV-android-sdk/ and link in CMakeLists.txt.

Build and Run on a real device.

🌐 Web Setup
Navigate to the web folder:

bash
Copy code
cd web
npm install
tsc
Open index.html in a browser — displays a static processed frame with overlayed FPS/resolution.

🧠 Architecture Explanation
🔹 Frame Flow
Camera2 API captures preview frames → SurfaceTexture.

Java sends frames to native via JNI → native-lib.cpp.

C++ uses OpenCV to perform edge detection (cv::Canny) or grayscale conversion.

The processed frame is rendered back using OpenGL ES 2.0 as a texture.

Optionally, the processed frame is saved as a PNG for the Web Viewer.

🔹 JNI Communication
Java calls:

java
Copy code
processFrameJNI(long nativeObjAddr);
Native implementation:

cpp
Copy code
JNIEXPORT void JNICALL Java_com_example_edgeviewer_MainActivity_processFrameJNI
(JNIEnv* env, jobject obj, jlong matAddr) {
    cv::Mat& frame = *(cv::Mat*)matAddr;
    cv::Canny(frame, frame, 80, 150);
}
🔹 OpenGL Renderer
Uses GLSurfaceView to render processed textures.

Frame data uploaded as texture via glTexImage2D.

Simple fragment shader handles color mapping.

🌐 Web Viewer Details
Built using TypeScript + HTML5.

Displays a sample processed image (processed_sample.png).

FPS and resolution displayed via DOM updates.

Example:

typescript
Copy code
document.getElementById("fps")!.innerText = "FPS: 15";
document.getElementById("resolution")!.innerText = "Resolution: 640x480";
⭐️ Bonus Features (Optional)
Toggle Button: Raw ↔ Processed frame

FPS Counter (in Java via frame time logs)

Grayscale / Invert shaders

Mock WebSocket feed (send base64 frame to web)

🧾 Commit History Guidelines
Meaningful commits for each development step:

bash
Copy code
git add .
git commit -m "Initial Android project setup"
git commit -m "Added JNI bridge and native-lib.cpp"
git commit -m "Integrated OpenCV Canny edge detection"
git commit -m "Added OpenGL texture rendering"
git commit -m "Implemented TypeScript web viewer"
git push origin main
