package com.sonuan.xxxxjni;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import java.util.Arrays;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "JNI-Activity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tvHelloWorld = (TextView) findViewById(R.id.tv_hello_world);
        HelloJNI jni = new HelloJNI();
        tvHelloWorld.append(jni.jniForHelloWorld() + "\n");
        tvHelloWorld.append(HelloJNI.jniForStatic() + "\n");
        jni.jstringToCString("I am Java String.");
        jni.newJavaArray();
        int[] intArray = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int[] intArrayAfterUpdate = jni.updateJavaIntArray(intArray, intArray.length);
        Log.i(TAG, "onCreate: 1: " + Arrays.toString(intArrayAfterUpdate));

        int[] intArrayAfterUpdate2 = jni.updateJavaIntArray2(intArray, intArray.length);
        Log.i(TAG, "onCreate: 2: " + Arrays.toString(intArrayAfterUpdate2));

        String[] textArray = {"I", "am", "JNI"};
        jni.updateJavaObjectArray(textArray, textArray.length);
    }


}
