var input = document.getElementById("input");
var button = document.querySelector("button");
var output = document.getElementById("output");
var select = document.getElementById("select");
function convertInchesToCentimeters(inches) {
    return inches * 2.54;
}
function convertCentimetersToInches(centimeters) {
    return centimeters / 2.54;
}
function convertYardsToMeters(yards) {
    return yards * 0.9144;
}
function convertMetersToYards(meters) {
    return meters / 0.9144;
}
if (button) {
    button.addEventListener("click", function () {
        console.log("Button clicked");
        if (select.value === "1") {
            output.value = convertInchesToCentimeters(+input.value).toString();
        }
        if (select.value === "2") {
            output.value = convertCentimetersToInches(+input.value).toString();
        }
        if (select.value === "3") {
            output.value = convertYardsToMeters(+input.value).toString();
        }
        if (select.value === "4") {
            output.value = convertMetersToYards(+input.value).toString();
        }
    });
}
