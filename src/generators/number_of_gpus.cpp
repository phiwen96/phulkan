#include "number_of_gpus.hpp"



int main (int argc, const char * argv[])
{
      file <write> f ("gpus_info.hpp");
      f << "#pragma once\n#define number_of_gpus = 0";
      
	return 0;
}
