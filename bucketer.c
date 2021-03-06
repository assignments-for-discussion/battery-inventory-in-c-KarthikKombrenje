#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  counts.lowCount=0;
  counts.mediumCount=0;
  counts.highCount=0;
  
  for(int i=0;i<6;i++)
  {
      if(cycles[i]<400)
      {
          counts.lowCount++;
      }
       else if(cycles[i]<=919)
      {
          counts.mediumCount++;
      }
      else 
      {
          counts.highCount++;
      }
  }
       printf("%d\n",counts.lowCount);
       printf("%d\n",counts.mediumCount);
       printf("%d\n",counts.highCount);
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
    assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
