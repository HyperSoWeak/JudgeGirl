#include <stdio.h>
#include <stdlib.h>
 
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
    WAVHeader a, b, c;
 
    FILE *in1 = fopen(f1, "rb");
    FILE *in2 = fopen(f2, "rb");
    FILE *out = fopen(opt, "wb");
 
    fread(&a, sizeof(WAVHeader), 1, in1);
    fread(&b, sizeof(WAVHeader), 1, in2);
 
    short contentA[a.dataSize];
    short contentB[b.dataSize];
 
    c = a;
    c.dataSize = a.dataSize + b.dataSize;
    c.chunkSize = c.dataSize + 36;
    fwrite(&c, sizeof(WAVHeader), 1, out);
 
    fread(&contentA, sizeof(short), a.dataSize, in1);
    fread(&contentB, sizeof(short), b.dataSize, in2);
 
    fwrite(&contentA, sizeof(short), a.dataSize/2, out);
    fwrite(&contentB, sizeof(short), b.dataSize/2, out);
 
    fclose(in1);
    fclose(in2);
    fclose(out);
}