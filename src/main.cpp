// GL, SFML, GLM
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SFML/Window.hpp>

// STL
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

// PROJECT
#include "../include/GameAppClass.hpp"
#include "../include/GameAppImplementation.hpp"
#include "../include/obj_loader.hpp"

// Entry point of application
int
main()
	{
		// Create some vectors for storing 3D data
		std::vector<glm::vec4> obj_verts;
		std::vector<GLushort>  obj_elems;
		std::vector<glm::vec3> obj_norms;

		// Populate the above vectors with 3D data
		load_obj("../res/suzanne.obj", obj_verts, obj_norms, obj_elems);

		// Create a 1D vector for storing ordered vertex data for each GL_TRIANGLE ( 1 triangle = 3vertices = 3 * 3 GLfloats )
		std::vector<GLfloat> ordered_verts;
		ordered_verts.resize(obj_elems.size() * 3, GLfloat(0.0));

		// Simultaneously read vertex data by elements (faces) and store it in the above vector. Note: the above vector, once populated, will contain
		for(unsigned int i = 0; i < obj_elems.size() / 3; i++)
			{
				for(unsigned int j = i * 3; j < (i * 3) + 3; j++)
					{
						int k = (j * 3);

						ordered_verts[ k + 0] = obj_verts[ (obj_elems[ j ]) ].x;

						ordered_verts[ k + 1] = obj_verts[ (obj_elems[ j ]) ].y;

						ordered_verts[ k + 2] = obj_verts[ (obj_elems[ j ]) ].z;
					}
			}

		std::cout << ordered_verts.size() << " ordered_verts\n";

		GameApp game("obj_loader", 640, 480);

		// Pass vertex data to game app
		for(unsigned int i = 0; i < ordered_verts.size(); i++)
			{
				game.V_pop(ordered_verts[i]);
			}

		game.Init();

		game.Run();

		return 0;
	}

