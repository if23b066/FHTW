// StringCalculator.js
function ElectronsGame() { }
ElectronsGame.prototype.dice = function (array) {
	let sum = 0;
	for (let i = 0; i < array.length; i++) {
		if (array[i] === 3) {
			sum += 2;
		} else if (array[i] === 5) {
			sum += 4;
		}
	}
	return sum;
};