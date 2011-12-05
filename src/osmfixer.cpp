#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/program_options.hpp>
namespace po = boost::program_options;

int main(int argc, char *argv[])
{
	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help message")
		;

	po::positional_options_description p;

	po::variables_map vm;
	try {
		po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
		po::notify(vm);
	} catch ( const boost::program_options::error& e ) {
		std::cerr << e.what() << std::endl;
	}

	if (vm.count("help")) {
		std::cout << desc << "\n";
		return 1;
	}


	system("pause");
	return EXIT_SUCCESS;
}