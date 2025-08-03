#include <jni.h>
#include <string>
#include <android/log.h>
#include <Eigen/Dense>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOG_TAG "MathCalculatorJNI_CPP"

extern "C" JNIEXPORT jstring JNICALL
Java_com_droid_nativelib_NativeMathLib_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
/**/
extern "C" JNIEXPORT jint JNICALL
Java_com_droid_nativelib_NativeMathLib_add(JNIEnv * /* env */, jobject/* clazz */, jint x, jint y) {
    return x + y;
}

extern "C" JNIEXPORT jfloatArray JNICALL
Java_com_droid_nativelib_NativeMathLib_vectorMultiplication(
        JNIEnv* env,    // Now properly named and used
        jobject /* clazz */, // Not used in this specific function, but kept for clarity
        jfloat a,       // Input float for vector component
        jfloat b,       // Input float for vector component
        jfloat scalar   // Input float for scalar
) {
    LOGD("JNI: Entered vectorMultiplication native function.");
    LOGD("JNI: Input vector components: a=%.2f, b=%.2f, scalar=%.2f", a, b, scalar);

    // 1. Create Eigen::Vector2f from input floats
    Eigen::Vector2f v;
    v << a, b;
    LOGD("JNI: Eigen vector v initialized: [%.2f, %.2f]", v[0], v[1]);


    // 2. Perform the Eigen scalar multiplication
    Eigen::Vector2f result = v * scalar;
    LOGD("JNI: Eigen result vector: [%.2f, %.2f]", result[0], result[1]);

    // 3. Create a Java float array to hold the result
    // The array will have 2 elements for the X and Y components.
    jfloatArray javaResultArray = env->NewFloatArray(2);
    if (javaResultArray == nullptr) {
        LOGE("JNI: Failed to create new Java float array.");
        return nullptr; // Return null if array creation fails
    }

    // 4. Populate the Java array with the results from the Eigen vector
    jfloat temp[2];
    temp[0] = result[0]; // Get the X component
    temp[1] = result[1]; // Get the Y component

    // Copy the C++ float array into the Java float array
    env->SetFloatArrayRegion(javaResultArray, 0, 2, temp);

    LOGD("JNI: Successfully returned result vector to Java.");
    return javaResultArray; // Return the Java array
}