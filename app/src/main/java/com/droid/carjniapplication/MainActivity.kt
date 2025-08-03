package com.droid.carjniapplication

import android.annotation.SuppressLint
import android.os.Bundle
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import com.droid.nativelib.NativeMathLib

class MainActivity : AppCompatActivity() {
    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val result = NativeMathLib().vectorMultiplication(3f,4f,2f)
        findViewById<TextView>(R.id.helloWorldText).text = "[${result[0]},${result[1]}]"
    }
}