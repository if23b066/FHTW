var input = document.getElementById('input');
var button = document.querySelector('button');
var output = document.getElementById('output');
var select = document.getElementById('select');
function convertInchesToCentimeters(inches) {
    return inches * 2.54;
}
function convertCentimetersToInches(centimeters) {
    return centimeters / 2.54;
}
function convertYardsToMeters(yards) {
    return yards * 1.094;
}
function convertMetersToYards(meters) {
    return meters / 1.094;
}
if (button) {
    button.addEventListener('click', function () {
        console.log('Button clicked');
        if (select.value === "1") {
            output.innerHTML = convertInchesToCentimeters(+input.value).toString();
        }
        if (select.value === "2") {
            output.innerHTML = convertCentimetersToInches(+input.value).toString();
        }
        if (select.value === "3") {
            output.innerHTML = convertYardsToMeters(+input.value).toString();
        }
        if (select.value === "4") {
            output.innerHTML = convertMetersToYards(+input.value).toString();
        }
    });
}
