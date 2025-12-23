#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./recover [forensic image]\n");
        return 1;
    }
    FILE *images = fopen(argv[1], "r");
    if (!images)
    {
        printf("File not found.\n");
        return 1;
    }
    char *filename = malloc(8 * sizeof(char));
    if (!filename)
    {
        fclose(images);
        printf("Memory allocation error\n");
        return 1;
    }
    FILE *rec = NULL;
    uint8_t buffer[512];
    int count = 0;
    while (fread(buffer, 1, 512, images))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (rec != NULL)
            {
                fclose(rec);
            }
            sprintf(filename, "%.03i.jpg", count);
            rec = fopen(filename, "w");
            count++;
        }
        if (rec != NULL)
        {
            fwrite(&buffer, 1, 512, rec);
        }
    }
    if (rec != NULL)
    {
        fclose(rec);
    }

    free(filename);
    fclose(images);
}
