package com.mapzen.tangram;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.View;
import android.view.Window;
import android.util.Log;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;

public class MainActivity extends Activity
{

    private GLSurfaceView view;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        
        super.onCreate(savedInstanceState);
        
        requestWindowFeature(Window.FEATURE_NO_TITLE);

		view = new GLSurfaceView(getApplication());
		view.setEGLContextClientVersion(2);
        view.setEGLConfigChooser(8,8,8,8,16,0);
        Tangram tangram = new Tangram();
		view.setRenderer(tangram);
		setContentView(view);

        //Set the touchListener on the view
        view.setOnTouchListener(tangram);
    }
    
    @Override
	protected void onPause() 
	{
		super.onPause();
		view.onPause();
	}

	@Override
	protected void onResume() 
	{
		super.onResume();
		view.onResume();
	}
}

