#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    w = 1024;
    h = 1024;
    ofSetWindowShape(w, h);
    
    shader.load("base.vert", "test.frag");
    ofDisableArbTex();
    
    fbo.allocate(w, h, GL_RGBA, 4);
    
    img.load("fang.jpg");
    
    fbo.begin();
    ofClear(0,255);
    fbo.end();
    
    sphere.set(30,500);
    glPointSize(1.);
//    sphere.setMode(OF_PRIMITIVE_POINTS);
    ofEnableDepthTest();
    
    plane.set(120,300,1000, 1000);
    
    img.getTexture().generateMipmap();
    fbo.getTexture().generateMipmap();
    
    img.getTexture().setTextureMinMagFilter(GL_MIPMAP, GL_LINEAR);
    fbo.getTexture().setTextureMinMagFilter(GL_MIPMAP, GL_LINEAR);
//    ofSetMinMagFilters(GL_MIPMAP, GL_MIPMAP);
//    plane.setMode(OF_PRIMITIVE_POINTS);
//    glPolygonMode(GL_FRONT, GL_POINT);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofClear(0,255);
    cam.begin();
        shader.begin();
        shader.setUniformTexture("tex0", img.getTexture(), 0);
        shader.setUniform1f("time", ofGetFrameNum()*0.01);
        shader.setUniform2f("res", w, h);
                            
//                img.draw(0,0);
//            sphere.drawVertices();
//    plane.drawVertices();
    ofPushMatrix();
    plane.draw();
//    ofTranslate(0, -10);
//    plane.draw();
    ofPopMatrix();
    
//    ofPushMatrix();
//    ofRotate(45,1,0,0);
//    ofRotate(70, 0,1,0);
//    ofScale(0.25, 0.25, 0.25);
//        sphere.drawWireframe();
//    ofPopMatrix();
        shader.end();
    cam.end();
    fbo.end();
    
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
