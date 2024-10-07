#include <stdio.h>

void print_combination(int td, int fg, int saf, int td_plus_2pt, int td_plus_fg) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
           td_plus_2pt, td_plus_fg, td, fg, saf);
}

void findcombo(int score, int td, int fg, int saf, int td_plus_2pt, int td_plus_fg) {
    int total_score = (td * 6) + (fg * 3) + (saf * 2) + (td_plus_2pt * 8) + (td_plus_fg * 7);
    
    if (total_score == score) {
        print_combination(td, fg, saf, td_plus_2pt, td_plus_fg);
        return;
    }
    
    if (total_score > score) {
        return;
    }

    findcombo(score, td, fg + 1, saf, td_plus_2pt, td_plus_fg);
    findcombo(score, td, fg, saf + 1, td_plus_2pt, td_plus_fg);
    findcombo(score, td + 1, fg, saf, td_plus_2pt, td_plus_fg);
    findcombo(score, td, fg, saf, td_plus_2pt + 1, td_plus_fg);
    findcombo(score, td, fg, saf, td_plus_2pt, td_plus_fg + 1);
}

int main() {
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }
        if (score == 0 || score == 1) {
            printf("Program stopped.\n");
            break;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d", score);
        printf(": \n");
        findcombo(score, 0, 0, 0, 0, 0);
    }

    return 0;
}