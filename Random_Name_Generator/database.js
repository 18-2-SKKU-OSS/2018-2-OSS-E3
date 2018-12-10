var lastNames = [576, 7028, 4117, 8540, 7189, 21, 7280, 6948, 7077, 7044, 10588,
    6692, 5404, 5856, 396, 10857, 6472, 5537, 7172, 10829, 6944, 224, 3896,
    6545, 5520, 4144, 4145, 10696, 1192, 5868, 1400, 10584, 253, 5425, 8232,
    7420, 6832, 364, 4092, 3416, 1176, 7620, 7616, 6596, 8260, 6864, 8348,
    4137, 245, 10756, 10600, 4288, 6652, 6636, 8596, 1988, 5516, 5405, 5408,
    5412, 3528, 568, 6640, 6916, 10332, 3717, 560, 4120, 2940, 6741, 520,
    6693, 6945, 7032, 3577, 7196, 3752, 1192, 9409, 365, 6580, 6976, 10168
];
var lastNameFrequency = [1068, 730, 419, 233, 239, 126, 145, 102, 101, 101, 77,
    76, 75, 98, 70, 69, 68, 68, 74, 55, 94, 47, 46, 52, 45, 40, 38, 32, 27,
    27, 31, 23, 20, 19, 19, 23, 19, 19, 17, 16, 16, 17, 15, 14, 13, 12, 12,
    12, 9, 8, 8, 13, 6, 8, 6, 5, 5, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1
];
firstNames[0] = [
    [
        [905, -1, 45, 839, -1, 17, 665, 309, -1, 2049, -1, 1597, 2653, -1,
            405, -1, 334, 19, 1382
        ],
        [77, -3, 150, -1, 237, 1, 5, 94, -2, 9, 22, 12, -1, 1, 116, 31, -1,
            150, -21, 40, 1, -6, 2, -4, 1, -4, 1, -2, 27, 124, -2, 17, -3,
            650, -4, 20, -4, 1, -23, 4, 7, -4, 2, -5, 1, -4, 2, -2, 1, 7, -
            5, 84, -1, 5, -4, 44, -6, 525, 4, 3, -2, 83, -1, 159, -1, 55, -
            4, 4, -6, 1, -21, 401, 5, -2, 786, 111, -2, 13, -4, 141, -4,
            500, -1, 92, -21, 3, -1, 8, -1, 7, 1, 411, 60, 10, 21, -2, 188,
            223, 163, -1, 1, 232, 72, 36, 161, 43, 581, -2, 388, 40, -2,
            252, -4, 717, -6, 632, -21, 307, 21, -2, 47, -8, 16, -6, 14, -
            22, 333, -6, 1, -18, 7, -13, 12, 163, 38, 2, -1, 10, -1, 695,
            16, 202, 32, -1, 7, 57, 24, -2, 17, 1, 3, 113, 2
        ],
        [89, 27, -2, 320, -3, 2, 1, -6, 35, 1, -3, 601, -6, 1098, 14, -14,
            1, -12, 1, -19, 9, -34, 37, 130, -2, 260, -3, 37, -7, 83, -4,
            941, -6, 152, -27, 5, 64, -2, 504, -3, 3, -7, 1, 1, -3, 1017, -
            6, 77, -27, 302, 1, -2, 14, -3, 2, -12, 876, -6, 7, -3, 73, -16,
            67, -34, 7, -27, 88, -16, 1, -3, 166, -6, 522, 18, -2, 607, -3,
            1, -12, 64, -10, 175, -51, 19, -27, 187, 1, -2, 161, -3, 2, -20,
            1, -2, 97, -3, 2, -12, 508, -6, 149, -27, 556, 18, -2, 975, -3,
            34, -7, 6, 1
        ],
         [285, 11, -2, 225, -3, 13, -7, 1, 1, -3, 369, -34, 6, 6, -14, 32, -
            4, 1, -6, 278, 18, -2, 3, -11, 1, -4, 539, -34, 9, 3, -2, 1, -
            16, 4, -6, 24, -3, 558, -4, 1, -11, 82, -6, 41, 1, -2, 13, -3,
            1, -7, 83, -4, 170, -34, 345, 113, -2, 150, -3, 4, -7, 5, -4,
            1432, -34, 415, 28, -2, 574, -3, 17, -7, 2, 1, -3, 560, -6,
            1106, -3, 855, -12, 1, -3, 691, -34, 36, -3, 193, -3, 36, -12,
            140, -34, 321, 13, -34, 12, -12, 7, -6, 429, 82, -2, 614, -11,
            2, 1, -3, 254
        ]
    ],
    [
        [870, -1, 35, 81, -1, 120, 585, 309, -1, 1555, -1, 2495, 1466, -1,
            315, 1, 121, 47, 3056
        ],
        [7, -3, 45, -1, 69, -1, 19, 45, -2, 12, 64, 32, -2, 349, 80, -1,
            148, -21, 14, -5, 8, -1, 4, -4, 3, -4, 6, -2, 4, 5, -2, 17, -3,
            52, -4, 3, -28, 16, 13, 1, -3, 20, -1, 20, -3, 7, 2, -3, 9, -2,
            32, 6, -5, 25, -1, 47, -4, 40, -6, 467, -1, 19, -2, 110, 1, 5, -
            1, 27, -4, 3, -6, 144, -21, 81, 4, -2, 918, 16, -2, 23, -4, 363, -
            4, 54, -1, 96, -21, 19, -1, 6, -1, 29, -1, 573, -1, 38, 59, -2,
            113, 938, 355, -1, 1, 167, 32, 10, 155, 1, 239, -2, 27, 35, -2,
            62, -4, 754, -6, 348, -21, 193, 6, -2, 112, -3, 2, -4, 2, -7, 1, -
            20, 13, 108, -25, 6, -1, 1, -3, 22, -7, 18, 163, 15, -2, 80, -1,
            1180, -1, 594, 330, -1, 11, 11, 471, -2, 19, 1, 11, 170
        ],
        [77, 54, -2, 263, -11, 24, -4, 100, -6, 354, 43, -14, 2, -4, 10, -
            27, 7, -34, 40, 414, -2, 223, -3, 109, -7, 111, 110, -3, 331, -
            6, 45, -7, 1, -8, 6, -11, 316, -2, 783, -3, 71, -7, 13, 97, -3,
            606, -34, 654, 37, -2, 34, -3, 13, -12, 151, -6, 35, 1, -2, 374, -
            16, 24, -34, 11, -27, 46, -20, 119, -6, 1139, 235, -2, 1124, -3,
            10, -12, 135, -10, 387, -51, 20, -27, 281, -3, 237, -3, 8, -20,
            1, -2, 113, -3, 7, -7, 7, 1, -3, 54, -6, 180, -27, 142, 108, -2,
            1024, -3, 105, -7, 20, 4, -5, 5
        ],
        [454, 23, -2, 278, -3, 30, -7, 13, -4, 72, -34, 6, 1, -2, 3, -3, 5, -
            7, 14, -4, 6, -6, 26, 17, -2, 6, -11, 4, -4, 28, -34, 25, 24, -
            2, 10, -3, 20, -7, 25, 4, -3, 12, -6, 52, 19, -2, 490, -16, 24, -
            6, 26, 18, -2, 139, -3, 4, -7, 110, -4, 7, -1, 5, -32, 406, 487, -
            2, 99, -3, 16, -7, 3, 117, -3, 427, -34, 648, 229, -2, 836, -3,
            129, -7, 2, 82, -3, 569, -6, 405, 3, -2, 944, -16, 114, -34, 6, -
            3, 172, -3, 102, -12, 35, -6, 1, -27, 74, 47, -26, 23, -7, 18, -
            12, 6, -6, 872, 341, -2, 1585, -11, 6, 15, -3, 237
        ]
    ]
];
