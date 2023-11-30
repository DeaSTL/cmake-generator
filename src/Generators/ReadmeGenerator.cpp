#include "Frate/Utils/General.hpp"
#include <Frate/Generators.hpp>
#include <Frate/Constants.hpp>
namespace Generators::Readme {
    bool create(std::shared_ptr<Command::Project> pro){
      std::string readme = R"(
# {project_name} with {name}
- {description}
- {author}
- {date}

## Getting started

### Adding dependencies
To add dependencies to your project, you can use the following command:
```bash
frate add p <package_name>
```
This will add the package to the project and will automatically add it to the CMakeLists.txt file.

### Building the project
To build the project, you can use the following command:
```bash
frate build
```
This will build the project and will create the executable in the build directory.

### Running the project
To run the project, you can use the following command:
```bash
frate run
```
This will run the project and will create the executable in the build directory.

Find more information at the [Frate Github]({help_url})

)";

      Utils::replaceKey(readme, "{project_name}", pro->project_name + Constants::VERSION);
      Utils::replaceKey(readme, "{name}", Constants::NAME);
      Utils::replaceKey(readme, "{description}", pro->project_description);
      Utils::replaceKey(readme, "{author}", pro->authors.size() > 0 ? pro->authors[0] : "");

      std::time_t t = std::time(nullptr);
      std::tm tm = *std::localtime(&t);
      std::stringstream ss;
      ss << std::put_time(&tm, "%d/%m/%Y");
      Utils::replaceKey(readme, "{date}", ss.str());
      Utils::replaceKey(readme, "{help_url}", Constants::PROJECT_URL);
      std::ofstream readme_file(pro->project_path / "README.md");

      try{
        readme_file << readme;
      }catch(...){
        std::cout << "Failed to create README.md file" << std::endl;
        return false;
      }
      return true;
    }
}
