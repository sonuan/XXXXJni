package com.sonuan.xxxxjni;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tvHelloWorld = (TextView) findViewById(R.id.tv_hello_world);
        tvHelloWorld.setText(jniForHelloWorld());
    }

    public native String jniForHelloWorld();

    static {
        System.loadLibrary("helloworld");
    }
}
