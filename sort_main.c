#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "data_quicksort.h"
#include "data_mergesort.h"
#include "data_heapsort.h"
#include "str_quicksort.h"
#include "str_mergesort.h"
#include "str_heapsort.h"
#define QUICKSORT 1
#define MERGESORT 2
#define RADIXSORT 3
#define HEAPSORT 4
#define DATACNT 1000000
#define MaxLineLen 100

int main()
{
        FILE *File1, *File2;
        FILE *quicksort_file1, *quicksort_file2, *mergesort_file1, *mergesort_file2, *heapsort_file1, *heapsort_file2;
        int n = 0;
        int i = 0;
        char word[MaxLineLen];
        int *data = (int*)malloc(sizeof(int) * DATACNT);
        File1 = fopen("dataset1.txt", "w");
        File2 = fopen("dataset2.txt", "w");

        srand(1);
        for(i = 0; i < DATACNT; i++){
                n = rand();
                fprintf(File1, "%d\n", n);
        }

        for(i = 0; i < DATACNT; i++){
                int idx = 0;
                while(idx < MaxLineLen){
                        n = rand() % 26 + 'a';
                        word[idx] = (char) n;
                        idx++;
                }
                word[idx] = '\0';
                fprintf(File2, "%s\n", word);
        }
        fclose(File1);
        fclose(File2);

        File1 = fopen("dataset1.txt", "r");
        File2 = fopen("dataset2.txt", "r");

        i = 0;
        char line[128];
        char **str = (char**)malloc(sizeof(char*) * DATACNT);

        while(fgets(line, sizeof(line), File1) != NULL){
                line[strcspn(line, "\n")] = '\0';
                data[i] = atoi(line);
                i++;
        }

        i = 0;
        while(fgets(line, MaxLineLen + 2, File2)){
                line[strcspn(line, "\n")] = '\0';
                str[i] = strdup(line);
		i++;
        }
        fclose(File1);
        fclose(File2);

        struct timeval start;
        struct timeval end;
        unsigned long diff;

        quicksort_file1 = fopen("quicksort_data.txt", "w");
        quicksort_file2 = fopen("quicksort_str.txt", "w");
        mergesort_file1 = fopen("mergesort_data.txt", "w");
        mergesort_file2 = fopen("mergesort_str.txt", "w");
        heapsort_file1 = fopen("heapsort_data.txt", "w");
        heapsort_file2 = fopen("heapsort_str.txt", "w");

        int modeCnt = 1;
        while(modeCnt <= 4){
                int *dataSort = (int*)malloc(sizeof(int) * DATACNT);
                char **strSort = (char**) malloc(sizeof(char*) * DATACNT);
                for(i = 0; i < DATACNT; i++){
                        dataSort[i] = data[i];
			strSort[i] = strdup(str[i]);
                }

                if(modeCnt == QUICKSORT){
                        gettimeofday(&start, NULL);
                        quicksort(dataSort, 0, DATACNT - 1);
			str_quicksort(strSort, 0, DATACNT - 1);
                        gettimeofday(&end, NULL);

                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("Quick sort performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
                        for(i = 0; i < DATACNT; i++){
                                fprintf(quicksort_file1, "%d\n", dataSort[i]);
                        	fprintf(quicksort_file2, "%s\n", strSort[i]);
			}
                }
                else if(modeCnt == MERGESORT){
                        gettimeofday(&start, NULL);
                        mergesort(dataSort, 0, DATACNT - 1);
                        str_mergesort(strSort, 0, DATACNT - 1);
			gettimeofday(&end, NULL);

                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("Merge sort performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
                        for(i = 0; i < DATACNT; i++){
                                fprintf(mergesort_file1, "%d\n", dataSort[i]);
                        	fprintf(mergesort_file2, "%s\n", strSort[i]);
			}
                }
                else if(modeCnt == HEAPSORT){
                        gettimeofday(&start, NULL);
                        heapsort(dataSort, DATACNT);
                        str_heapsort(strSort, DATACNT);
			gettimeofday(&end, NULL);

                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("Heap sort performance %ld us (equal %f sec)\n", diff, diff/1000000.0);
                        for(i = 0; i < DATACNT; i++){
                                fprintf(heapsort_file1, "%d\n", dataSort[i]);
                        	fprintf(heapsort_file2, "%s\n", strSort[i]);
			}
                }
                modeCnt++;
        }

	fclose(quicksort_file1);
	fclose(quicksort_file2);
	fclose(mergesort_file1);
	fclose(mergesort_file2);
	fclose(heapsort_file1);
	fclose(heapsort_file2);
        
	return 0;
}

