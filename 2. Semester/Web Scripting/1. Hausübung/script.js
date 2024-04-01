function addiere() {
    var zahl1 = parseInt(document.getElementById("ersteZahl").value);
    var zahl2 = parseInt(document.getElementById("zweiteZahl").value);
    var ergebnis = zahl1 + zahl2;
    document.getElementById("ergebnis").value = ergebnis;
    addToList("+");
}

function subtrahiere() {
    var zahl1 = parseInt(document.getElementById("ersteZahl").value);
    var zahl2 = parseInt(document.getElementById("zweiteZahl").value);
    var ergebnis = zahl1 - zahl2;
    document.getElementById("ergebnis").value = ergebnis;
    addToList("-");
}

function multipliziere() {
    var zahl1 = parseInt(document.getElementById("ersteZahl").value);
    var zahl2 = parseInt(document.getElementById("zweiteZahl").value);
    var ergebnis = zahl1 * zahl2;
    document.getElementById("ergebnis").value = ergebnis;
    addToList("·");
}

function dividiere() {  
    var zahl1 = parseInt(document.getElementById("ersteZahl").value);
    var zahl2 = parseInt(document.getElementById("zweiteZahl").value);
    var ergebnis = zahl1 / zahl2;
    document.getElementById("ergebnis").value = ergebnis;
    addToList("÷");
}

function addToList(operator) {
    var ul = document.getElementById("list");
    var li = document.createElement("li");
    li.appendChild(document.createTextNode(document.getElementById("ersteZahl").value + " " + operator + " " + document.getElementById("zweiteZahl").value + " = " + document.getElementById("ergebnis").value));
    ul.appendChild(li);
}