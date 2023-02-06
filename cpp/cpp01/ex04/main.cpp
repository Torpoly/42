/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpol <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:22:30 by rpol              #+#    #+#             */
/*   Updated: 2023/02/06 18:05:45 by rpol             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/stat.h>

int is_a_directory( std::string file_name ) {
    struct stat buffer;
    int status = stat(file_name.c_str(), &buffer);
    if (status == 0 && !(buffer.st_mode & S_IFDIR))
        return (EXIT_SUCCESS);
    else
		return (std::cout << file_name << " Is a directory or does not exist! (╯°□°)╯︵ ┻━┻" << std::endl, EXIT_FAILURE);
}

int	main( int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Give me the good number of arguments ! (╯°□°)╯︵ ┻━┻" << std::endl, EXIT_FAILURE);
		
	std::string newfile = av[1];
	std::string search = av[2];
	std::string replace = av[3];
	
	if (newfile.empty() || search.empty() || replace.empty())
		return (std::cout << "Give me non null arguments ! (╯°□°)╯︵ ┻━┻" << std::endl, EXIT_FAILURE);
	if (is_a_directory(av[1]))
		return EXIT_FAILURE;
	
	
	std::ifstream ifs_file(av[1]);
	if (ifs_file.fail())
		return (std::cout << "Could not open" << av[1] << " ! (╯°□°)╯︵ ┻━┻" << std::endl, EXIT_FAILURE);
	
	newfile.append(".replace");
	std::ofstream ofs_newfile(newfile.c_str());
	if (ofs_newfile.fail())
	{
		ifs_file.close();
		return (std::cout << "Could not create" << newfile << " ! (╯°□°)╯︵ ┻━┻" << std::endl, EXIT_FAILURE);
	
	}
	
	std::string buff;
	std::string temp;
	while (std::getline(ifs_file, buff))
	{
		temp.append(buff);
		if (ifs_file.eof())
			break;
		temp.append("\n");
	}
	buff = temp;
	
	if (search != replace)
	{
		unsigned long int i = 0;
		while (1)
		{
			i = temp.find(search, i);
			if (i >= std::string::npos)
				break;
			temp.erase(i, search.size());
			temp.insert(i, replace);
			i += replace.length();
			buff = temp;
		}
	}
	
	ofs_newfile << buff;
	ofs_newfile.close();
	ifs_file.close();
	
	return EXIT_SUCCESS;
}