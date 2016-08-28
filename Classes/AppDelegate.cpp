#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;


const Size kDesignSize = Size(480, 320);
//const Size kDesignSize = Size(320, 480);


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

void setupResolutionPolicy(float designW, float designH)
{
	GLView *view = Director::getInstance()->getOpenGLView();
	Size screenSize = view->getFrameSize();
	
	float designRatio = designW / designH;
	float screenRatio = screenSize.height / screenSize.width;
	
	ResolutionPolicy resolutionPolicy = screenRatio < designRatio ?
	ResolutionPolicy::FIXED_HEIGHT : ResolutionPolicy::FIXED_WIDTH;
	
	view->setDesignResolutionSize(designW, designH, resolutionPolicy);
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
		
    }
	
	
	setupResolutionPolicy(kDesignSize.width, kDesignSize.height);
	director->setContentScaleFactor(2);

	
	FileUtils::getInstance()->addSearchPath("res");
	
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 30);

    // create a scene. it's an autorelease object
    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
