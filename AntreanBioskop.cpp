#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 6

struct bioskop{
    char nama[20];
    char film[30];
    char kodeJam[3];
    char harga[20];
};

void jadwal(){
    puts("======================::::::::::::================================\n");
    puts("                 JADWAL FILM BIOSKOP CINEMA21\n");
    puts("            Metropolitan Mall Cileungsi, Bogor, Jawa Barat\n");
    puts("======================::::::::::::================================\n\n");
    puts("------------------------------------------------------------------\n");
    puts("|       |                |               KODE JADWAL             |\n");
    puts("|Studio |      Film      |---------------------------------------|\n");
    puts("|       |                |   01    |   02    |   03    |   04    |\n");
    puts("|   1   |  Interstellar  |  09.00  |  11.40  |  15.10  |  18.00  |\n");
    puts("|   2   |  Tokyo Drift   |  11.00  |  14.20  |  16.30  |  21.00  |\n");
    puts("|   3   |  The Conjuring |  07.00  |  12.30  |  14.40  |  17.00  |\n");
    puts("|   4   |     Boruto     |  08.30  |  11.10  |  13.30  |  16.00  |\n");
    puts("------------------------------------------------------------------\n");
    puts(" Harga Tiket :\n 1. Senin-Jumat : Rp30000\n Sabtu-Minggu : Ro50000\n");
}

int main(){
    struct bioskop data[MAX];
    int head=0, tail=0, choice, n=1, i, m, e=0;
    int menu1, menu2, menu3;
    
    menu : 
        jadwal();
        puts("======================::::::::::::================================\n");
        puts("                 PROGRAM ANTRIAN BIOSKOP\n");
        puts("            DATE NOW : Sabtu, 28 Januari 2023\n");
        puts("======================::::::::::::================================\n\n");
        puts("==> Tampilan Menu : \n\n");
        puts(" 1.Enqueue\n");
        puts(" 2.Dequeue\n");
        puts(" 3.Display\n");
        puts(" 4.Exit\n");
        printf("Inputkan pilihan menu : \n\n");
        scanf("%d",&choice);
        system("cls");
        
    switch(choice){
        case 1 : {
            if(tail==MAX){
                printf("Maaf di karenakan Pandemi, KUOTA BIOSKOP HANYA 6 PENONTON!");
            }else{
                input : 
                puts("======================::::::::::::================================\n");
                puts("               -- MENU INPUT DATA PENONTON --\n");
                puts("======================::::::::::::================================\n\n");
                fflush(stdin);
                printf("Input Nama                : ");
                gets(data[tail].nama);
                printf("Input FILM                : ");
                gets(data[tail].film);
                printf("Input Kode Jadwal (01-04) : ");
                gets(data[tail].kodeJam);
                printf("Input Nominal             : Rp");
                gets(data[tail].harga); tail++;
                printf("\n\n");
                
            }
            printf("DATA TELAH BERHASIL DI INPUT!\n"); 
            printf("Inputkan 1 untuk melanjutkan: ");
            scanf("%d",&menu1);
            fflush(stdin);
        
            if (menu1==1){
                system("cls");
                goto input;
            }else{
                system("cls");
                goto menu;
            }
        }
        
        case 2 : {
            puts("======================::::::::::::================================\n");
            puts("               -- MENU HAPUS DATA PENONTON --\n");
            puts("======================::::::::::::================================\n\n");
            puts("Apakah Anda yakin ingin menghapus tiket?\n");
            printf(" 1.YA / 2.TIDAK : ");
            scanf("%d",&menu2);
            
            if(menu2==1){
                if(tail==NULL || head==tail){
                printf("Maaf, tidak ada antrean\n");
                system("pause");
                system("cls");
                goto menu;
                }else{
                    printf("Data telah berhasil di hapus!\n");
                    e++;
                    head++;
                    system("pause");
                    system("cls");
                    goto menu;
                }
            }else if(menu2==2){
                printf("Kembali ke menu \n");
                system("pause");
                system("cls");
                goto menu;
            }else{
                printf("Pilihan yang anda input salah!");
                system("cls");
                goto menu;
            }
        }
        
        case 3 : {
            if (head==tail || head>tail){
                printf("maaf tidak ada data \n");
                system("pause");
                system("cls");
                goto menu;
            }else{
                display : 
                puts("======================::::::::::::================================\n");
                puts("               -- MENU DISPLAY DATA PENONTON --\n");
                puts("======================::::::::::::================================\n\n");
                printf("==> INPUTAN MENU (1-2) : \n\n");
                printf(" 1. Lihat semua data \n");
                printf(" 2. Kembali \n\n");
                printf("Pilihan : ");
                scanf("%d",&menu3);
                system("cls");
                
                if(menu3==1){
                    puts("======================::::::::::::================================\n");
                    puts("               -- MENU DISPLAY DATA PENONTON --\n");
                    puts("======================::::::::::::================================\n\n");
                    for(i=head;i<tail;i++){
                    	printf("Penonton ke : %d\n", i+1);
                    	printf("----------------\n");
                        printf("Nama    : %s\n", data[i].nama);
                        printf("FILM    : %s\n", data[i].film);
                        printf("Jadwal  : %s\n", data[i].kodeJam);
                        printf("Nominal : Rp%s\n\n\n", data[i].harga);
                    }
                    system("pause");
                    system("cls");
                    goto display;
                }else if(menu3==2){
                    system("cls");
                    goto menu;
                }else{
                    printf("Maaf, pilihan yang anda input tidak tersedia!\n\n");
                    system("pause");
                    system("CLS");
                    goto display;
                }
                
            }
        }
        
        case 4 : {
            printf("TERIMA KASIH TELAH DATANG!\n");
            printf("Enjoy your Movie...\n");
            system("pause");
            return 0;
        }
        
        default : {
            printf("PILIHAN MENU TIDAK TERSEDIA!\n");   
            printf("Silahkan input menu Kembali...\n"); 
            system("pause");
            system("cls");
            goto menu;
        }
        
    } 
    
 }
