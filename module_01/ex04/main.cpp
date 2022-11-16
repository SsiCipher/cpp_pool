#include <iostream>
#include <fstream>
#include <string.h>

void    replace_str(std::string &line, std::string s1, std::string s2)
{
	size_t  pos;

	pos = line.find(s1);
	while (pos != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos = line.find(s1, pos + s2.length());
	}
}

bool    is_empty(std::string arg)
{
	return (arg.empty());
}

int main(int argc, char *argv[])
{
	std::string		line;
	std::string		outfileName;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4 || is_empty(argv[2]) || is_empty(argv[3]))
	{
		std::cout << "USAGE: ./sed <filename> <old_string> <new_string>\n";
		return (1);
	}
	else
	{
		infile.open(argv[1]);
		if (!infile.is_open())
		{
			std::cout << "ERROR: Failed to open file: " << argv[1] << "\n";
			return (1);
		}
		else
		{
			outfileName.append(argv[1]);
			outfileName.append(".replace");
			outfile.open(outfileName.c_str());
			if (!outfile.is_open())
			{
				std::cout << "ERROR: Failed to open file: " << outfileName << "\n";
				return (1);
			}
			else
			{
				while (getline(infile, line))
				{
					replace_str(line, argv[2], argv[3]);
					outfile << line << std::endl;
				}
				infile.close();
				outfile.close();
			}
		}
	}
	return (0);
}
