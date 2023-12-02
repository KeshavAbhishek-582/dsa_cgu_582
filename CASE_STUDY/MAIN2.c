#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a real estate property
struct Property
{
    char name[50];
    int bedrooms;
    double area;
    double price;
    struct Property *next;
};

// Initialize a linked list
struct Property *head = NULL;

// Function to insert a new property into the linked list
void insertProperty(const char name[], int bedrooms, double area, double price)
{
    struct Property *newProperty = (struct Property *)malloc(sizeof(struct Property));

    // Check if memory allocation was successful
    if (newProperty == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    strcpy(newProperty->name, name);
    newProperty->bedrooms = bedrooms;
    newProperty->area = area;
    newProperty->price = price;
    newProperty->next = NULL;

    if (head == NULL)
    {
        head = newProperty;
    }
    else
    {
        struct Property *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newProperty;
    }
}

// Function to predict the price of a property based on features
double predictPrice(int bedrooms, double area)
{
    struct Property *current = head;
    double predictedPrice = 0.0;
    int count = 0;

    while (current != NULL)
    {
        if (current->bedrooms == bedrooms && (current->area >= area-100 && current->area <= area+100))
        {
            predictedPrice += current->price;
            count++;
        }
        current = current->next;
    }

    if (count == 0)
    {
        printf("No matching properties found.\n");
        return -1;
    }
    else
    {
        return predictedPrice / count;
    }
}

int main()
{
    insertProperty("Property 1", 5, 2416.0, 181773.0);
    insertProperty("Property 2", 2, 1967.0, 195759.0);
    insertProperty("Property 3", 5, 1687.0, 246130.0);
    insertProperty("Property 4", 1, 2219.0, 190179.0);
    insertProperty("Property 5", 4, 3699.0, 203319.0);
    insertProperty("Property 6", 1, 1902.0, 189521.0);
    insertProperty("Property 7", 5, 4419.0, 194890.0);
    insertProperty("Property 8", 5, 3440.0, 202183.0);
    insertProperty("Property 9", 3, 4351.0, 213131.0);
    insertProperty("Property 10", 1, 3726.0, 215113.0);
    insertProperty("Property 11", 4, 2021.0, 215152.0);
    insertProperty("Property 12", 1, 3539.0, 225136.0);
    insertProperty("Property 13", 4, 1250.0, 245665.0);
    insertProperty("Property 14", 4, 3686.0, 221981.0);
    insertProperty("Property 15", 2, 1618.0, 222212.0);
    insertProperty("Property 16", 3, 2328.0, 218713.0);
    insertProperty("Property 17", 5, 1019.0, 211822.0);
    insertProperty("Property 18", 1, 3690.0, 238561.0);
    insertProperty("Property 19", 3, 1185.0, 222498.0);
    insertProperty("Property 20", 5, 1770.0, 210875.0);
    insertProperty("Property 21", 2, 3683.0, 231927.0);
    insertProperty("Property 22", 3, 1065.0, 238465.0);
    insertProperty("Property 23", 1, 3505.0, 185347.0);
    insertProperty("Property 24", 3, 2309.0, 198096.0);
    insertProperty("Property 25", 1, 1556.0, 185823.0);
    insertProperty("Property 26", 1, 4731.0, 222001.0);
    insertProperty("Property 27", 4, 1129.0, 233628.0);
    insertProperty("Property 28", 2, 1188.0, 239413.0);
    insertProperty("Property 29", 1, 1615.0, 238509.0);
    insertProperty("Property 30", 4, 1808.0, 237718.0);
    insertProperty("Property 31", 4, 3174.0, 244007.0);
    insertProperty("Property 32", 2, 1812.0, 236671.0);
    insertProperty("Property 33", 3, 3150.0, 244824.0);
    insertProperty("Property 34", 3, 4330.0, 193886.0);
    insertProperty("Property 35", 2, 1380.0, 248909.0);
    insertProperty("Property 36", 1, 1062.0, 216942.0);
    insertProperty("Property 37", 2, 3357.0, 186542.0);
    insertProperty("Property 38", 1, 4091.0, 196905.0);
    insertProperty("Property 39", 1, 3991.0, 189686.0);
    insertProperty("Property 40", 4, 3007.0, 248113.0);
    insertProperty("Property 41", 5, 1391.0, 218703.0);
    insertProperty("Property 42", 3, 1322.0, 196982.0);
    insertProperty("Property 43", 3, 2820.0, 222506.0);
    insertProperty("Property 44", 4, 4957.0, 194865.0);
    insertProperty("Property 45", 5, 4924.0, 206414.0);
    insertProperty("Property 46", 3, 1200.0, 247884.0);
    insertProperty("Property 47", 1, 3631.0, 196402.0);
    insertProperty("Property 48", 5, 4459.0, 242560.0);
    insertProperty("Property 49", 1, 4416.0, 239896.0);
    insertProperty("Property 50", 5, 1475.0, 182416.0);
    insertProperty("Property 51", 2, 1086.0, 189334.0);
    insertProperty("Property 52", 5, 2517.0, 233970.0);
    insertProperty("Property 53", 1, 4011.0, 185277.0);
    insertProperty("Property 54", 2, 2955.0, 224951.0);
    insertProperty("Property 55", 1, 1618.0, 241725.0);
    insertProperty("Property 56", 4, 4404.0, 183394.0);
    insertProperty("Property 57", 3, 4258.0, 234507.0);
    insertProperty("Property 58", 5, 1564.0, 207421.0);
    insertProperty("Property 59", 2, 1353.0, 210364.0);
    insertProperty("Property 60", 4, 4093.0, 221827.0);
    insertProperty("Property 61", 1, 4787.0, 208505.0);
    insertProperty("Property 62", 2, 2848.0, 233583.0);
    insertProperty("Property 63", 5, 1636.0, 247383.0);
    insertProperty("Property 64", 5, 1491.0, 195821.0);
    insertProperty("Property 65", 1, 1828.0, 190703.0);
    insertProperty("Property 66", 3, 1496.0, 215662.0);
    insertProperty("Property 67", 5, 4022.0, 233626.0);
    insertProperty("Property 68", 3, 2606.0, 218886.0);
    insertProperty("Property 69", 2, 2058.0, 244685.0);
    insertProperty("Property 70", 1, 4148.0, 241257.0);
    insertProperty("Property 71", 1, 1868.0, 212166.0);
    insertProperty("Property 72", 1, 1392.0, 202724.0);
    insertProperty("Property 73", 3, 1090.0, 218048.0);
    insertProperty("Property 74", 4, 3958.0, 219643.0);
    insertProperty("Property 75", 4, 3847.0, 218177.0);
    insertProperty("Property 76", 3, 4719.0, 235296.0);
    insertProperty("Property 77", 5, 3763.0, 198620.0);
    insertProperty("Property 78", 3, 4402.0, 193030.0);
    insertProperty("Property 79", 2, 3983.0, 202393.0);
    insertProperty("Property 80", 3, 2871.0, 203428.0);
    insertProperty("Property 81", 4, 3366.0, 197263.0);
    insertProperty("Property 82", 1, 1844.0, 235037.0);
    insertProperty("Property 83", 2, 2617.0, 242813.0);
    insertProperty("Property 84", 2, 3383.0, 201300.0);
    insertProperty("Property 85", 4, 4409.0, 209125.0);
    insertProperty("Property 86", 1, 1910.0, 222300.0);
    insertProperty("Property 87", 4, 3649.0, 190883.0);
    insertProperty("Property 88", 1, 2444.0, 218126.0);
    insertProperty("Property 89", 4, 2856.0, 196823.0);
    insertProperty("Property 90", 4, 4152.0, 244812.0);
    insertProperty("Property 91", 4, 4066.0, 232446.0);
    insertProperty("Property 92", 1, 4117.0, 205163.0);
    insertProperty("Property 93", 5, 2115.0, 205140.0);
    insertProperty("Property 94", 1, 3330.0, 238266.0);
    insertProperty("Property 95", 5, 3305.0, 196395.0);
    insertProperty("Property 96", 3, 2882.0, 182216.0);
    insertProperty("Property 97", 3, 4917.0, 213057.0);
    insertProperty("Property 98", 4, 3322.0, 196311.0);
    insertProperty("Property 99", 4, 1403.0, 211297.0);
    insertProperty("Property 100", 5, 1998.0, 193288.0);
    insertProperty("Property 101", 1, 2673.0, 191801.0);
    insertProperty("Property 102", 1, 4016.0, 197547.0);
    insertProperty("Property 103", 3, 4196.0, 239369.0);
    insertProperty("Property 104", 3, 1935.0, 189847.0);
    insertProperty("Property 105", 2, 4594.0, 236029.0);
    insertProperty("Property 106", 4, 2909.0, 223069.0);
    insertProperty("Property 107", 4, 1970.0, 215609.0);
    insertProperty("Property 108", 2, 4861.0, 212710.0);
    insertProperty("Property 109", 1, 1705.0, 209022.0);
    insertProperty("Property 110", 4, 1803.0, 236686.0);
    insertProperty("Property 111", 1, 2286.0, 216618.0);
    insertProperty("Property 112", 2, 1209.0, 245496.0);
    insertProperty("Property 113", 5, 1051.0, 231680.0);
    insertProperty("Property 114", 4, 3802.0, 230877.0);
    insertProperty("Property 115", 1, 3700.0, 180427.0);
    insertProperty("Property 116", 1, 3314.0, 246479.0);
    insertProperty("Property 117", 4, 4480.0, 211211.0);
    insertProperty("Property 118", 3, 1575.0, 209865.0);
    insertProperty("Property 119", 1, 1594.0, 201893.0);
    insertProperty("Property 120", 2, 4190.0, 184703.0);
    insertProperty("Property 121", 2, 2160.0, 199186.0);
    insertProperty("Property 122", 1, 4977.0, 185416.0);
    insertProperty("Property 123", 1, 1536.0, 243465.0);
    insertProperty("Property 124", 3, 3425.0, 187143.0);
    insertProperty("Property 125", 5, 4964.0, 184167.0);
    insertProperty("Property 126", 5, 3776.0, 249835.0);
    insertProperty("Property 127", 1, 2277.0, 214596.0);
    insertProperty("Property 128", 3, 1806.0, 246842.0);
    insertProperty("Property 129", 3, 3038.0, 181291.0);
    insertProperty("Property 130", 1, 1814.0, 195957.0);
    insertProperty("Property 131", 4, 2563.0, 249965.0);
    insertProperty("Property 132", 3, 2988.0, 235523.0);
    insertProperty("Property 133", 5, 2568.0, 247577.0);
    insertProperty("Property 134", 4, 2812.0, 199070.0);
    insertProperty("Property 135", 4, 2657.0, 228041.0);
    insertProperty("Property 136", 1, 1014.0, 195099.0);
    insertProperty("Property 137", 1, 1573.0, 210554.0);
    insertProperty("Property 138", 5, 3752.0, 183783.0);
    insertProperty("Property 139", 3, 4091.0, 210859.0);
    insertProperty("Property 140", 1, 1949.0, 187242.0);
    insertProperty("Property 141", 3, 2470.0, 238694.0);
    insertProperty("Property 142", 3, 3524.0, 201079.0);
    insertProperty("Property 143", 3, 1894.0, 182682.0);
    insertProperty("Property 144", 1, 3721.0, 180731.0);
    insertProperty("Property 145", 1, 1373.0, 202324.0);
    insertProperty("Property 146", 2, 4209.0, 245629.0);
    insertProperty("Property 147", 4, 1943.0, 211522.0);
    insertProperty("Property 148", 5, 2460.0, 185042.0);
    insertProperty("Property 149", 2, 4329.0, 214983.0);
    insertProperty("Property 150", 4, 1752.0, 238215.0);

    // Predict the price of a property
    int bedroomsToPredict = 5;
    double areaToPredict = 1800.0;
    scanf("%lf", &areaToPredict);
    double predictedPrice = predictPrice(bedroomsToPredict, areaToPredict);

    if (predictedPrice != -1)
    {
        printf("Predicted price for a %d-bedroom property with %.1f sq. ft. area: $%.2f\n", bedroomsToPredict, areaToPredict, predictedPrice);
    }

    return 0;
}