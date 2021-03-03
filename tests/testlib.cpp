#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
// #include <catch2/catch_test_macros.hpp>
#include <phulkan/phulkan.hpp>
using namespace std;
// #include <catch2/internal/catch_default_main.hpp>

// int main(int args, char** argc){return 0;}
consteval int kiss (){return 0;}

TEST_CASE( "Quick check", "[kiss]" ) {
      cout << GPU_0_MAX_IMAGE_DIMENSION_1D << endl;
      cout << gpu<0>::max_image_dimension_1D << endl;
      cout << kuk << endl;
//     std::vector<double> values {1, 2., 3.};
//     auto [mean, moment] = accumulate_vector(values);
	std::cout << "hi" << std::endl;
    REQUIRE( kiss () == 0 );
//     REQUIRE( moment == Approx(4.666666) );
}
