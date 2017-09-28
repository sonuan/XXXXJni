//
// Created by sonuan on 2017/9/28.
//

#include "com_sonuan_xxxxjni_MainActivity.h"
#include <string.h>
/*
 * Class:     com_sonuan_xxxxjni_MainActivity
 * Method:    jniForHelloWorld
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_sonuan_xxxxjni_MainActivity_jniForHelloWorld(JNIEnv *env, jobject obj){
    return (*env).NewStringUTF("hello world ndk");
}
