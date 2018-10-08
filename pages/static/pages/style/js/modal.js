// Get the modal
var modal = document.getElementById('myModal');

// Get the button that opens the modal
var btn = document.getElementsByClassName("myBtn");

// Get the <span> element that closes the modal
var span = document.getElementsByClassName("close");

// When the user clicks on the button, open the modal
//btn.onclick = function() {
//    modal.style.display = "block";
//}

for (var i = 0; i < btn.length; i++) {
    btn[i].addEventListener("click", function() { 
        // modal.style.display = "block";
        this.parentNode.parentNode.nextElementSibling.style.display = 'block';
    })
}

// When the user clicks on <span> (x), close the modal
span.onclick = function() {
    modal.style.display = "none";
}

for (var i = 0; i < span.length; i++) {
    span[i].addEventListener("click", function() { 
        // modal.style.display = "block";
        this.parentNode.parentNode.style.display = 'none';
    })
}

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
    if (event.target == modal) {
        modal.style.display = "none";
    }
}