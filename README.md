# Android + OpenCV (C++) + OpenGL ES + Web
---

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

> Avoid single large commits. The grader expects to see progress.

---

## What to include in your final README screenshots/GIFs

* One GIF showing app running with camera -> processed edges rendered in GL
* If GIF not possible, add at least 3 screenshots: (1) raw camera, (2) processed (edges), (3) web viewer displaying sample image

---

## Need help? Next options I can do for you (pick any):

* Generate the complete *repo skeleton* as a downloadable ZIP (with all skeleton files) ready to import.
* Generate the full `native-lib.cpp`, `CMakeLists.txt`, and `app` Gradle configuration ready-to-build (best-effort — you may need to tweak OpenCV path).
* Create a step-by-step terminal script to build the native libs and run on a device.

---

Good luck — push often, and if you want I can produce the full file skeleton ZIP right now so you can import into Android Studio and begin implementation.
