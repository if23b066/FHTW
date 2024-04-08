const input = document.getElementById('input')! as HTMLInputElement;
const button = document.querySelector('button');
const output = document.getElementById('output')! as HTMLInputElement;
const select = document.getElementById('select')! as HTMLSelectElement;

function convertInchesToCentimeters(inches: number): number {
    return inches * 2.54;
}

function convertCentimetersToInches(centimeters: number): number {
    return centimeters / 2.54;
}

function convertYardsToMeters(yards: number): number {
    return yards * 1.094;
}

function convertMetersToYards(meters: number): number {
    return meters / 1.094;
}

if (button) {
    button.addEventListener('click', () => {
        console.log('Button clicked');
        if(select.value === "1") {
            output.innerHTML = convertInchesToCentimeters(+input.value).toString();
        }
        if(select.value === "2") {
            output.innerHTML = convertCentimetersToInches(+input.value).toString();
        }
        if(select.value === "3") {
            output.innerHTML = convertYardsToMeters(+input.value).toString();
        }
        if(select.value === "4") {
            output.innerHTML = convertMetersToYards(+input.value).toString();
        }
    });
}