#include<stdio.h>

void to_char_format(char *line);
void to_RC_format(char *line);
int main() {
    int lines, counter = 0;
    // get the numbers of input.
    scanf("%d", &lines);
    while(counter < lines) {
        char line[20];
        scanf("%s", line);
        //First character decides which numeration system should use.
        if (line[0] == 'R') {
            to_char_format(line);
        } else {
            to_RC_format(line);
        }
        counter++;
    }
    

    return 0;
}

void to_char_format(char *line) {

}

void to_RC_format(char *line) {
    char output[20];
    output[0] = 'R';
    
    printf("%s", output);
}
