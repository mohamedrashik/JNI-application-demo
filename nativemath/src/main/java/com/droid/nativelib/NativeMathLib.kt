package com.droid.nativelib

class NativeMathLib {

    external fun stringFromJNI(): String
    external fun add(x : Int, y: Int) : Int

    companion object {
        init {
            System.loadLibrary("nativemath")
        }
    }
}