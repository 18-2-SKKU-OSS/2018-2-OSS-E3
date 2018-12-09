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
    }
}
