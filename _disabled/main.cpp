#include <boost/filesystem.hpp>
#include <zipper/unzipper.h>
#include <headers/keynote.h>
#include "src/key_to_svg/svg_wrapper.h"
#define NANOSVG_IMPLEMENTATION	// Expands implementation

using namespace boost::filesystem;

int generate_svg(std::string filePath);

inline bool file_exists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

inline bool ends_with(const std::string &path, const std::string& ending) {
        return path.size() >= ending.size() &&
                path.compare(path.size() - ending.size(), ending.size(), ending) == 0;
}

int main(int argc,char* argv[]) {
    if(argc == 2) {
        path canonicalPath = canonical(argv[1]);
        generate_svg(canonicalPath.generic_string());
    } else {
        std::cout << "Wrong formatting of command line arguments" << std::endl;
        std::cout << "This tool expects the path of a keynote file as command line argument" << std::endl;
    }
}

int generate_svg(std::string filePath) {

    svg_wrapper svg;
    zipper::Unzipper* currentZip;

    // check if contains index.zip, otherwise extract the .key file as it will be newer format.
    if (file_exists(filePath + "/Index.zip")) {
        currentZip = new zipper::Unzipper(filePath + "/Index.zip");

    } else {
        currentZip = new zipper::Unzipper(filePath);
    }

    std::vector<zipper::ZipEntry> entries = currentZip->entries();

    // erase all entries which are not ".iwa" files.
    entries.erase(
            std::remove_if(entries.begin(),
                           entries.end(),
                           [](const zipper::ZipEntry& entry){
                               return !ends_with(entry.name, ".iwa");
                           }),
            entries.end());


    std::vector<keynoteIWAFile> entriesInMemory(entries.size());
    std::transform(entries.begin(), entries.end(), entriesInMemory.begin(), [&](auto const &x) {
                       keynoteIWAFile entry;
                       entry.name = x.name;
                       currentZip->extractEntryToMemory(x.name, entry.contents);
                       return entry;
                   }
    );

    currentZip->close();
    delete currentZip;


    auto output_file = "output.svg";
    std::ofstream outFile;
    outFile.open(output_file);
    outFile << generateSVGFromKeynoteIWAFiles(entriesInMemory);
    outFile.close();
    return 0;
}
