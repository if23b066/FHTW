function startGame() {
    displayName();
    displayTimer();
    createCards();
}

function displayName() {
    var playerName = prompt("Gib deinen Namen ein:");
    document.getElementById("playername").innerHTML = playerName;
}

var timer;

function displayTimer() {
    var time = 0;
    timer = setInterval(function(){
        document.getElementById("timer").innerHTML = time++;}, 1000);
}

function stopTimer() {
    clearInterval(timer);
}

var attempts = 1;

function countAttempts() {
    document.getElementById("versuche").innerHTML = attempts++;
}

function shuffleCards() {
    var currentIndex = bilder.length, temporaryValue, randomIndex;

    while (currentIndex !== 0) {
        randomIndex = Math.floor(Math.random() * currentIndex);
        currentIndex--;

        temporaryValue = bilder[currentIndex];
        bilder[currentIndex] = bilder[randomIndex];
        bilder[randomIndex] = temporaryValue;
    }

    var spielbereich = document.getElementById("spielbereich");
    spielbereich.innerHTML = "";

    for (var i = 0; i < bilder.length; i++) {
        spielbereich.appendChild(bilder[i]);

        if ((i + 1) % 4 === 0) {
            var clearDiv = document.createElement("div");
            clearDiv.style.clear = "both";
            spielbereich.appendChild(clearDiv);
        }
    }
}

var bilder = [];

function createCards() {
    var spielbereich = document.getElementById("spielbereich");
    for (var i = 0; i < 16; i++) {
        var card = document.createElement("div");
        card.setAttribute("onclick", "flipCard(this)");
        card.setAttribute("id", i+1);
        card.setAttribute("class", "karte");
        bilder.push(card);

        card.style.backgroundImage = "url(pics/memoryBg.png)";
        spielbereich.appendChild(card);
    }

    shuffleCards();

}

var flippedCards = [];
var foundPairs = 0;
var totalPairs = 8;

function flipCard(card) {
    if (!card.getAttribute("data-flipped") && card.style.backgroundImage !== "url(pics/memoryBgI.png)") {
        if (flippedCards.length < 2) {
            var imagePath = "pics/card" + (card.id) + ".png";
            card.style.backgroundImage = "url(" + imagePath + ")";
            card.setAttribute("data-flipped", true);
            card.setAttribute("data-image", imagePath);
            flippedCards.push(card);

            console.log("Karte umgedreht: " + card.id);
            console.log("Anzahl umgedrehter Karten: " + flippedCards.length);

            if (flippedCards.length === 2) {
                countAttempts();
                if (parseInt(flippedCards[0].id) + parseInt(flippedCards[1].id) === 17) {
                    console.log("Summe der IDs: 17");
                    setTimeout(function() {
                        flippedCards.forEach(function(flippedCard) {
                            flippedCard.style.backgroundImage = "url(pics/memoryBgI.png)";
                            flippedCard.removeAttribute("onclick");
                            flippedCard.removeAttribute("data-flipped");
                        });
                        flippedCards = [];
                        foundPairs++;
                        if (foundPairs === totalPairs) {
                            endGame();
                        }
                    }, 1000); 
                } else {
                    console.log("Summe der IDs: Nicht 17");
                    setTimeout(function() {
                        flippedCards.forEach(function(flippedCard) {
                            flippedCard.style.backgroundImage = "url(pics/memoryBg.png)";
                            flippedCard.removeAttribute("data-flipped");
                        });
                        flippedCards = [];
                    }, 1000);
                }
            }
        }
    }
}

function endGame() {
    stopTimer();
    alert("Herzlichen Glückwunsch! Du hast das Spiel in " + (parseInt(document.getElementById("timer").innerHTML)) + " Sekunden und " + (attempts - 1) + " Versuchen beendet!");
    location.reload();
}