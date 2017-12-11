#include <stdio.h>
#include <math.h>
#include "header.h"


void getDataTrainning_fromFile(char* file) /// Fungsi mengambil data trainning dari file
{
    FILE *arr; double k[100][100]; int x,y;
    arr =fopen(file,"r");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t\ ");
    printf("Data Trainning \n");
    printf("\t\t\t\t\t\t\ ");
    printf("----------------------------------\n");
    printf("\t\t\t\t\t\t\ ");
    printf(" %-2s | %-4s | %-4s | %-4s | \n","No","X1","X2","Class");
    printf("\t\t\t\t\t\t\ ");
    printf("----------------------------------\n");

    for(x=1;x<=nN;x++){
        printf("\t\t\t\t\t\t\ ");
        for(y=1;y<=4;y++){
            fscanf(arr, "%lf ",&k[x][y]);
            DataTrainning[x][y]=k[x][y];

            /// Print out Data Trainning
            if(y==1 || y==4){
                      printf("%5.2lf | ",DataTrainning[x][y]);
                }else{
                     if(DataTrainning[x][y]>=10){
                         printf("%5.2lf | ",DataTrainning[x][y]);
                    }else if(DataTrainning[x][y]>=0 && DataTrainning[x][y]<=10 ) {
                         printf("%5.2lf | ",DataTrainning[x][y]);
                    }else if(DataTrainning[x][y]>=-10 && DataTrainning[x][y]<=0) {
                         printf("%5.2lf | ",DataTrainning[x][y]);
                    }else if(DataTrainning[x][y]<=-10){
                         printf("%5.2lf | ",DataTrainning[x][y]);
                    }
                }


        }printf("\n");
    }
    printf("\t\t\t\t\t\t\ ");
    printf("----------------------------------\n");
}

void getDataTesting_fromfile(char* file) /// Fungsi mengambil data testing dari file
{
    FILE *arr; double k[100][100]; int x,y;
    arr =fopen(file,"r");
    printf("\t\t\t\t\t\t\ ");printf(" Data Testing \n");
    printf("\t\t\t\t\t\t\ ");
    printf("----------------------------------\n");
        printf("\t\t\t\t\t\t\ ");
        printf(" %-2s | %-4s | %-4s | %-4s | \n","No","X1","X2","Class");
        printf("\t\t\t\t\t\t\ ");
        printf("----------------------------------\n");
        for(x=1;x<=n;x++){
        printf("\t\t\t\t\t\t\ ");
            for(y=1;y<=4;y++){
                fscanf(arr, "%lf ",&k[x][y]);
                DataTesting[x][y]=k[x][y];

                /// Print out Data Testing
                if(y==1 || y==4){
                     printf(" %-2.0lf | ",DataTesting[x][y]);
                }else{
                     if(DataTesting[x][y]>=10){
                        printf("%2.2lf | ",DataTesting[x][y]);
                    }else if(DataTesting[x][y]>=0 && DataTesting[x][y]<=10 ) {
                        printf("%2.3lf | ",DataTesting[x][y]);
                    }else if(DataTesting[x][y]>=-10 && DataTesting[x][y]<=0) {
                        printf("%2.2lf | ",DataTesting[x][y]);
                    }else if(DataTesting[x][y]<=-10){
                        printf("%2.1lf | ",DataTesting[x][y]);
                    }
                }
            }printf("\n");
    }
        printf("\t\t\t\t\t\t\ ");
        printf("----------------------------------\n");
}

void getDataTrainning() /// fungsi iterasi untuk melakukan learning pada data tranning
{
    int x,y,x2;
    printf("\n\n\n");
    for(x2=1 ; x2<=10 ; x2++){
        printf("\t\t\ ");
        printf("===============================================================================================================================================================\n");
        printf("\n\n");
        printf("\t\t\ "); printf("Data Epoch %i \n\n",x2);
        printf("\t\t\ ");
        printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\ ");printf(" %-12s | %-13s | %-13s | %-13s | %-13s | %-13s | %-13s | %-13s | %-13s | %-13s | ","W0","W1","W2","in","G(in)","G'(in)","Error","W0'","W1'","W2'"); printf("\n");
        printf("\t\t\ ");
        printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            for(x=1; x<=nN; x++){
            printf("\t\t\ ");
                for(y=1;y<=10;y++){

                    /// Proses Learning
                    switch (y){
                        case 1 :    W[x][y]=_W[x-1][8]; DataTrainningTMP[x][y]=W[x][y];break;   /// Mengambil bobot terbaru setelah di update untuk W0
                        case 2 :    W[x][y]=_W[x-1][9]; DataTrainningTMP[x][y]=W[x][y];break;   /// Mengambil bobot terbaru setelah di update untuk W1
                        case 3 :    W[x][y]=_W[x-1][10]; DataTrainningTMP[x][y]=W[x][y];break;  /// Mengambil bobot terbaru setelah di update untuk W2
                        case 4 :    DataTrainningTMP[x][y]=getIn(x);break;                      /// Mengambil nilai in atau nilai dari fungsi aktifasi
                        case 5 :    DataTrainningTMP[x][y]=getG_in(x);break;                    /// Mengambil nilai G(in)
                        case 6 :    DataTrainningTMP[x][y]=getG_Ain(x);break;                   /// Mengambil nilai G'in
                        case 7 :    DataTrainningTMP[x][y]=error(x);break;                      /// Mengambil nilai error
                        case 8 :    _W[x][y]=_W0(x); DataTrainningTMP[x][y]=_W[x][y];break;     /// Update Bobot untuk W0
                        case 9 :    _W[x][y]=_W1(x); DataTrainningTMP[x][y]=_W[x][y];break;     /// Update Bobot untuk W1
                        case 10 :   _W[x][y]=_W2(x); DataTrainningTMP[x][y]=_W[x][y];break;     /// Update Bobot untuk W2
                        default :  exit(0);
                    }

                    /// Print out Nilai Data Trainning
                    if(DataTrainningTMP[x][y]>=10){
                            printf("%10.10lf | ",DataTrainningTMP[x][y]);
                    }else if(DataTrainningTMP[x][y]>=0 && DataTrainningTMP[x][y]<=10 ) {
                            printf("%10.11lf | ",DataTrainningTMP[x][y]);
                    }else if(DataTrainningTMP[x][y]>=-10 && DataTrainningTMP[x][y]<=0) {
                            printf("%10.10lf | ",DataTrainningTMP[x][y]);
                    }else if(DataTrainningTMP[x][y]<=-10){
                            printf("%10.9lf | ",DataTrainningTMP[x][y]);
                    }

                }
                printf("\n");

            }
            printf("\t\t\ ");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    /// Mencari jumlah error dan jumlah Klass yang telah di cek dan
    int i;
    double sum = 0,sumError = 0;
        for(i=1;i<=nN;i++){
            sumError+=DataTrainningTMP[i][7];
        }

    /// Print out MSE pada data Trainning
    sumError = (sumError/nN);
    printf("\n\n\n\n");
    printf("\t\t\t\ ");printf("sum     ---> %5.16lf \n",sumError );
    printf("\t\t\t\ "); printf("MSE     ---> %5.16lf \n\n",MSE(sumError));

        /// Pengambilan Nilai Bobot update untuk melanjutkan ke iterasi selanjutnya
        _W[0][8]=_W[30][8];_W[0][9]= _W[30][9];_W[0][10]=_W[30][10] ;
    printf("\t\t\ ");

    printf("================================================================================================================================================================\n");
    }
}

void getDataTesting() /// fungsi iterasi untuk menentukan akurasi pada data Testing
{
    /// Kamus Data lokal
    int x,y,x2;
    /// Algorimta
    printf("\n");

    for(x2=0;x2<N;x2++){
        printf("\n\n \t\t Data Testing %i \n",x2+1);
        printf("\t\t\ ");
        printf("-------------------------------------------------------------------------------------------------\n");
        printf("\t\t\ ");printf(" %-12s | %-13s | %-13s | %-13s | %-13s | %-13s | ","in","G(in)","G'(in)","Error","Kelas","Cek'");printf("\n");
        printf("\t\t\ ");
        printf("-------------------------------------------------------------------------------------------------\n");
        for(x=1;x<=n;x++){
            printf("\t\t\ ");
            for(y=1;y<=6;y++){

                /// Proses mencari akurasi pada data testing
                switch (y){
                    case 1 :    DataTestingTMP[x][y]=getInDataTesting(x,x2);break;          /// Mengambil nilai dari fungsi aktivasi
                    case 2 :    DataTestingTMP[x][y]=getGn(x,x2);break;                     /// mengambil nilai dari fungsi g(in)
                    case 3 :    DataTestingTMP[x][y]=getG_n(x,x2);break;                    /// mengambil nilai dari fungsi g'(in)
                    case 4 :    DataTestingTMP[x][y]=errorDataTesting(x,x2);break;          /// mengambil nilai dari fungsi error
                    case 5 :    DataTestingTMP[x][y] = Kelas(DataTestingTMP[x][2]);break;   /// Menentukkan class klasifikasi
                    case 6 :    DataTestingTMP[x][y]= pengecekan(DataTesting[x][4],DataTestingTMP[x][5]);break;
                                /// Melakukan pencekekan terhadapat class awal dengan class klasifikasi
                    default :  exit(0);
                }

                /// Print out data Testing
                if(y==5 || y==6 ){
                    printf("%13.0lf | ",DataTestingTMP[x][y]);
                }else{
                    if(DataTestingTMP[x][y]>=10){
                        printf("%10.10lf | ",DataTestingTMP[x][y]);
                    }else if(DataTestingTMP[x][y]>=0 && DataTestingTMP[x][y]<=10 ) {
                        printf("%10.11lf | ",DataTestingTMP[x][y]);
                    }else if(DataTestingTMP[x][y]>=-10 && DataTestingTMP[x][y]<=0) {
                        printf("%10.10lf | ",DataTestingTMP[x][y]);
                    }else if(DataTestingTMP[x][y]<=-10){
                        printf("%10.9lf | ",DataTestingTMP[x][y]);
                    }
                }
            }printf("\n");
        }
    }
    printf("\t\t\ ");
    printf("-------------------------------------------------------------------------------------------------\n");
    /// Mencari jumlah error dan jumlah Klass yang telah di cek dan
    int i; double akurasi,sum = 0,sumError = 0;
        for(i=1;i<=n;i++){
            sum+=DataTestingTMP[i][6];
            sumError+=DataTestingTMP[i][4];
        }
    akurasi = (sum / n);

    /// Print out MSE dan Akurasi pada data Testing
    printf("\n\n");
    printf("\t\t\t\ "); printf("sum     ---> %1.2lf \n",sum );
    printf("\t\t\t\ "); printf("Akurasi ---> %1.15lf",akurasi);
    double Akurat = (akurasi*100);
    printf("\t\t\t\ "); printf("Akurasi ---> %1.15lf\n",Akurat);
    printf("\t\t\t\ "); printf("MSE     ---> %5.16lf \n\n",MSE(sumError/sum));
    printf("\t\t\ ");
    printf("-------------------------------------------------------------------------------------------------\n");
}

double getIn (int x) /// Fungsi aktifasi untuk data trainning
{
    /// data yang akan masuk nantinya akan terlebih dahulu masuk ke fungsi aktivasi
    return ((W[x][1])+(W[x][2]*DataTrainning[x][2])+(W[x][3]*DataTrainning[x][3]));
}
double getG_in(int x) /// Fungsi g(in) untuk data trainning
{
    return (1/(1+exp(-getIn(x))));
}

double getG_Ain(int x) /// Fungsi g'(in) untuk data trainning
{
    return (getG_in(x)*(1-getG_in(x)));
}

double error(int x)  /// Fungsi error untuk data trainning
{
    return ((DataTrainning[x][4])-getG_in(x));
}

double _W0 (int x)  /// Fungsi update bobot W0 untuk data trainning
{
    return W[x][1]+(0.1*getG_Ain(x)*error(x)*1);
}

double _W1 (int x)  /// Fungsi update bobot W1 untuk data trainning
{
    return W[x][2]+(0.1*getG_Ain(x)*error(x)*DataTrainning[x][2]);
}

double _W2 (int x)  /// Fungsi update bobot W2 untuk data trainning
{
    return W[x][3]+(0.1*getG_Ain(x)*error(x)*DataTrainning[x][3]);
}

double getInDataTesting(int x,int x2) /// Fungsi in pada data Testing
{
    /// data yang akan masuk nantinya akan terlebih dahulu masuk ke fungsi aktivasi
    return ((_W[x2][8])+(_W[x2][9]*DataTesting[x][2])+(_W[x2][10]*DataTesting[x][3]));
}

double getGn (int x,int x2) /// Fungsi g(in) pada data Testing
{
    return (1/(1+exp(-getInDataTesting(x,x2))));
}

double getG_n(int x,int x2) /// Fungsi g'(in) pada data Testing
{
    return (getGn(x,x2)*(1-getGn(x,x2)));
}

double errorDataTesting(int x,int x2) /// Fungsi errror pada data Testing
{
    return ((DataTesting[x][4])-getGn(x,x2));
}

int Kelas(double x) /// Fungsi pengelompokan Class pada data Testing
{
    if(x<=0.35){ /// Mengelompokkan class sesuai dengan kondisi classnya
        return 1;
    }else if (x >0.35 && x <=0.7){
        return 2;
    }else if (x >0.7 && x <=1 ){
        return 3;
    }
}

double MSE(double x) /// Fungsi MSE untuk Data trannning dan data Testing
{
    return pow(x,2);
}

int pengecekan(double c, double d) /// Fungsi pengecekan Class pada data Testing
{
    if(c==d){  /// mengecek Class apakah sama atau tidak jika sama maka akan me return 1 dan jika tidak maka akan me return 0
        return 1;
    }else{
        return 0;
    }
}
