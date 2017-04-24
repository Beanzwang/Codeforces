#include<stdio.h>
#include<string.h>

void to_char_format(char *line);
void to_RC_format(char *line);
char output[20];
int str_len;
int main() {
    int input_num, counter = 0;
    // get the numbers of input.
    scanf("%d", &input_num);
    while(counter < input_num) {
        char line[20];
        scanf("%s", line);  // read a new line
        str_len = strlen(line);
        //First character decides which numeration system should use.
        if (line[0] == 'R') {
            to_char_format(line);
            printf("%s\n", output);
        } else {
            to_RC_format(line);
            printf("%s\n", output);
        }
        counter++;
    }
    

    return 0;
}

void to_char_format(char *line) {
    // read: R23C55 -> BC23
    int col_num = 0, str_c = 0, temp = 0;
    int i_counter = 0, o_counter = 0, r_counter = 0, c_counter = 0;
    int quo = 0, rem = 0;
    char row[10], c, col[10];
    i_counter++;
    // read R23C55
    while(line[i_counter] != 'C') {
        row[r_counter++] = line[i_counter++];
    }
    row[r_counter] = '\0';
    i_counter++;
    while(line[i_counter] != '\0') {
        col_num *= 10;
        col_num += (line[i_counter++] - 48);
    }
    // convert to BC23 format. col first then row.
    // col
    while (col_num != 0) {
        rem = col_num % 26;  // 55 % 26 = 3, 2 % 3 = 3
        if (rem == 0) {
            col[c_counter++] = 'Z';   
            col_num = col_num / 26;
            col_num -= 1;
        } else {
            col[c_counter++] = rem + 64;
            col_num = col_num / 26;  // 55 / 26 = 3
        }
        

    }
    
    col[c_counter] = '\0';
    int col_len = c_counter;
    c_counter--;
    while (o_counter < col_len) {
        output[o_counter++] = col[c_counter--];
    }
    output[o_counter] = '\0';
    // row
    strcat(output, row);
}

void to_RC_format(char *line) {
    // read: BC23 -> R23C55
    int i_counter = 0, o_counter = 0, r_counter = 0, c_counter = 0, i = 0;
    int col_num = 0, quo, rem;
    char row[10], col[10], rev_col[10];
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
    while (i < c_counter) {
        rev_col[i] = col[c_counter - i - 1];
        i++;
    }
    rev_col[i] = '\0';
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
    strcat(output, rev_col);
}
