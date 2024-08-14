#include <stdio.h>
#include <stdlib.h>

int sum_of_divisors(int n){

    int sum = 1;
    for(int i = 2; i <= n/2; i++){
        if (n % i == 0)
        {
            sum += i;
        }
        
    }
    return sum;
}

int main(){
    FILE *file = fopen("abudant_numbers.dat", "w");
    if(!file) {
        perror("cannot open file ");
        return 1;
    }

    for (int i = 0; i <= 300; i++){
        if (sum_of_divisors(i) > i)
        {
            fprintf(file, "%d\n", i);
        }
        
    }
    fclose(file);

    system("gnuplot -e \"set terminal png; set output 'abundant_numbers.png'; plot 'abundant_numbers.dat' with linespoints\"");

    return 0;
}
