/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 - structure and dynamic arrays
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : Angelika Nainggolan (13224085)
 *   Nama File           : modul3.c
 *   Deskripsi           : Kondisi/Aturan 
1. Setiap meteorit memiliki:  
• nama string tanpa spasi  
• massa integer  
• murni integer  
2. Urutan ranking:  
• murni lebih tinggi lebih baik  
• jika sama, massa lebih kecil lebih baik  
• jika sama, nama alfabetis lebih kecil lebih baik  
3. Cetak maksimal 3 data teratas  
4. Jika N < 3, cetak semua 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct soalmeteor {
    char nama[200];
    int massa;
    int murni;
};
int main()
{
    int N;
    scanf("%d", &N);
    struct soalmeteor* meteor
        = (struct soalmeteor*)malloc(N * sizeof(*meteor));

    for (int i = 0; i < N; i++){
       scanf("%s %d %d", meteor[i].nama, &meteor[i].massa, &meteor[i].murni); 
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (meteor[j].murni < meteor[j + 1].murni ||
                (meteor[j].murni == meteor[j + 1].murni &&
                 meteor[j].massa > meteor[j + 1].massa) ||
                (meteor[j].murni == meteor[j + 1].murni &&
                 meteor[j].massa == meteor[j + 1].massa &&
                 strcmp(meteor[j].nama, meteor[j + 1].nama) > 0)) {
                struct soalmeteor temp = meteor[j];
                meteor[j] = meteor[j + 1];
                meteor[j + 1] = temp;
            } else{
                struct soalmeteor temp = meteor[j];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%s %d %d\n",
               meteor[i].nama, meteor[i].massa, meteor[i].murni);
        }

    free(meteor);
    return 0;
}
//referensi https://www.geeksforgeeks.org/c/how-to-create-dynamic-array-of-structs-in-c/
//referensi https://www.geeksforgeeks.org/c/dynamic-array-in-c/
//referensi https://www.geeksforgeeks.org/c/structures-c/
//referensi https://www.geeksforgeeks.org/c/how-to-dynamically-create-array-of-structs-in-c/
//referensi https://www.w3schools.com/c/ref_string_strcmp.php
