#include <jni.h>

#ifndef _Included_com_sonuan_xxxxjni_HelloJNI
#define _Included_com_sonuan_xxxxjni_HelloJNI
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_com_sonuan_xxxxjni_HelloJNI_jniForHelloWorld(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_com_sonuan_xxxxjni_HelloJNI_jniForStatic(JNIEnv *env, jclass type);

JNIEXPORT void JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_jstringToCString(JNIEnv *env, jobject instance, jstring javaString);

JNIEXPORT jobjectArray JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_newJavaArray(JNIEnv *env, jobject instance);

JNIEXPORT jintArray JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_updateJavaIntArray(JNIEnv *env, jobject instance, jintArray javaArray_, jint size);

JNIEXPORT jobjectArray JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_updateJavaObjectArray(JNIEnv *env, jobject instance, jobjectArray javaArray,
                                                       jint size);
JNIEXPORT jintArray JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_updateJavaIntArray2(JNIEnv *env, jobject instance, jintArray javaArray_, jint size);

        #ifdef __cplusplus
}
#endif
#endif
