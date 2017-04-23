#include<stdio.h>
#include<string.h>

int main() {
    char line[20], output[20];
    int str_len;
    scanf("%s", line);
    str_len = strlen(line);
    // read: BC23 -> R23C55
    int i_counter = 0, o_counter = 0, r_counter = 0, c_counter = 0;
    int col_num = 0, quo, rem;
    char row[10], col[10];
    while(!(line[i_counter] >= 48 && line[i_counter] <= 57)) {
        col_num *= 26;
        col_num += line[i_counter++] - 64;
    }
    
    quo = col_num;
    while(quo != 0) {
        rem = quo % 10;  // 55 % 10 = 5, 5 % 5 = 5
        col[c_counter++] = rem + 48;
        quo = quo / 10;  // 55 / 10 = 5
    }
    col[c_counter] = '\0';
    // row
    while (i_counter < str_len) {
        row[r_counter++] = line[i_counter++];
    }
    row[r_counter] = '\0';
    output[o_counter++] = 'R';
    output[o_counter] = '\0';
    strcat(output, row);
    // col
    strcat(output, "C");
    strcat(output, col);
    printf("%s\n", output);
    
    return 0;
}

// void temp() {
//     // read: R23C55 -> BC23
//     int col_num = 0, str_c = 0, temp = 0;
//     int i_counter = 0, o_counter = 0, r_counter = 0, c_counter = 0;
//     int quo = 0, rem = 0;
//     char row[10], c, col[10];
//     i_counter++;
//     // read R23C55
//     while(line[i_counter] != 'C') {
//         row[r_counter++] = line[i_counter++];
//     }
//     row[r_counter] = '\0';
//     i_counter++;
//     while(line[i_counter] != '\0') {
//         col_num *= 10;
//         col_num += (line[i_counter++] - 48);
//     }
//     // convert to BC23 format. col first then row.
//     // col
//     while (col_num != 0) {
//         rem = col_num % 26;  // 55 % 26 = 3, 2 % 3 = 3
//         if (rem != 0) {
//             col[c_counter++] = rem + 64;
//         } else {
//             // rem = 0 -> 'Z'
//             col[c_counter++] = 'Z';
//         }
//         col_num = col_num / 26;  // 55 / 26 = 2
//     }
//     col[c_counter] = '\0';
//     int col_len = c_counter;
//     c_counter--;
//     while (o_counter < col_len) {
//         output[o_counter++] = col[c_counter--];
//     }
//     output[o_counter] = '\0';
//     // row
//     strcat(output, row);
//     printf("%s\n", output);
// }