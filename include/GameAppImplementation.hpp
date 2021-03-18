/*
    GameApp Implementation
*/

//Constructor
GameApp::GameApp(const std::string title, const int width, const int height)
    : m_window(sf::VideoMode(width, height), title)
	{
		//Init();
	}

void
GameApp::Init()
	{
		m_window.setPosition(sf::Vector2i(200, 100));

		// Make it the active window for OpenGL calls
		m_window.setActive();

		// Set the background colour
		glClearColor(0.01f, 0.35f, 0.05f, 1.f);

		// Configure the viewport (the same size as the window)
		glViewport(0, 0, m_window.getSize().x, m_window.getSize().y);

		// Enable depth test
		glEnable(GL_DEPTH_TEST);

		// Accept fragment only if it closer to the camera than the former ones
		glDepthFunc(GL_LESS);

		// Enable client-side vertex and colour capabilities
		glEnableClientState(GL_VERTEX_ARRAY);
		//glEnableClientState(GL_COLOR_ARRAY);

		// Tell GL how to point to vertex data and colour data stored within a vector
		glVertexPointer(3, GL_FLOAT, 0, &v_dat[0]);
		//glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), &vec[0] + 3);
	}

void
GameApp::Run()
	{
		while(m_window.isOpen())
			{
				sf::Event e;
				while(m_window.pollEvent(e))
					{
					    switch(e.type)
							{
								// Close window: exit
								case sf::Event::Closed:
									m_window.close();
									break;
								// Escape key: exit
								case sf::Event::KeyPressed:
									if(e.key.code == sf::Keyboard::Escape)
										{
											m_window.close();
										}
									break;
								// Resize event: adjust the viewport
								case sf::Event::Resized:
									glViewport(0, 0, e.size.width, e.size.height);
									break;
								// Mastercard (everything else)
								default:
									break;
							}
					}	
				Render();
			}
		exit(0);
	}

void
GameApp::Render()
	{
		// Clear the color and depth buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw the first triangle
		glDrawArrays(GL_TRIANGLES, 0, v_dat.size() / 3);

		// Finally, display the rendered frame on screen
		m_window.display();
	}

void
GameApp::V_pop(GLfloat x)
	{
		v_dat.push_back(x);
	}

