#ifndef __Game__
#define __Game__

class Game {

public:

	Game() {}
	~Game() {}

	void init() { m_bRunning = true; }

	void renderer() {}
	void update() {}
	void handleEvents() {}
	void clean() {}
	// a function to acces the private running variable
	bool running() { return m_bRunning; }

private:

	bool m_bRunning;

};

#endif
