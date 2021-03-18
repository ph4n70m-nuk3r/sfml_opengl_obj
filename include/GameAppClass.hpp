#ifndef GAMEAPP_HPP_INCLUDED
#define GAMEAPP_HPP_INCLUDED

class
GameApp
	{
		public:
		    // Constructor taking args
		    GameApp(const std::string title, const int width, const int height);

		    // Disable default constructor C++11 FEATURE ( GameApp game; //will not compile )
		    GameApp() = delete;

		    // Initialisation code
		    void
			Init();

		    // Loop code
		    void
			Run();

		    // Render window & graphics
		    void
			Render();

		    void
			V_pop(GLfloat);

		private:
		    sf::Window
			m_window;

		    std::vector<GLfloat>
			v_dat; //Vertex data stored as vector of GLfloat

		    std::vector<GLfloat>
			n_dat; //Vertex data stored as vector of GLfloat

		    std::vector<GLushort>
			e_dat; //Vertex data stored as vector of GLfloat
	};

#endif // GAMEAPP_HPP_INCLUDED
