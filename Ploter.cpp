#include "Ploter.h"

namespace ohd {
void Ploter::plotWithPlt(std::vector<int>& win_bureau_count, int n, int player_num)
{
  size_t bureau_num = win_bureau_count.size();

  std::ofstream data_file;
  data_file.open("win_bureau_count.dat");
  if (data_file.is_open()) {
    for (size_t i = 1; i < bureau_num; i++) {
      data_file << i << " " << (win_bureau_count[i] / 1.0 / n * 100) << "%" << std::endl;
    }
    data_file.close();
  }

  std::ofstream plt_file;
  plt_file.open("win_bureau_count.plt");
  if (plt_file.is_open()) {
    plt_file << "set terminal pdfcairo" << std::endl;
    plt_file << "set output 'win_bureau_count.pdf'" << std::endl;
    plt_file << "set key off" << std::endl;
    plt_file << "set style data lines" << std::endl;
    plt_file << "set title 'BureauNum " << n << " PlayerNum " << player_num << " ' " << std::endl;
    plt_file << "set xlabel 'num'" << std::endl;
    plt_file << "set ylabel 'pencent(%)'" << std::endl;
    plt_file << "set xrange [ * : * ]" << std::endl;
    plt_file << "set yrange [ * : * ]" << std::endl;
    plt_file << "plot 'win_bureau_count.dat' u 1:2";
    plt_file.close();
  }
  system("gnuplot-x11 win_bureau_count.plt");
}
}  // namespace ohd
