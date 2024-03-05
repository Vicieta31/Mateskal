#pragma once
class SceneDirector
{
public:
	~SceneDirector();
private:
	int scene;

	SceneDirector();

	static SceneDirector* pInstance;

	
protected:
};

