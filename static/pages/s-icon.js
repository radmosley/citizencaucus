var modal = document.querySelector(".modal");
var closeButton = document.querySelector(".close");
var trigger = document.getElementsByClassName(".senator-cell");

function toggleModal(event) {
    console.log(trigger[0])
}

function windowOnClick(event) {
    if (event.target === modal) {
        toggleModal();
    }
}

trigger.addEventListener("click", toggleModal);
closeButton.addEventListener("click", toggleModal);
window.addEventListener("click", windowOnClick);