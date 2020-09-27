
#include "dl.hpp"

int main()
{
    DynamicLibraryParser dynamic_library_parser("/mnt/projects/doodles/LoadDL/build/lib/libfunction.so");
    auto function = dynamic_library_parser.getFunction<int32_t(int32_t, int32_t)>("add_integers");
    int32_t res = function(3, 2);
    printf("Result: %d\n", res);
    return 0;
}