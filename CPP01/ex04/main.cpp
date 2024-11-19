#include <iostream>
#include <string>
#include <fstream>

bool	read_and_replace(char **argv){
	std::string	line;
	std::string	filename = argv[1];
	std::string	to_replace = argv[2];
	std::string	replace_with = argv[3];

	if (filename.empty() || to_replace.empty() || replace_with.empty()){
		std::cout << "Error: Empty string" << std::endl;
		return (0);
	}

	std::ifstream ini_file(filename.c_str());
	std::ofstream out_file((filename + ".replace").c_str());

	if (ini_file && out_file){
		while(getline(ini_file, line)){
			size_t	pos = 0;
			while ((pos = line.find(to_replace, pos)) != std::string::npos){
				line = line.substr(0, pos) + replace_with + line.substr(pos + replace_with.length());
				pos += replace_with.length();
			}
			out_file << line << "\n";
		}
		ini_file.close();
		out_file.close();
	}
	else{
		std::cout << "Error: Cannot read file" << std::endl;
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Usage: [filename] [stringToReplace] [stringToReplaceWith]" << std::endl;
		return (1);
	}

	if (read_and_replace(argv) == 0){
		return (1);
	}

	return (0);
}
