/*
    Function used for loading Wavefront OBJ file data (vertices, elements, and normals) into a program
*/
void
load_obj(const char* filename, std::vector<glm::vec4> &vertices, std::vector<glm::vec3> &normals, std::vector<GLushort> &elements)
	{
		std::ifstream in(filename, std::ios::in);
		if (!in)
			{
				std::cerr << "Cannot open " << filename << std::endl; exit(1);
			}

		int vi {0}, fi {0};

		std::string line;
		while (getline(in, line))
			{
				if (line.substr(0,2) == "v ")
					{
						std::istringstream s(line.substr(2));
						glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
						vertices.push_back(v);
						vi+=4;
					}
				else if (line.substr(0,2) == "f ")
					{
						std::istringstream s(line.substr(2));
						GLushort a,b,c;
						s >> a; s >> b; s >> c;
						a--; b--; c--;
					   elements.push_back(a); elements.push_back(b); elements.push_back(c);
					   fi+=3;

					}
				else if (line[0] == '#')
					{
						/* ignoring this line */
					}
				else
					{
						/* ignoring this line */
					}
			}

	   std::cout << vi << " verts\n";
	   std::cout << fi << " elems\n";

		normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));

		for (unsigned int i = 0; i < elements.size(); i+=3)
			{
				GLushort ia = elements[i];
				GLushort ib = elements[i+1];
				GLushort ic = elements[i+2];

				glm::vec3 normal = glm::normalize(glm::cross(
				glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
				glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));

				normals[ia] = normals[ib] = normals[ic] = normal;
			}
	}

