package com.sonuan.xxxxjni;

/**
 * @author wusongyuan
 * @date 2017.11.20
 * @desc
 */

public class HelloJNI {

    public native String jniForHelloWorld();

    public native static String jniForStatic();

    public native void jstringToCString(String s);

    public native String[] newJavaArray();

    public native int[] updateJavaIntArray(int[] javaArray, int size);

    public native int[] updateJavaIntArray2(int[] javaArray, int size);

    public native String[] updateJavaObjectArray(String[] javaArray, int size);

    static {
        System.loadLibrary("helloworld");
    }
}
