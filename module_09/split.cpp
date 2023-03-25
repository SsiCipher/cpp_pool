#include <iostream>
#include <vector>

std::vector<std::string> split_str(std::string str, char sep)
{
	std::vector<std::string>	result;
    size_t  					start = 0, sep_pos = -1;
    
    while ((sep_pos = str.find(sep, start)))
    {
        std::cout << start << " - " << sep_pos << std::endl;
		result.push_back(str.substr(start, sep_pos));
        start = sep_pos + 1;
        if (sep_pos == std::string::npos)
			break;
    }
	return (result);
}

int main() {
    std::vector<std::string> res = split_str("Hello world Happy", ' ');

	for (int i = 0; i < res.size(); i++)
		std::cout << res[i] << std::endl;

    return (0);
}
