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
  

## ✅ Required Submission Checklist

* [ ] Public (or shareable private) GitHub/GitLab repository with commit history
* [ ] README.md (this file)
* [ ] `/app` Android Java/Kotlin source
* [ ] `/jni` C++ OpenCV code + `CMakeLists.txt`
* [ ] `/gl` OpenGL renderer classes
* [ ] `/web` TypeScript viewer (static sample image + stats)
* [ ] Screenshots or GIFs of the working app
* [ ] Clear commit history (see recommended commit plan below)

**Deadline:** *31 October 2025, 10:30 AM IST* — ensure the repo is pushed before this time.

---

## Features Implemented (Suggested for the README entry)

* Camera capture using `TextureView` / `SurfaceTexture` (Camera2 recommended)
* JNI bridge to native C++ (NDK + CMake)
* OpenCV (C++) processing: Grayscale + Canny Edge Detection
* Render processed frames using OpenGL ES 2.0 as a texture
* Minimal TypeScript web viewer showing a static processed frame + FPS text overlay
* Bonus: Toggle button (raw / processed) and FPS counter (optional)

---

## Quick Architecture Explanation

**High-level flow:**

```
Camera (SurfaceTexture) -> Java/Kotlin frame callback -> Mat (Java-side or direct native Mat) -> JNI -> native C++ (OpenCV) -> processed Mat -> upload to OpenGL texture -> GLSurfaceView renders texture
```

**Modules:**

* `/app` — Android app (camera setup, JNI calls, UI controls, lifecycle)
* `/jni` — native C++ code (OpenCV processing). Use `Mat` objects and JNI functions that accept `jlong` pointers to `cv::Mat`.
* `/gl` — OpenGL ES 2.0 renderer, shader programs, texture upload helper.
* `/web` — TypeScript + HTML viewer that displays a sample processed frame and a small stats overlay.

---

## Setup Instructions (short)

1. **Install prerequisites**

   * Android Studio (prefer latest stable)
   * Android NDK (r23b or compatible)
   * CMake (bundled with Android Studio or install separately)
   * OpenCV Android SDK (download from opencv.org) — extract and reference `sdk/native/jni/include` and `sdk/native/libs` in `CMakeLists.txt`

2. **Project-level**

   * Ensure `android.ndkVersion` in `build.gradle` matches installed NDK
   * In `app/build.gradle` enable externalNativeBuild with CMake and point to `CMakeLists.txt`

3. **Build & Run**

   * Build in Android Studio (Gradle will invoke CMake to produce the `.so`)
   * Grant camera permission on first run

4. **TypeScript Web Viewer**

   * `cd web && npm install` (if using dev dependencies)
   * `npx tsc` (compile `main.ts` -> `main.js`)
   * Open `index.html` in browser (static; no server needed)

---

## Recommended Commit Plan (example messages & cadence)

Make small focused commits. Push early & often.

1. `chore: repo skeleton + README` — add top-level folders and README
2. `feat: initial Android project (app module, activity)` — minimal MainActivity and gradle config
3. `feat: camera capture (TextureView) + frame callback` — capture frame buffer, log frames
4. `feat: add NDK integration + CMakeLists` — native-lib stub exported
5. `feat: JNI bridge + OpenCV native processing (canny skeleton)` — static image test
6. `feat: GL renderer skeleton (GLSurfaceView + GLRenderer)` — renders solid color
7. `feat: connect processed Mat -> upload to GL texture` — show processed texture
8. `feat: web viewer (TypeScript) + sample image` — basic viewer working
9. `fix: performance tweaks (frame throttling, conversions)`
10. `docs: add screenshots + final README updates`

---

## Example `git` commands to produce reasonable commit history

```bash
git init
git add README.md
git commit -m "chore: repo skeleton + README"
# create app boilerplate
git add app/
git commit -m "feat: initial Android app skeleton (MainActivity, gradle)"
# add native + CMake
git add jni/
git commit -m "feat: add NDK integration and CMakeLists"
# add JNI processing
git add jni/native-lib.cpp
git commit -m "feat: JNI bridge + openCV canny skeleton"
# add GL renderer
git add gl/
git commit -m "feat: add GLRenderer skeleton"
# add web viewer
git add web/
git commit -m "feat: add simple TypeScript web viewer and sample image"
# push
git remote add origin <repo-url>
git push -u origin main
```

---

