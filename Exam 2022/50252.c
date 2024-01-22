#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
typedef struct WAVHeader {
    char  RIFF[4];
    int   chunkSize;
    char  wave[4];
    char  format[4];
    int   subChunkSize;
    short audioFormat;
    short numChannel;
    int   sampleRate;
    int   byteRate;
    short blockAlign;
    short bitsPerSample;
    char  data[4];
    int   dataSize;
} WAVHeader;
 
int main() {
    char f1[128], f2[128], opt[128];
    scanf("%s%s%s", f1, f2, opt);
    WAVHeader a, b;
 
    FILE *in1 = fopen(f1, "rb");
    FILE *in2 = fopen(f2, "rb");
    FILE *out = fopen(opt, "wb");
 
    fread(&a, sizeof(WAVHeader), 1, in1);
    fread(&b, sizeof(WAVHeader), 1, in2);
    fwrite(&a, sizeof(WAVHeader), 1, out);
 
    int total = a.dataSize / 2;
    uint16_t aa, bb;
 
    while(total > 0 && fread(&aa, sizeof(uint16_t), 1, in1) && fread(&bb, sizeof(uint16_t), 1, in2)) {
        uint16_t cc = aa - bb;
        fwrite(&cc, sizeof(uint16_t), 1, out);
        total--;
    }
 
    fclose(in1);
    fclose(in2);
    fclose(out);
}