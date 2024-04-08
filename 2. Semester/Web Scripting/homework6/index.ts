const input = document.getElementById("input")! as HTMLInputElement;
const button = document.querySelector("button");
const output = document.getElementById("output")! as HTMLInputElement;
const select = document.getElementById("select")! as HTMLSelectElement;

function convertInchesToCentimeters(inches: number): number {
    return inches * 2.54;
}

function convertCentimetersToInches(centimeters: number): number {
    return centimeters / 2.54;
}

function convertYardsToMeters(yards: number): number {
    return yards * 0.9144;
}

function convertMetersToYards(meters: number): number {
    return meters / 0.9144;
}

if (button) {
    button.addEventListener("click", () => {
        console.log("Button clicked");
        if(select.value === "1") {
            output.value = convertInchesToCentimeters(+input.value).toString();
        }
        if(select.value === "2") {
            output.value = convertCentimetersToInches(+input.value).toString();
        }
        if(select.value === "3") {
            output.value = convertYardsToMeters(+input.value).toString();
        }
        if(select.value === "4") {
            output.value = convertMetersToYards(+input.value).toString();
        }
    });
}