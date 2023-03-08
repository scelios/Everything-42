/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beaudibe <beaudibe@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:00:34 by beaudibe          #+#    #+#             */
/*   Updated: 2023/03/08 15:24:37 by beaudibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <str_to_find> <str_change>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string str_to_find = argv[2];
    std::string str_change = argv[3];

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return 1;
    }
    if (str_to_find.empty()) {
        std::cerr << "Error: empty string" << std::endl;
        return 1;
    }
    std::string line;
    std::string replaced_text;
    while (std::getline(infile, line)) {
        size_t pos = 0;
        while ((pos = line.find(str_to_find, pos)) != std::string::npos) {
            replaced_text += line.substr(0, pos) + str_change;
            pos += str_to_find.length();
            line = line.substr(pos, std::string::npos);
            pos = 0;
        }
        replaced_text += line + '\n';
    }
    std::ofstream outfile(filename + ".replace");
    if (!outfile) {
        std::cerr << "Error: could not create output file " << filename << ".replace" << std::endl;
        return 1;
    }

    outfile << replaced_text;
    std::cout << "File " << filename << " has been replaced, output saved in " << filename << ".replace" << std::endl;

    return 0;
}
