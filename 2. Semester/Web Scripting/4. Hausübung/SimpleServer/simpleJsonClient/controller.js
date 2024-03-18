//Starting point for JQuery init
$(document).ready(function () {
    $("#searchResult").hide();
    $("#btn_Search").click(function (e) {
        var searchTerm = $("#seachfield").val();
        if (searchTerm.trim() !== "") { // Check if search term is not empty
            loaddataByName(searchTerm);
        } else {
            $("#searchResult").empty().append("<p>Please enter a valid search term.</p>").show(1000).delay(1000).hide(1000);
        }
    });
    $("#btn_SearchPosition").click(function (e) {
        var position = $("#positionSelect").val();
        if (position.trim() !== "") { // Check if position is selected
            loaddataByPosition(position);
        } else {
            $("#searchResult").empty().append("<p>Please select a position.</p>").show(1000).delay(1000).hide(1000);
        }
    });
});

function loaddataByName(searchterm) {
    $.ajax({
        type: "GET",
        url: "../serviceHandler.php",
        cache: false,
        data: {method: "queryPersonByName", param: searchterm},
        dataType: "json",
        success: function (response) {
            displayResults(response);
        },
        error: function(xhr, status, error) {
            console.error(xhr.responseText);
        }
    });
}

function loaddataByPosition(position) {
    $.ajax({
        type: "GET",
        url: "../serviceHandler.php",
        cache: false,
        data: {method: "queryPersonByPosition", param: position},
        dataType: "json",
        success: function (response) {
            displayResults(response);
        },
        error: function(xhr, status, error) {
            console.error(xhr.responseText);
        }
    });
}

function displayResults(response) {
    $("#noOfentries").val(response.length);
    $("#searchResult").empty();
    // Check if response is an array
    if (Array.isArray(response) && response.length > 0) {
        response.forEach(function(person) {
            $("#searchResult").append("<p>Name: " + person[0].firstname + ", Email: " + person[0].email + ", Position: " + person[0].position + "</p>");
        });
    } else {
        $("#searchResult").append("<p>No results found.</p>");
    }
    $("#searchResult").show(1000).delay(1000).hide(1000);
}
