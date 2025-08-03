package com.droid.nativelib

class NativeMathLib {

    external fun stringFromJNI(): String
    external fun add(x : Int, y: Int) : Int
    external fun vectorMultiplication(x : Float, y: Float, s: Float) : FloatArray

    companion object {
        init {
            System.loadLibrary("nativemath")
        }
    }
}