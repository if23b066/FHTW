$(document).ready(function () {

    var idCounter = 1;

    function addItem() {
        var e = $("#item").val();
        if (!e) {
            console.log("Input is empty, an item is required");
            return;
        }
        $("ol").append("<li id='item" + idCounter + "'>" + e + "</li>");
        console.log("element added with id: item" + idCounter);
        idCounter++;
        $("#item").val('');
    }
    $(document).ready(
        $("#add").on("click", addItem)
    );

    function deleteItem() {
        var index = $("#index").val();
        if (!index) {
            console.log("No index provided");
            return;
        }
        if (index < 0 || index > idCounter - 1) {
            console.log("Index out of range");
            return;
        }
        $("#item" + index).remove();
        console.log("element deleted with id: item" + index);
    }
    $(document).ready(
        $("#delete").on("click", deleteItem)
    );

    function swapItems() {
        var swap1 = $("#swap1").val();
        var swap2 = $("#swap2").val();
    
        if (swap1 < 0 || swap1 > idCounter - 1 || swap2 < 0 || swap2 > idCounter - 1) {
            console.log("Swap indices out of range");
            return;
        }
        if(swap1 == swap2) {
            console.log("Swap indices are the same");
            return;
        }
    
        var item1 = $("#item" + swap1);
        var item2 = $("#item" + swap2);
    
        var temp = item1.text();
        item1.text(item2.text());
        item2.text(temp);
    
        console.log("Swapped items with ids: item" + swap1 + " and item" + swap2);
    }
    $(document).ready(
        $("#swap").on("click", swapItems)
    );

    function hideItems() {
        $("ol").slideUp();
        console.log("List hidden");
    }
    $(document).ready(
        $("#hide").on("click", hideItems)
    );

    function showItems() {
        $("ol").slideDown();
        console.log("List shown");
    }
    $(document).ready(
        $("#show").on("click", showItems)
    );
});