#include <CMD/CMD_Args.h>
#include <GU/GU_Detail.h>
#include <UT/UT_Exit.h>

static float DensityFunction(const UT_Vector3 &P, [[maybe_unused]] void *data) {
    return 1.0f - P.length();
}

int main(int argc, char *argv[]) {
    CMD_Args args;
    args.initialize(argc, argv);

    GU_Detail gdp;

    printf("Hello, HDK!\n");

    UT_BoundingBoxF bounds(-1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f);
    gdp.polyIsoSurface(DensityFunction, nullptr, bounds, 8, 8, 8);

    if (!gdp.save("D:\\sample.obj", nullptr).success()) {
        fprintf(stderr, "Failed to save sample.obj\n");
    } else {
        printf("sample.obj saved!");
    }

    UT_Exit::exit(UT_Exit::EXIT_OK);
}
