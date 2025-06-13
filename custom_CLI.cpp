#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

std::string truncate(const std::string& str, size_t width) {
    return (str.length() > width) ? str.substr(0, width - 3) + "..." : str;
}

void printProcess(const std::string& gpu, const std::string& gi, const std::string& ci, const std::string& pid, 
                      const std::string& type, const std::string& processName, const std::string& gpuMemUsage) 
{
    std::cout << "| "
              << std::left << std::setw(6) << gpu << " "
              << std::left  << std::setw(3) << gi  << " "
              << std::left << std::setw(6) << ci << " "
              << std::left << std::setw(12) << pid << " "
              << std::left  << std::setw(9) << type
              << std::left  << std::setw(20) << truncate(processName, 20)
              << "  "
              << std::left << std::setw(12) << gpuMemUsage
              << "  |\n";
}

int main() {

    std::time_t t = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&t)); 

    std::cout << "+-----------------------------------------------------------------------------+\n";
    std::cout << "| NVIDIA-SMI 551.86    Driver Version: 551.86    CUDA Version: 12.4           |\n";
    std::cout << "|-------------------------------+----------------------+----------------------+\n";
    std::cout << "| GPU Name        Warframe-X    |Bus-Id        Disp.A  | Volatile Uncorr. ECC |\n";
    std::cout << "| Fan Temp Perf   Pwr:Usage/Cap |         Memory-Usage | GPU-Util  Compute M. |\n";
    std::cout << "|                               |                      |               MIG M. |\n";
    std::cout << "|===============================+======================+======================|\n";
    std::cout << "|   0  Pokemon_GPUE       On    | 00000000:01:00.0 Off |                  N/A |\n";
    std::cout << "|  45%   55C    P2   70W / 150W |  4096MiB / 8192MiB   |     0%       Default |\n";
    std::cout << "|                               |                      |                  N/A |\n";
    std::cout << "+-------------------------------+----------------------+----------------------+\n";
    std::cout << "\n";
    std::cout << "+-------------------------------+----------------------+----------------------+\n";
    std::cout << "| Processes:                                                                  |\n";
    std::cout << "|  GPU   GI   CI    PID          Type     Process name          GPU Memory    |\n";
    std::cout << "|        ID   ID                                                Usage         |\n";
    std::cout << "|=============================================================================|\n";

    printProcess("0", "N/A", "N/A", "3475", "C+G", "Ultrakill.exe", "N/A");
    printProcess("0", "N/A", "N/A", "1045", "C+G", "In Stars and Time.exe", "N/A");
    printProcess("0", "N/A", "N/A", "9549", "C+G", "LimbusCompany.exe", "N/A");
    printProcess("0", "N/A", "N/A", "0999",  "C+G", "Oneshot.exe", "N/A");
    printProcess("0", "N/A", "N/A", "8888", "C+G", "LibraryOfRuinaMadeMyKoreanStudioProjectMoon.exe", "N/A");

    std::cout << "+-----------------------------------------------------------------------------+\n";
    return 0;
}
