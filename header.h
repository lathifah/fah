#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/// -+ Kamus Data Global +-

double W[100][100];
double _W[100][100];
double DataTrainning[100][100],DataTesting[100][100];
double DataTrainningTMP[100][100],DataTestingTMP[100][100];
int n,N,nN;

///  -+ Defenisi Mothod Fungi dan prosedur +-
/// Denefisi Mothod untuk data Trainning
void getDataTrainning_fromFile(char* file);
double error(int x);
double getG_Ain(int x);
double getG_in(int x);
double getIn (int x);
void getDataTrainning();
void getDataTrainning_fromFile(char* file);
double _W0 (int x);
double _W1 (int x);
double _W2 (int x);

/// Denefisi Mothod untuk data Testing
void getDataTesting();
void getDataTesting_fromfile(char* file);
int pengecekan(double c, double d);
int Kelas(double x);
double errorDataTesting(int x,int x2);
double getG_n(int x,int x2);
double getGn (int x,int x2);
double getInDataTesting(int x,int x2);

/// Denefisi Mothod untuk data Testing dan Trainning
double MSE(double x);



#endif // HEADER_H_INCLUDED
