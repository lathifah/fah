#include "body.c"

int main () /// Fungsi Utama
{
    int x,y;
    int x2,j;
    n=15;
    N=1;
    nN=30;
    /// Pendefenisin Tebakan awal pada bobot
    _W[0][8]=0.5;
    _W[0][9]= 0.1;
    _W[0][10]= 0.15;
    /// Mengambil data Trainning dari file
    getDataTrainning_fromFile("TrainingData.txt");
    system("pause");
    /// Proses Learning untuk data trainning
    getDataTrainning();
    system("pause");
    /// Mengambil data Testing dari file
    getDataTesting_fromfile("TestingData.txt");
    system("pause");
    /// Proses akurasi data untuk data Testing
    getDataTesting();
    system("pause");
}
