#pragma once

// Simulate ARKit on non-iOS platforms

#include "CinderARKit.h"

#ifndef CINDER_COCOA_TOUCH
namespace ARKit
{
CameraPersp mCam;

SessionImpl::SessionImpl() {}
SessionImpl::~SessionImpl() {}

Session::Session() {}

Anchor kFakeAncor = {"kFaker", mat4(1.0)};
std::vector<Anchor> fakeAncors = {kFakeAncor};
std::vector<PlaneAnchor> fakePlaneAncors = {};

const AnchorID Session::addAnchorRelativeToCamera(vec3 offset)
{
    // TODO: implement it
    return kFakeAncor.mUid;
}

void Session::runConfiguration(SessionConfiguration config)
{
}

void Session::drawRGBCaptureTexture(Area area) const
{
}

const mat4 Session::getViewMatrix() const
{
    return mCam.getViewMatrix();
}

const mat4 Session::getProjectionMatrix() const
{
    return mCam.getProjectionMatrix();
}

const std::vector<Anchor> &Session::getAnchors() const
{
    return fakeAncors;
}

const std::vector<PlaneAnchor> &Session::getPlaneAnchors() const
{
    return fakePlaneAncors;
}

} // namespace ARKit
#endif