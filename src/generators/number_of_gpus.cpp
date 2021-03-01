#include "number_of_gpus.hpp"



int main (int argc, const char * argv[])
{
//      file <write> f2 (argv [0]);
//      f2 << "snopp";
      
      file <write> f ("gpus_info.hpp");
//      file <write> f (argv [0]);
      f << "#pragma once\n#define number_of_gpus 0\n";
      f << "#define number_of_gpus2 0";
      
      
	return 0;
}
