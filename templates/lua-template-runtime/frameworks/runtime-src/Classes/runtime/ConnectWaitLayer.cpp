/****************************************************************************
Copyright (c) 2013 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "ConnectWaitLayer.h"
#include "Runtime.h"
#include "FileServer.h"
#include "ConfigParser.h"
#include "VisibleRect.h"
#include "ResData.h"

using namespace cocos2d;

ConnectWaitLayer::ConnectWaitLayer()
{
    int designWidth = 1280;
    int designHeight = 800;
    
    if (ConfigParser::getInstance()->isLanscape())
    {
         if(!ConfigParser::getInstance()->ignoreDesignResolutionSize()) {
             Director::getInstance()->getOpenGLView()->setDesignResolutionSize(designWidth, designHeight, ResolutionPolicy::EXACT_FIT);
         }
    } else
    {
         if(!ConfigParser::getInstance()->ignoreDesignResolutionSize()) {
             Director::getInstance()->getOpenGLView()->setDesignResolutionSize(designHeight, designWidth, ResolutionPolicy::FIXED_HEIGHT);
         }
    }

    std::string strip = getIPAddress();
    char szIPAddress[64] = {0};
    sprintf(szIPAddress, "IP: %s", strip.c_str());
    auto IPlabel = Label::createWithSystemFont(szIPAddress, "", 72);
    IPlabel->setAnchorPoint(Vec2(0, 0));
    int spaceSizex = 72;
    int spaceSizey = 200;
    IPlabel->setPosition(Point(VisibleRect::leftTop().x + spaceSizex, VisibleRect::top().y - spaceSizey));
    addChild(IPlabel, 9001);

    
    auto runLabel = Label::createWithSystemFont("RUN", "", 72);
    runLabel->setAnchorPoint(Vec2(0.5, 0.5));
    runLabel->setPosition(Point(VisibleRect::center().x, VisibleRect::center().y));
    addChild(runLabel, 9002);

    
    std::string transferTip = "waiting for file transfer ...";
    if (CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM || CC_PLATFORM_MAC == CC_TARGET_PLATFORM)
    {
        transferTip = "waiting for debugger to connect ...";
    }

    char szVersion[256] = {0};
    sprintf(szVersion, "runtimeVersion:%s \nengineVersion:%s", getRuntimeVersion(), cocos2dVersion());
    Label* verLable = Label::createWithSystemFont(szVersion, "", 24);
    verLable->setAnchorPoint(Vec2(0, 0));
    int width = verLable->getBoundingBox().size.width;
    verLable->setPosition(Point(VisibleRect::right().x - width, VisibleRect::rightBottom().y));
    verLable->setAlignment(TextHAlignment::LEFT);
    addChild(verLable, 9003);

    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch* touch, Event  *event)->bool{
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 point = target->convertToNodeSpace(Director::getInstance()->convertToGL(touch->getLocationInView()));
        auto rect = Rect(0, 0, target->getContentSize().width, target->getContentSize().height);
        if (!rect.containsPoint(point)) return false;
        target->stopAllActions();
        target->runAction(Sequence::createWithTwoActions(ScaleBy::create(0.05f, 0.9f), ScaleTo::create(0.125f, 1)));
        return true;
    };
    listener->onTouchEnded = [](Touch* touch, Event  *event){
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 point = target->convertToNodeSpace(Director::getInstance()->convertToGL(touch->getLocationInView()));
        auto rect = Rect(0, 0, target->getContentSize().width, target->getContentSize().height);
        if (!rect.containsPoint(point)) return;
        startScript("");
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, runLabel);
}

ConnectWaitLayer::~ConnectWaitLayer()
{
}
