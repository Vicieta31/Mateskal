#ifndef SCENE_H
#define SCENE_H

//! Scene class
/*!
	Handles the scenes for the game.
*/
class Scene
{
public:
	//! Constructor of scene.
	Scene();

	//! Destructor
	virtual ~Scene();

	//! Initializes the scene.
	virtual void init();

	//! Function to withdraw anything owned by the class and call init
	virtual void reinit();

	//! Drawing of the scene
	virtual void render() = 0;

	//! Updating of the scene
	virtual void update() = 0;

	void setReInit(bool loaded = true) { mReinit = loaded; };
	bool mustReInit() { return mReinit; };

protected:
	bool mReinit; /*!<  Reload when returning to scene*/
};

#endif
