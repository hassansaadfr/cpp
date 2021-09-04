#include <iostream>
#include <fstream>

int	check_args(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "usage: ./replace filename to_find to_replace" << std::endl;
		return (0);
	}
	if (std::string(av[1]).empty())
	{
		std::cout << "filename is empty" << std::endl;
		std::cout << "usage: ./replace filename to_find to_replace" << std::endl;
		return (0);
	}
	if (std::string(av[2]).empty())
	{
		std::cout << "to_find is empty" << std::endl;
		std::cout << "usage: ./replace filename to_find to_replace" << std::endl;
		return (0);
	}
	if (std::string(av[3]).empty())
	{
		std::cout << "to_replace is empty" << std::endl;
		std::cout << "usage: ./replace filename to_find to_replace" << std::endl;
		return (0);
	}
	return (1);
}

std::string	sed(std::string line, std::string to_find, std::string to_replace)
{
	std::string out;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line.compare(i, to_find.length(), to_find) == 0)
		{
			out += to_replace;
			i += to_find.length() - 1;
		}
		else
			out += line[i];
	}
	return out;
}

int	main(int ac, char **av)
{
	if (!check_args(ac, av))
		return 1;
	try
	{
		std::string to_find = av[2];
		std::string to_replace = av[3];
		std::ifstream ifs(av[1]);
		if (ifs.fail())
			throw std::ios::failure("Cant open file");
		std::ofstream ofs(std::string(av[1]) + ".replace");
		if (ofs.fail())
		{
			ifs.close();
			throw std::ios::failure("Cant write in new file");
		}
		std::string line;
		while (std::getline(ifs, line))
		{
			ofs << sed(line, to_find, to_replace);
			if (to_find.compare("\n") == 0)
				ofs << to_replace;
			else
				ofs << std::endl;
		}
		ifs.close();
		ofs.close();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 2;
	}
	return 0;
}
