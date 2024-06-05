// StringCalculator.js
function HelpAlf() {}

HelpAlf.prototype.findSpaceship = function (map) {
    let mapArray = map.split("\n");
    for (let i = mapArray.length - 1; i >= 0; i--) {
        if (mapArray[i].includes("X")) {
            return `${mapArray[i].indexOf("X")},${mapArray.length - 1 - i}`;
        }
    }
    return "Spaceship lost forever.";
};
