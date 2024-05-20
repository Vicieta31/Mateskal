#ifndef BASESCENE_H
#define BASESCENE_H

#pragma once

class BaseScene
{
public:
	//! Constructor of an empty Scene.
	BaseScene();

	//! Destructor
	virtual ~BaseScene();

	//! Initializes the Scene.
	virtual void init();

	//! Function to withdraw anything owned by the class and to call init
	virtual void reinit();

	//! Handles the drawing of the scene
	virtual void render() = 0;

	//! Handles the updating of the scene
	virtual void update() = 0;

	void setReInit(bool loaded = true) { mReinit = loaded; };
	bool mustReInit() { return mReinit; };
protected:

	bool mReinit;			/*!<  Reload when returning to scene*/

};

#endif