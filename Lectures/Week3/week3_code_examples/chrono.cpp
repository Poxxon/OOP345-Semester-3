#include <chrono>
#include <iostream>
#include <fstream>

void writeToFile(int count) {
  std::ofstream fout("Output.txt");
  for (int i = 0; i < count; ++i) {
    fout << "Hello" << std::endl;
  }
  fout.close();
}

int main() {

  int cnt = 0;
  std::ifstream fin("Output.txt");
  while (fin) {
    char x = fin.get();
    if (x == 'o')
      cnt++;
  }
  
  std::cout << "Count: " << cnt << std::endl;

  fin.clear();
  fin.seekg(0);

  std::cout << "Start of program" << std::endl;

  std::chrono::system_clock::time_point start_time;
  std::chrono::system_clock::time_point end_time;

  std::cout << "\**************" << std::endl;
  start_time = std::chrono::system_clock::now();
  writeToFile(1);
  end_time = std::chrono::system_clock::now();
  // std::chrono::system_clock::duration
  auto timetook = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
  std::cout << "Time took to write 1 Hello to file: " << timetook.count() << " nanoseconds" << std::endl;
  std::cout << "**************" << std::endl;

  std::cout << "\n**************" << std::endl;
  start_time = std::chrono::system_clock::now();
  writeToFile(100);
  end_time = std::chrono::system_clock::now();
  timetook = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
  std::cout << "Time took to write 100 Hello to file: " << timetook.count() << " nanoseconds" << std::endl;
  std::cout << "**************" << std::endl;

  std::cout << "\n**************" << std::endl;
  start_time = std::chrono::system_clock::now();
  writeToFile(10000);
  end_time = std::chrono::system_clock::now();
  timetook = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
  std::cout << "Time took to write 10000 Hello to file: " << timetook.count() << " nanoseconds" << std::endl;
  std::cout << "**************" << std::endl;

  std::cout << "End of program" << std::endl;
}
