#ifndef CONVERSIONTABLE_H
#define CONVERSIONTABLE_H

class conversiontable
{
public:
    static std::map<int, double> values;
};

std::map<int, double> conversiontable::values = {
    {0, 212.00},
    {1, 215.34},
    {2, 218.51},
    {3, 221.53},
    {4, 224.40},
    {5, 227.15},
    {6, 229.79},
    {7, 232.33},
    {8, 234.77},
    {9, 237.13},
    {10, 239.40},
    {11, 241.60},
    {12, 243.74},
    {13, 245.80},
    {14, 247.81},
    {15, 249.76},
    {16, 251.66},
    {17, 253.51},
    {18, 255.31},
    {19, 257.06},
    {20, 258.78},
    {21, 260.45},
    {22, 262.09},
    {23, 263.69},
    {24, 265.25},
    {25, 266.79},
    {26, 268.29},
    {27, 269.76},
    {28, 271.21},
    {29, 272.63},
    {30, 274.02},
    {31, 275.38},
    {32, 276.73},
    {33, 278.05},
    {34, 279.34},
    {35, 280.62},
    {36, 281.87},
    {37, 283.11},
    {38, 284.33},
    {39, 285.52},
    {40, 286.71},
    {41, 287.87},
    {42, 289.02},
    {43, 290.15},
    {44, 291.26},
    {45, 292.36},
    {46, 293.45},
    {47, 294.52},
    {48, 295.58},
    {49, 296.62},
    {50, 297.65},
    {51, 298.67},
    {52, 299.68},
    {53, 300.67},
    {54, 301.65},
    {55, 302.62},
    {56, 303.58},
    {57, 304.53},
    {58, 305.47},
    {59, 306.40},
    {60, 307.32},
    {61, 308.23},
    {62, 309.12},
    {63, 310.01},
    {64, 310.89},
    {65, 311.76},
    {66, 312.63},
    {67, 313.48},
    {68, 314.33},
    {69, 315.16},
    {70, 315.99},
    {71, 316.83},
    {72, 317.63},
    {73, 318.44},
    {74, 319.24},
    {75, 320.03},
    {76, 320.81},
    {77, 321.59},
    {78, 322.37},
    {79, 323.17},
    {80, 323.89},
    {81, 324.64},
    {82, 325.39},
    {83, 326.13},
    {84, 326.86},
    {85, 327.59},
    {86, 328.31},
    {87, 329.03},
    {88, 329.74},
    {89, 330.45},
    {90, 331.15},
    {91, 331.84},
    {92, 332.53},
    {93, 333.22},
    {94, 333.90},
    {95, 334.57},
    {96, 335.24},
    {97, 335.91},
    {98, 336.57},
    {99, 337.22},
    {100, 337.87},
    {101, 338.52},
    {102, 339.16},
    {103, 339.80},
    {104, 340.43},
    {105, 341.06},
    {106, 341.69},
    {107, 342.31},
    {108, 342.93},
    {109, 343.54},
    {110, 344.15},
    {111, 344.76},
    {112, 345.36},
    {113, 345.95},
    {114, 346.55},
    {115, 347.14},
    {116, 347.73},
    {117, 348.31},
    {118, 348.89},
    {119, 349.47},
    {120, 350.04},
    {121, 350.61},
    {122, 351.18},
    {123, 351.74},
    {124, 352.30},
    {125, 352.86},
    {126, 353.41},
    {127, 353.96},
    {128, 354.51},
    {129, 155.05},
    {130, 355.60},
    {131, 356.13},
    {132, 356.67},
    {133, 357.20},
    {134, 357.73},
    {135, 358.26},
    {136, 358.79},
    {137, 359.31},
    {138, 359.83},
    {139, 360.34},
    {140, 360.86},
    {141, 361.37},
    {142, 361.88},
    {143, 362.38},
    {144, 362.89},
    {145, 363.39},
    {146, 363.89},
    {147, 364.38},
    {148, 364.88},
    {149, 365.37},
    {150, 365.86},
    {152, 366.83},
    {154, 367.79},
    {156, 368.74},
    {158, 369.69},
    {160, 370.62},
    {162, 371.55},
    {164, 372.47},
    {166, 373.38},
    {168, 374.29},
    {170, 375.18},
    {172, 376.07},
    {174, 376.95},
    {176, 377.82},
    {178, 378.69},
    {180, 379.55},
    {182, 380.40},
    {184, 381.25},
    {186, 382.09},
    {188, 382.92},
    {190, 383.75},
    {192, 384.57},
    {194, 385.38},
    {196, 386.19},
    {198, 386.99},
    {200, 387.79},
    {205, 389.75},
    {210, 391.68},
    {215, 393.58},
    {220, 395.44},
    {225, 397.28},
    {230, 399.08},
    {235, 400.86},
    {240, 402.61},
    {245, 404.33},
    {250, 406.03},
    {255, 407.70},
    {260, 409.35},
    {265, 410.97},
    {270, 412.58},
    {275, 414.16},
    {280, 415.72},
    {285, 417.26},
    {290, 418.78},
    {295, 420.28},
    {300, 421.76},
    {310, 424.67},
    {320, 427.51},
    {330, 430.29},
    {340, 433.00},
    {350, 435.66},
    {360, 438.26},
    {370, 440.80},
    {380, 443.30},
    {390, 445.75},
    {400, 448.15},
    {410, 450.15},
    {420, 452.82},
    {430, 455.09},
    {440, 457.33},
    {450, 459.52},
    {460, 461.68},
    {470, 463.81},
    {480, 465.90},
    {490, 467.97},
    {500, 470.00},
    {510, 472.00},
    {520, 473.97},
    {530, 475.91},
    {540, 477.82},
    {550, 479.71},
    {560, 481.57},
    {570, 483.41},
    {580, 485.23},
    {590, 487.02},
    {600, 488.79}
};

#endif // CONVERSIONTABLE_H