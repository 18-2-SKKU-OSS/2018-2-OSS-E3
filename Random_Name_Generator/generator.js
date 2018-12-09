var trainedData = require("./trained-data.js");

trainedData.firstNames = uncompressEmptyPart(trainedData.firstNames);

/**
 * 랜덤한 한국 이름을 생성한다.
 * 
 * @param {boolean} isMale 
 */
function generate(trainedDataMatrix) {
    let ensure = (n) => n == undefined ? 0 : n; 

        // 요소들의 가중치에 비례한 확률로 랜덤 뽑기
    let pick = (count, item) => {
        let sum = 0;
        let selected = 0;
        for (let i = 0; i < count; i++) {
                sum += item(i);
        }
        let pivot = Math.random() * sum;
        for (let i = 0; i < count; i++) {
            if ((pivot -= item(i)) <= 0) {
                selected = i;
                break;
            }
        }
        return selected;
    }
    let pickSyllable = (set) => {
        let choseong = pick(19, (n) => ensure(trainedDataMatrix[set][0][n]));
        let jungseong = pick(21, (n) => ensure(trainedDataMatrix[set][1][choseong * 21 + n]));
        let jongseong = pick(28, (n) => ensure(trainedDataMatrix[set][2][jungseong * 28 + n]) * ensure(trainedDataMatrix[set][3][choseong * 28 + n]));

        return constructFromJamoIndex([choseong, jungseong, jongseong]);
    }
    let pickLastName = () => {
        let lastNameIndex = pick(trainedData.lastNames.length, (n) => trainedData.lastNameFrequency[n]);

        return String.fromCharCode(trainedData.lastNames[lastNameIndex] + 0xAC00);
    }
    return pickLastName() + pickSyllable(0) + pickSyllable(1);
}
function generateByDefault(isMale = true) {
    return generate(trainedData.firstNames[isMale ? 0 : 1]);
}
/**
 * 이름 리스트를 토대로 통계적 학습 데이터를 생성한다.
 * 
 * @param {array} nameList 
 */
function train(nameList, compress = false) {
    let trainedNameData = [[[], [], [], []], [[], [], [], []]];
    let increase = (array, index) => {
        array[index] = (array[index] == undefined ? 1 : array[index] + 1);
    };
}
