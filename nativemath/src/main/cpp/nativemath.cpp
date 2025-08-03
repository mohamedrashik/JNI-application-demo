#include <jni.h>
#include <string>
#include <android/log.h>

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
    LOGD("Native", "Adding %d + %d = %d", x, y, x + y);
    return x + y;
}