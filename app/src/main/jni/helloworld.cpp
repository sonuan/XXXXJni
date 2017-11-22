//
// Created by sonuan on 2017/9/28.
//

#include "com_sonuan_xxxxjni_HelloJNI.h"
#include <string.h>
#include <stdio.h>
#include <android/log.h>

#define TAG "JNI"
/*
 * Class:     com_sonuan_xxxxjni_HelloJNI
 * Method:    jniForHelloWorld
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_sonuan_xxxxjni_HelloJNI_jniForHelloWorld(JNIEnv *env, jobject instance){
    jstring javaString;
    javaString = env->NewStringUTF("Hello JNI1!");
    return javaString;
}

JNIEXPORT jstring JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_jniForStatic(JNIEnv *env, jclass type) {
    return env->NewStringUTF("Hello Static!");
}

JNIEXPORT void JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_jstringToCString(JNIEnv *env, jobject instance, jstring javaString) {
    const char *str = env->GetStringUTFChars(javaString, 0);

    if (0 != str) {
        printf("Java string:%s", str);
    }

    env->ReleaseStringUTFChars(javaString, str);
}

JNIEXPORT jobjectArray JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_newJavaArray(JNIEnv *env, jobject instance) {

    jclass cls = env->FindClass("java/lang/String");
    jobjectArray javaArray = env->NewObjectArray(3, cls, NULL);
    if (0 != javaArray) {
        __android_log_print(ANDROID_LOG_INFO, TAG, "new array");
    }
    return javaArray;
}

JNIEXPORT jintArray JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_updateJavaIntArray(JNIEnv *env, jobject instance, jintArray javaArray, jint size) {
    //定义一个C数组
    jint nativeArray[size];
    //将Java数组区复制到C数组中
    env->GetIntArrayRegion(javaArray, 0, size, nativeArray);
    __android_log_print(ANDROID_LOG_INFO, TAG, "get int array: %s", nativeArray[0]);
    for (int i = 0; i <size; i++) {
        nativeArray[i] = nativeArray[i] * 2;
    }
    //从C数组向Java数组提交所做的修改
    env->SetIntArrayRegion(javaArray, 0, size, nativeArray);
    __android_log_print(ANDROID_LOG_INFO, TAG, "set int array: %s", (char *) javaArray);
    return javaArray;
}

JNIEXPORT jobjectArray JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_updateJavaObjectArray(JNIEnv *env, jobject instance, jobjectArray javaArray,
                                                       jint size) {
    for (int i = 0; i < size; i++) {
        jstring javaString = (jstring) env->GetObjectArrayElement(javaArray, i);
        const char *string = env->GetStringUTFChars(javaString, NULL);
        __android_log_print(ANDROID_LOG_INFO, TAG, "get string: %s" , string);
    }
    return javaArray;
}

JNIEXPORT jintArray JNICALL
Java_com_sonuan_xxxxjni_HelloJNI_updateJavaIntArray2(JNIEnv *env, jobject instance, jintArray javaArray_, jint size) {
    // 获得指向Java数组元素的直接指针
    jint *array = env->GetIntArrayElements(javaArray_, NULL);
    for (int i = 0; i < size; i++) {
        array[i]= array[i] * 3;
//        __android_log_print(ANDROID_LOG_INFO, TAG, "get int: %d", array[i]);
    }
//    env->SetIntArrayRegion(javaArray_, 0, size, array);
    // 释放指向Java数组元素的直接指针
    env->ReleaseIntArrayElements(javaArray_, array, 0);
    return javaArray_;
}