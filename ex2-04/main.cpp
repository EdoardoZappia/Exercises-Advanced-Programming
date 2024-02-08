#include "lib/datasource.hpp"
#include "lib/datatransformer.hpp"
#include "lib/filedatasource.hpp"
#include "lib/consoledatasource.hpp"
#include "lib/logtransformer.hpp"
#include "lib/linearscaler.hpp"
#include "lib/standardscaler.hpp"



int main() {
  DataSource *data;

  std::string input_type;
  std::cout << "Select input format (File | Console): ";
  std::cin >> input_type;

  if (input_type == "File") {
    const std::string filename = "/Users/edoardozappia/Documents/adv_allenam/ex2-04/data.txt";
    data = new FileDataSource(filename);
  } else if (input_type == "Console") {
    data = new ConsoleDataSource();
  } else {
    std::cerr << "Error: Invalid source type." << std::endl;
    return 1;
  }

  data->display_info();
  data->read_data();

  std::cout << std::endl << "Original data: " << std::endl;
  std::cout << data << std::endl;
  std::cout << std::endl;

  // Define polymorphic transformer.
  DataTransformer *transformer;

  std::string transformation_type;
  std::cout << "Select transformation to apply (Linear | Log | Standard): ";

std::cin >> transformation_type;

if (transformation_type == "Linear") {
    transformer = new LinearScaler(data, 0.5);
} else if (transformation_type == "Log") {
    transformer = new LogTransformer(data);
} else if (transformation_type == "Standard") {
    transformer = new StandardScaler(data);
} else {
    std::cerr << "Error: Invalid transformation type." << std::endl;
    return 1;
}

transformer->transform();
std::cout << std::endl << "Transformed data: " << std::endl;
  std::cout << data << std::endl << std::endl;

  delete transformer;
  delete data;

  return 0;
}
